#include <cmath>

class Orders {
public:
    static bool lt_order(double a, double b) {
        return a < b;
    }

    static bool lt_order(int a, int b) {
        return a < b;
    }

    static bool lt_order(float a, float b) {
        return a < b;
    }

    static bool gtabs_order(double a, double b) {
        return std::abs(a) > std::abs(b);
    }

    static bool gtabs_order(int a, int b) {
        return std::abs(static_cast<float>(a)) > std::abs(static_cast<float>(b));
    }

    static bool gtabs_order(float a, float b) {
        return std::abs(a) > std::abs(b);
    }

    static bool gt_order(double a, double b) {
        return a > b;
    }

    static bool gt_order(int a, int b) {
        return a > b;
    }

    static bool gt_order(float a, float b) {
        return a > b;
    }
};