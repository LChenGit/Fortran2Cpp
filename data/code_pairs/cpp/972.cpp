#include <gtest/gtest.h>
#include <vector>

class Type_Vector {
public:
    double x = 0.0, y = 0.0, z = 0.0;
};

class Type_Primitive {
public:
    bool flag = false;
    void free() { flag = false; }
    void init() { flag = true; }
};

class Type_Conservative {
public:
    bool flag = false;
    void free() { flag = false; }
    void init() { flag = true; }
};

class Type_Cell {
public:
    double V = 0.0;
    Type_Vector cent;
    double Dt = 0.0;
    Type_Primitive P;
    Type_Conservative U;
    std::vector<Type_Conservative> KS;

    void init(int rk_ord) {
        KS.resize(rk_ord);
    }

    void free() {
        P.free();
        U.free();
        KS.clear();
    }
};

TEST(TypeCellTest, InitializeAndFree) {
    Type_Cell cell;

    // Initialize cell with a vector of size 3
    cell.init(3);
    EXPECT_EQ(cell.KS.size(), 3) << "KS vector should be resized to 3.";

    // Test freeing functionality
    cell.free();
    EXPECT_TRUE(cell.KS.empty()) << "KS vector should be empty after free.";
    EXPECT_FALSE(cell.P.flag) << "Primitive type flag should be false after free.";
    EXPECT_FALSE(cell.U.flag) << "Conservative type flag should be false after free.";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}