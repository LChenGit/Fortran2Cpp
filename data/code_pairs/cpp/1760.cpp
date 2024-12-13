#include <vector>
#include <string>

using i_long = long int;      // Adjust as per actual types used
using i_short = short int;    // Adjust as per actual types used

struct ncdr_file {
    int dummy;  // Placeholder for actual content
};

class ncdr_state {
public:
    static constexpr i_short NCDR_DEFAULT_ENT = 1024;
    static constexpr i_long NCDR_CHUNKING = 16384;

    bool init_done;
    i_long ncdr_id_stack_count;
    i_long ncdr_file_count;

    ncdr_state() : init_done(false), current_ncdr_id(-1), ncdr_id_stack_size(0),
                   ncdr_id_stack_count(0), ncdr_file_count(0), ncdr_file_total(0),
                   ncdr_file_highest(0) {}

private:
    i_long current_ncdr_id;
    std::vector<i_long> ncdr_id_stack;
    i_long ncdr_id_stack_size;
    std::string cur_nc_file; // Adjusted to 200 chars in constructor if needed

    std::vector<ncdr_file> ncdr_files;
    i_long ncdr_file_total;
    i_long ncdr_file_highest;
};