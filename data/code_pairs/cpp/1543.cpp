#ifndef TEST_MOD_HPP
#define TEST_MOD_HPP

class TestMod {
public:
    static float add(int i, int j, int k) {
        return static_cast<float>(i + j + k) + 1.0f;
    }

    static float add2(int i, int j, int k) {
        return static_cast<float>(i + j + k);
    }

    static void check_err(float a[2][2], float s) {
        float sum = 0.0f;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                sum += a[i][j];
            }
        }
        if (std::abs(sum - s) > 1e-5) {
            std::cerr << "Error detected" << std::endl;
            std::exit(1);
        }
    }
};

#endif // TEST_MOD_HPP