#include <iostream>
#include <vector>
#include <omp.h>

int main() {
    std::vector<int> a(16, 0);

    #pragma omp parallel
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                for (auto& val : a) {
                    #pragma omp atomic
                    val += 1;
                }
            }
            #pragma omp section
            {
                for (auto& val : a) {
                    #pragma omp atomic
                    val += 2;
                }
            }
        }
    }

    for (auto val : a) {
        if (val != 3) {
            std::cerr << "Error: Not all elements are 3" << std::endl;
            return 1;
        }
    }

    std::cout << "All elements are 3." << std::endl;
    return 0;
}