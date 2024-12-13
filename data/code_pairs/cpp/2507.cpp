#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <iostream>
#include <vector>
#include <functional>
#include <string>

class SimpleTestFramework {
public:
    using TestFunc = std::function<void()>;

    static void registerTest(const std::string& testName, TestFunc testFunc) {
        getTests().push_back({testName, testFunc});
    }

    static void runAllTests() {
        for (auto& test : getTests()) {
            std::cout << "Running test: " << test.first << std::endl;
            test.second();
        }
    }

private:
    static std::vector<std::pair<std::string, TestFunc>>& getTests() {
        static std::vector<std::pair<std::string, TestFunc>> tests;
        return tests;
    }
};

#endif // TEST_FRAMEWORK_H