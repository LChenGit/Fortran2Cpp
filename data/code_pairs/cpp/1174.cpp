#include <string>

class GribHandler {
public:
    void grib_index_get(const std::string& key, int& value) {
        if (key == "intKey") {
            value = 42;
        } else {
            value = -1;
        }
    }

    void grib_index_get(const std::string& key, std::string& value) {
        if (key == "stringKey") {
            value = "TestString";
        } else {
            value = "Unknown";
        }
    }

    // Additional methods can be added here
};