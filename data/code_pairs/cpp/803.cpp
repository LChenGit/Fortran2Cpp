#include <vector>

class DataCoarse {
public:
    int nc;
    int ns_ib;
    std::vector<int> iclev;
    std::vector<int> iclevc;

    DataCoarse() = default; 
    ~DataCoarse() = default;
};