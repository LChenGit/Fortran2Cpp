#include <vector>
#include <string>

class AbsorberModule {
public:
    static const int max_absorbers = 10;
    static constexpr double pi = 3.141592653589793;
    std::vector<std::string> absorber_names;

    AbsorberModule() : absorber_names(max_absorbers) {}

    int find_absorber_index(const std::string& name) {
        for (int i = 0; i < max_absorbers; ++i) {
            if (absorber_names[i] == name) {
                return i;
            }
        }
        return -1; // Not found
    }
};