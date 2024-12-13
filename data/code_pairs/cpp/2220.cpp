// wb_dma_transfer_test.cpp
#include <iostream>
#include <gtest/gtest.h>
#include <string>

// Mocked function to simulate UVM's set_type_override
void uvm_set_type_override(const std::string& original_type, const std::string& new_type) {
    std::cout << "Overriding " << original_type << " with " << new_type << std::endl;
}

// Test Case
TEST(WBDmaTransferTest, TypeOverride) {
    uvm_set_type_override("wb_dma_transfer_seq", "wb_dma_infact_single_transfer_seq");
    uvm_set_type_override("wb_dma_config_seq", "wb_dma_infact_fields_config_seq");

    // Mocked checks, assuming they pass
    EXPECT_TRUE(true); // Placeholder for actual tests
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}