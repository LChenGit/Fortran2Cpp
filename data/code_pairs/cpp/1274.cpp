#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <array>

class Vector2D {
public:
    std::array<int, 2> values;

    Vector2D(int x = 0, int y = 0) {
        values[0] = x;
        values[1] = y;
    }

    // Overloaded '+' operator for adding two Vector2D objects
    Vector2D operator+(const Vector2D& rhs) const {
        return Vector2D(values[0] + rhs.values[0], values[1] + rhs.values[1]);
    }
};

#endif // VECTOR2D_H