#include <stdio.h>
#include <omp.h>

int main()
{
    omp_lock_t lock;
    int i = 0;
    omp_init_lock(&lock);

#pragma omp parallel sections
    {
#pragma omp section
        {
            omp_set_lock(&lock);
            i = i + 1;
            omp_unset_lock(&lock);
        }
#pragma omp section
        {
            omp_set_lock(&lock);
            i = i + 2;
            omp_unset_lock(&lock);
        }
    }

    omp_destroy_lock(&lock);
    
    printf("I = %d\n", i);
    return 0;
}
