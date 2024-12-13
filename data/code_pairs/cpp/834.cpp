// File: TEST.hpp
#ifndef TEST_HPP
#define TEST_HPP

class TEST {
public:
    struct all_type {
        struct info_type {
            int value;
        } info;
    };

    class any_type {
    private:
        struct info_type {
            int value;
        } info;
    public:
        void setValue(int val) { info.value = val; }
        int getValue() const { return info.value; }
    };
};

#endif // TEST_HPP