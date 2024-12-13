#ifndef PPM_MODULE_COLOR_EDGE_H
#define PPM_MODULE_COLOR_EDGE_H

#include <vector>

class Vertex {
public:
    int degree = 0;
    int color = 0;
    int dsat = 0;
    bool iscolored = false;
    int loc_heap = 0;
    std::vector<int> list;
};

class List {
public:
    std::vector<int> adj_edge;
};

class PpmModuleColorEdge {
public:
    std::vector<Vertex> node;
    std::vector<int> nelem;
    std::vector<int> offset;
    std::vector<List> edges_per_node;
    std::vector<List> lists;
    std::vector<std::vector<int>> node_sat;
    std::vector<int> size_heap;
    std::vector<bool> used_color;

    int nvertices = 0;
    int nedges = 0;
    int max_degree = 0;
    int ncolor = 0;
    int alloc_error = 0;

    void ppm_color_edge() {
        std::cout << "ppm_color_edge called - implement your logic here." << std::endl;
    }
};

#endif // PPM_MODULE_COLOR_EDGE_H