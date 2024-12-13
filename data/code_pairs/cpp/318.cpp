#include <iostream>

void print_optimize_message() {
    std::cout << "Preprocessor: " << std::endl;
    
    #ifdef ARTED_SC
    std::cout << "  ARTED_SC" << std::endl;
    #endif
    
    #ifdef ARTED_MS
    std::cout << "  ARTED_MS" << std::endl;
    #endif
}

int main() {
    print_optimize_message();
    return 0;
}