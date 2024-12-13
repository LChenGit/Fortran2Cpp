// MyClass.h
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    int* data = nullptr;
    int currentSize = 0;

    MyClass() = default;

    ~MyClass() {
        delete[] data;
    }

    void resetArray() {
        if (data != nullptr) {
            delete[] data;
            data = nullptr;
        }
        currentSize = 0;
    }
};

#endif // MYCLASS_H