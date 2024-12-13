#ifndef FOO_H
#define FOO_H

// Base class
class Foo {
public:
    virtual void doit() { i = 1; }
    virtual int getit() const { return i; }
protected:
    int i{0};
};

// Derived class
class Foo2 : public Foo {
public:
    void doit() override {
        i = 2;
        j = 3;
    }
    int getit() const override { return j; }
private:
    int j{0};
};

#endif // FOO_H