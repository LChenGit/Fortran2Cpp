#include <cstdlib>
#include <iostream>

int run_logic() {
    int i;
    bool l;

    l = false;
    i = -1;
    if (l) if (i) goto label999; else goto label999; else goto label999;

    l = true;
    if (l) if (i) goto label10; else goto label999; else goto label999;
    goto label999;

label10:
    i = 0;
    if (l) if (i) goto label999; else goto label20; else goto label999;
    goto label999;

label20:
    i = 1;
    if (l) if (i) goto label999; else goto label999; else goto label30;
    goto label999;

label999:
    return -1; // Instead of std::abort(), return an error code.

label30:
    return 0;
}

int main() {
    int result = run_logic();
    std::cout << "Test Result: " << result << std::endl;
    return result;
}