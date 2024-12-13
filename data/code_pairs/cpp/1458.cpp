// check_vector_size.cpp
#include <iostream>
#include <vector>
#include <cstdlib> // For std::exit()
#include <sstream> // For std::stringstream

template<typename T>
void checkVectorSize(const std::vector<T>& vector, size_t nsize, const std::string& subname, const std::string& vecname) {
    if (vector.size() != nsize) {
        std::stringstream ss;
        ss << "FATAL ERROR: Size problem incompatibility!\n"
           << "  Inside Procedure: " << subname << "\n"
           << "  Vector Name:      " << vecname << "\n"
           << "  Expected size:    " << nsize << "\n"
           << "  Actual size:      " << vector.size();
        throw std::runtime_error(ss.str());
    }
}

// main.cpp (Assuming the Google Test framework is set up in your project)
#include <gtest/gtest.h>

TEST(CheckVectorSizeTest, HandlesCorrectSize) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::string subname = "TestProcedure";
    std::string vecname = "TestVector";
    size_t expectedSize = 5;
    EXPECT_NO_THROW(checkVectorSize(vec, expectedSize, subname, vecname));
}

TEST(CheckVectorSizeTest, HandlesIncorrectSize) {
    std::vector<int> vec = {1, 2, 3, 4};
    std::string subname = "TestProcedure";
    std::string vecname = "TestVector";
    size_t expectedSize = 5;
    EXPECT_THROW(checkVectorSize(vec, expectedSize, subname, vecname), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}