#include <cstdint> // For std::int32_t

void get_loop_index(int instr_index, int& index, bool& subrange_flag) {
    const std::int32_t in_index_mask = 65536;
    std::int32_t mask_val = instr_index & in_index_mask;

    if (mask_val == 0) {
        subrange_flag = false;
        index = instr_index;
    } else {
        subrange_flag = true;
        index = instr_index ^ in_index_mask;
    }
}