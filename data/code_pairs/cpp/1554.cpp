#ifndef DIMENSIONSWRAPPER7D_H
#define DIMENSIONSWRAPPER7D_H

#include <vector>
#include <iostream>

template<typename T>
class DimensionsWrapper7D_t {
public:
    virtual ~DimensionsWrapper7D_t() {}

    virtual void Set(const T& value) = 0;
    virtual void Get(T& value) = 0;
    virtual T* GetPointer() = 0;
};

template<typename T>
class ConcreteDimensionsWrapper : public DimensionsWrapper7D_t<T> {
    T data_; // Assuming T supports operator=
public:
    void Set(const T& value) override {
        data_ = value;
        std::cout << "Set method called." << std::endl;
    }

    void Get(T& value) override {
        value = data_;
        std::cout << "Get method called." << std::endl;
    }

    T* GetPointer() override {
        return &data_;
    }
};

#endif // DIMENSIONSWRAPPER7D_H