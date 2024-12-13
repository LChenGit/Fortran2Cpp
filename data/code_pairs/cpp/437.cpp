#include <string>
#include <iostream>
#include "gtest/gtest.h"

class ilaenv_I {
public:
    virtual int ilaenv(int ISPEC, const std::string& NAME, int N1, int N2, int N4) = 0;
};

class ilaenv_Impl : public ilaenv_I {
public:
    int ilaenv(int ISPEC, const std::string& NAME, int N1, int N2, int N4) override {
        return ISPEC + N1 + N2 + N4; // Example implementation
    }
};