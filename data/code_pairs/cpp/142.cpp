#ifndef DYNAMIC_ARRAY_3D_HPP
#define DYNAMIC_ARRAY_3D_HPP

class DynamicArray3D {
private:
    float*** data;
    int xSize, ySize, zSize;

public:
    DynamicArray3D(int x, int y, int z);
    ~DynamicArray3D();
    float& operator()(int x, int y, int z);
    void fill(float value);
};

#endif // DYNAMIC_ARRAY_3D_HPP