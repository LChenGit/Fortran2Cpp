// file_operations.cpp
#include <fstream>
#include <unordered_map>
#include <iostream>

std::unordered_map<int, std::fstream> fileMap;

void closeUnit(int unitnum) {
    auto it = fileMap.find(unitnum);
    if (it != fileMap.end()) {
        if (it->second.is_open()) {
            it->second.close();
            std::cout << "File with unit number " << unitnum << " closed successfully.\n";
        }
        fileMap.erase(it);
    }
}

// file_operations_test.cpp
#include <gtest/gtest.h>
#include "file_operations.cpp"

class FileCloseTest : public ::testing::Test {
protected:
    void SetUp() override {
        int testUnitNum = 1;
        fileMap[testUnitNum].open("testfile_cpp.txt", std::fstream::out);
        ASSERT_TRUE(fileMap[testUnitNum].is_open());
    }

    void TearDown() override {
        int testUnitNum = 1;
        if (fileMap.find(testUnitNum) != fileMap.end() && fileMap[testUnitNum].is_open()) {
            fileMap[testUnitNum].close();
        }
        fileMap.erase(testUnitNum);
        remove("testfile_cpp.txt");
    }
};

TEST_F(FileCloseTest, ClosesFileCorrectly) {
    int testUnitNum = 1;
    closeUnit(testUnitNum);
    ASSERT_EQ(fileMap.find(testUnitNum), fileMap.end());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}