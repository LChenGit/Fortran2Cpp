#ifndef UTILITIES_H
#define UTILITIES_H

namespace Utilities {

template<typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

} // namespace Utilities

#endif // UTILITIES_H