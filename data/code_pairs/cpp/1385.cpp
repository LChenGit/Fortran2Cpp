#include <iostream>
#include <fstream>
#include <string>

void createSimpleXMLWithAttribute(const std::string& filename, const std::string& attributeName, const std::string& attributeValue) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    file << "<root " << attributeName << "=\"" << attributeValue << "\">\n";
    // Add more XML content here as needed
    file << "</root>\n";

    file.close();
    std::cout << "File created with an attribute: " << filename << std::endl;
}

int main() {
    const std::string filename = "test.xml";
    const std::string attributeName = "att";
    const std::string attributeValue = "value";

    createSimpleXMLWithAttribute(filename, attributeName, attributeValue);

    return 0;
}