// DataDiag.h
#include <string>

class DataDiag {
public:
    bool dump_mesh_info_files;
    bool dump_mesh_info_screen;
    bool dump_mesh_vtk;
    bool dump_1dmodel;
    bool only_suggest_ntheta;
    std::string diagpath;
    int lfdiag;

    // Constructor to initialize members
    DataDiag()
        : dump_mesh_info_files(false),
          dump_mesh_info_screen(false),
          dump_mesh_vtk(false),
          dump_1dmodel(false),
          only_suggest_ntheta(false),
          diagpath(""),
          lfdiag(0) {}
};