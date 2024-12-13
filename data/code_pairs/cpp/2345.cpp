#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <gtest/gtest.h>

// Function to calculate the product of elements in a 2D vector
int totalProduct(const std::vector<std::vector<int>>& a) {
    int total_product = 1;
    for (const auto& row : a) {
        total_product = std::accumulate(row.begin(), row.end(), total_product, std::multiplies<int>());
    }
    return total_product;
}

// Function to calculate product along the first dimension
std::vector<int> productAlongFirstDimension(const std::vector<std::vector<int>>& a) {
    std::vector<int> products;
    for (const auto& row : a) {
        products.push_back(std::accumulate(row.begin(), row.end(), 1, std::multiplies<int>()));
    }
    return products;
}

// Function to calculate product along the second dimension with optional mask
std::vector<int> productAlongSecondDimension(const std::vector<std::vector<int>>& a, const std::vector<std::vector<bool>>& mask) {
    std::vector<int> products(3, 1);
    for (size_t j = 0; j < a[0].size(); ++j) {
        for (size_t i = 0; i < a.size(); ++i) {
            if (mask.empty() || mask[i][j]) {
                products[j] *= a[i][j];
            }
        }
    }
    return products;
}

// Test fixture for our product tests
class ProductTest : public ::testing::Test {
protected:
    std::vector<std::vector<int>> a{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<bool>> mask{{false, true, true}, {false, true, true}, {true, true, true}};
};

// Test cases
TEST_F(ProductTest, TotalProduct) {
    EXPECT_EQ(totalProduct(a), 362880) << "Total product should be 362880";
}

TEST_F(ProductTest, ProductAlongFirstDimension) {
    auto products = productAlongFirstDimension(a);
    EXPECT_EQ(products, (std::vector<int>{6, 120, 504})) << "Products along the first dimension are incorrect";
}

TEST_F(ProductTest, ProductAlongSecondDimensionWithMask) {
    auto products = productAlongSecondDimension(a, mask);
    EXPECT_EQ(products, (std::vector<int>{28, 40, 162})) << "Products along the second dimension with mask are incorrect";
}

// Main function to run all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}