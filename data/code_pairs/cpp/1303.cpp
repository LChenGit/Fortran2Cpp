// XMLDefinitions.h
#pragma once

enum XMLVersion {
    XML1_0,
    XML1_1
};

struct XmlDocumentState {
    XMLVersion xml_version = XML1_0;
};

// QNameCheck.h
#pragma once
#include "XMLDefinitions.h"
#include <string>
#include <cctype>

bool checkQName(const std::string& name, const XmlDocumentState& xds) {
    if (name.empty() || std::isdigit(name[0]) || name[0] == ':' || name[0] == '#') {
        return false;
    }
    if (name.find(':') != std::string::npos && xds.xml_version == XML1_0) {
        return false;
    }
    return true;
}

// test_namecheck.cpp
#include "XMLDefinitions.h"
#include "QNameCheck.h"
#include <iostream>

int main() {
    XmlDocumentState xds;

    std::cout << std::boolalpha;
    std::cout << checkQName("abcd", xds) << std::endl;
    std::cout << checkQName("1abcd", xds) << std::endl;
    std::cout << checkQName(":abcd", xds) << std::endl;
    std::cout << checkQName("#abcd", xds) << std::endl;
    std::cout << checkQName("e:abcd", xds) << std::endl;

    xds.xml_version = XML1_1;

    std::cout << checkQName("abcd", xds) << std::endl;
    std::cout << checkQName("1abcd", xds) << std::endl;
    std::cout << checkQName(":abcd", xds) << std::endl;
    std::cout << checkQName("#abcd", xds) << std::endl;
    std::cout << checkQName("e:abcd", xds) << std::endl;

    return 0;
}