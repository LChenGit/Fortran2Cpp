#ifndef SCALAR_POOL_H
#define SCALAR_POOL_H

#include <vector>
#include <omp.h>

class ScalarPool {
private:
    std::vector<float> pool;
    omp_lock_t lock;

public:
    ScalarPool(int size);
    ~ScalarPool();
    void acquireResource(int id, float& resource);
    void releaseResource(int id, float resource);
};

#endif // SCALAR_POOL_H