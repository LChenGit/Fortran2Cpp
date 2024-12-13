#ifndef MODEXAMPLE2_H
#define MODEXAMPLE2_H

#include <iostream>
#include <string>

namespace ModExample2 {

    constexpr char NameMod[] = "ModExample2";
    const float ExampleParameter = 1.0f; // Assuming ExampleParameter is defined here for simplicity

    void example_iroutine(float InputVar, float& OutputVar, float& InputOutputVar);

} // namespace ModExample2

#endif // MODEXAMPLE2_H