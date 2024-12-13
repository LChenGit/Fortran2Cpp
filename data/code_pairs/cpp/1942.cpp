#include <vector>
#include <string>

class BCAST_ALL_CH_ARRAY__genmod {
public:
    static void BCAST_ALL_CH_ARRAY(std::vector<std::string>& buffer, int NDIM, int COUNTVAL, const std::string& message) {
        buffer.clear(); // Make sure the buffer starts empty to match Fortran behavior
        buffer.resize(NDIM);
        
        for (auto& str : buffer) {
            // Fill each string with the message, truncated or padded as necessary
            str = message.substr(0, COUNTVAL);
        }
    }
};