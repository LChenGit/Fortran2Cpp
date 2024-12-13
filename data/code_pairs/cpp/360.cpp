#ifndef WORKTYPE_H
#define WORKTYPE_H

#include <vector>

class WorkType {
public:
    int ntotal_kernel;
    int ndimensions;
    int nvertices;
    std::vector<std::vector<double>> vertices;
    std::vector<std::vector<double>> kernel_values;

    WorkType() : ntotal_kernel(0), ndimensions(0), nvertices(0) {}

    void init(int nkern, int ndim, int nverts) {
        ntotal_kernel = nkern;
        nvertices = nverts;
        ndimensions = ndim;

        vertices.resize(ndimensions, std::vector<double>(nvertices, 0.0));
        kernel_values.resize(ntotal_kernel, std::vector<double>(nvertices, 0.0));
    }
};

#endif // WORKTYPE_H