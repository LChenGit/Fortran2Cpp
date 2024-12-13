#include <iostream>
#include <fstream>
#include <filesystem>

namespace modmain {
    std::string scrpath = "./test/";
    std::string filext = ".txt";
}

void delevec(const std::string& scrpath, const std::string& filext) {
    std::string filePath1 = scrpath + "EVECFV" + filext;
    if (std::filesystem::exists(filePath1)) {
        std::filesystem::remove(filePath1);
    }

    std::string filePath2 = scrpath + "EVECSV" + filext;
    if (std::filesystem::exists(filePath2)) {
        std::filesystem::remove(filePath2);
    }
}

void createTestFile(const std::string& path) {
    std::ofstream ofs(path);
    ofs.close();
}

void testFileDeletion(const std::string& scrpath, const std::string& filext) {
    // Setup - create files to be deleted
    createTestFile(scrpath + "EVECFV" + filext);
    createTestFile(scrpath + "EVECSV" + filext);
    
    // Test deletion
    delevec(scrpath, filext);
    
    // Assertions
    std::ifstream testFile1(scrpath + "EVECFV" + filext);
    assert(!testFile1.good() && "EVECFV file was not deleted.");
    testFile1.close();

    std::ifstream testFile2(scrpath + "EVECSV" + filext);
    assert(!testFile2.good() && "EVECSV file was not deleted.");
    testFile2.close();

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testFileDeletion(modmain::scrpath, modmain::filext);
    return 0;
}