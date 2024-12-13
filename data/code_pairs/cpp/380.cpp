#include <cstddef>

namespace pr37287_1 {
    void set_null(void*& ptr) {
        ptr = nullptr;
    }
}