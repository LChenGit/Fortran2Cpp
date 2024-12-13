#include <vector>

class LinkedCells {
public:
    int nboxesx, nboxesy, nboxesz;
    double xmin, ymin, zmin, xmax, ymax, zmax;
    std::vector<std::vector<std::vector<int>>> ifirstbox; // 3D vector for ifirstbox
    std::vector<int> inextbox; // 1D vector for inextbox
};