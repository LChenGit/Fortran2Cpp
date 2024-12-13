// factorial.h
#ifndef FACTORIAL_H
#define FACTORIAL_H

int factorial(int n) {
    int fact = 1;
    for(int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

#endif // FACTORIAL_H