// MyType.hpp
#ifndef MYTYPE_HPP
#define MYTYPE_HPP

class MyType {
public:
    int i;
    MyType(int x = 0) : i(x) {}
};

MyType* get(MyType& a) {
    return &a;
}

MyType* get2(MyType& a) {
    return &a;
}

#endif // MYTYPE_HPP