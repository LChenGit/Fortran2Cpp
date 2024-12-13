#ifndef ENUMS_H
#define ENUMS_H

enum class Color : int {
    red = 1, blue, gold, silver, bronze, purple
};

// The Enums class declaration
class Enums {
public:
    float somevar;
    static constexpr float othervar = 42.0;

    Enums() : somevar(0.0f) {}
    float Func(float arg);
};

#endif // ENUMS_H