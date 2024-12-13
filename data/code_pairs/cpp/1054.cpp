#include <cstdint>
#include <cstdlib>

extern "C" void* dump_lua_toBuf(void* L, std::int32_t length, std::int32_t& ierr) {
    if (length <= 0) {
        ierr = 1; // Error condition
        return nullptr;
    }
    ierr = 0; // Success
    return malloc(length); // Allocate buffer and return (for testing)
}