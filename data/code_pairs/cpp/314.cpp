// large_recl.cpp
#include <fstream>
#include <vector>

// Function to simulate handling a large record length
bool handleLargeRecord(const char* filename, std::streamsize recordLength) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::out);
    if (!outFile) return false;

    std::vector<char> buffer(recordLength, 'A'); // Fill buffer with 'A's for simplicity
    outFile.write(buffer.data(), recordLength);
    if (!outFile) return false;
    outFile.close();

    std::ifstream inFile(filename, std::ios::binary | std::ios::in);
    if (!inFile) return false;

    std::vector<char> readBuffer(recordLength);
    inFile.read(readBuffer.data(), recordLength);
    if (!inFile) return false;
    inFile.close();

    return true;
}

// test_large_recl.cpp (Unit test for the above C++ code)
#include <gtest/gtest.h>

TEST(LargeReclTest, HandleLargeRecord) {
    const char* filename = "temp_test_file.bin";
    const std::streamsize recordLength = 12345678901LL;

    EXPECT_TRUE(handleLargeRecord(filename, recordLength));
    std::remove(filename); // Cleanup
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}