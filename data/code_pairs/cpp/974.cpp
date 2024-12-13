#include <string>

namespace NetCDF {
    bool openFile(const std::string& filename) {
        // Simplified example: Assume success if filename is "example.nc"
        return filename == "example.nc";
    }
}