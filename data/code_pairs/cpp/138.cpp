#include <vector>
#include <string>

struct asdf_record {
    std::vector<float> record;
};

struct asdf_event {
    std::string event = std::string(13, ' '); // Ensure the string is of length 13, filled with spaces
    int nreceivers;
    std::vector<std::string> receiver_name_array;
    std::vector<std::string> network_array;
    std::vector<std::string> component_array;
    std::vector<std::string> receiver_id_array;
    std::vector<asdf_record> records;
};