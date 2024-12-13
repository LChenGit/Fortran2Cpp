// C++ function file: f_function.cpp
int f() {
    static int g; // Considering the SAVE attribute for demonstration
    g = 42;
    return g;
}