#include <vector>

class PpmModuleDataState {
public:
    int ppm_map_type_state;
    int ppm_nrecvlist_state;
    int ppm_nsendlist_state;
    int ppm_nsendbuffer_state;
    int ppm_buffer_set_state;

    std::vector<int> ppm_psendbuffer_state;
    std::vector<int> ppm_buffer2part_state;
    std::vector<int> ppm_irecvlist_state;
    std::vector<int> ppm_isendlist_state;

    // Constructor
    PpmModuleDataState()
        : ppm_map_type_state(0), ppm_nrecvlist_state(0), ppm_nsendlist_state(0),
          ppm_nsendbuffer_state(0), ppm_buffer_set_state(0) {
    }
};