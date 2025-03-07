#include <iostream>
#include <string>
#include <cassert>

int main() {
    int ivar1 = 3;
    std::string cvar1;
    char cvar2 = ' ';  // Initialize to a default character
    bool lvar1 = true;
    float rvar1 = 0.0f;

    // First SELECT CASE equivalent for ivar1
    if (ivar1 <= -1) {
        cvar1 = "path";
    } else if (ivar1 == 10/5 - 2) { // 0
        // No action
    } else if (ivar1 == 1) {
        // No action
    } else if ((ivar1 >= 2 && ivar1 <= 3) || 
               (ivar1 >= 5 && ivar1 <= 7) || 
               ivar1 == 9) {
        // No action
    } else if (ivar1 >= 10) {
        // No action
    } else {
        cvar1 = "no path!";
        cvar2 = 'd';
    }

    // Second SELECT CASE equivalent for lvar1
    if (lvar1 == false) {
        // Handle .false.
    } else if (lvar1 == true) {
        // Handle .true.
    }

    // Third SELECT CASE
    cvar1 = "hamster";
    if (cvar1 <= "cat") {
        // Handle up to 'cat'
    } else if (cvar1 >= "dog" && cvar1 <= "ferret") {
        // Handle 'dog' to 'ferret'
    } else if (cvar1 == "gerbil") {
        // Handle 'gerbil'
    } else if (cvar1 >= "horse") {
        // Handle above 'horse'
    } else {
        // Default case
    }

    // Fourth SELECT CASE equivalent for rvar1
    if (rvar1 == -1.0f) {
        // Handle -1.0
    } else if (rvar1 >= 2.0f && rvar1 <= 5.0f) {
        // Handle range
    } else if (rvar1 == ivar1) {
        // Handle if rvar1 equals ivar1
    } else if (rvar1 == 0.0f) {
        // Handle logical condition
    }

    // Unit tests
    assert(cvar2 == 'd');
    assert(cvar1 == "hamster");
    assert(ivar1 == 3);
    assert(lvar1 == true);
    assert(rvar1 == 0.0f);

    std::cout << "All tests passed." << std::endl;
    return 0;
}