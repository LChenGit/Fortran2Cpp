#include <iostream>

class IotkRead {
public:
    virtual void read(int file_handle, int& data) = 0;  // Pure virtual function
    virtual void read(int file_handle, float& data) = 0; // Pure virtual function
};

class IotkReadImpl : public IotkRead {
public:
    void read(int file_handle, int& data) override {
        data = 42;  // Dummy implementation
    }

    void read(int file_handle, float& data) override {
        data = 3.14f;  // Dummy implementation
    }
};