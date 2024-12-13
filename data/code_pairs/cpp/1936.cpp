// Foo.h
#ifndef FOO_H
#define FOO_H

class Foo {
public:
    float a = 0.0f;

    Foo() = default;
    void assign(float value);
};

#endif // FOO_H