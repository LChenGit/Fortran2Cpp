#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

constexpr size_t MAX_STRING_LEN = 256;

void createNameDatabase(std::string& prname, int iproc, int iregionCode, const std::string& localPath) {
    std::ostringstream procnameStream;
    procnameStream << "/proc" << std::setw(6) << std::setfill('0') << iproc << "_reg" << iregionCode << "_";
    prname = localPath + procnameStream.str(); // Using string concatenation for path manipulation
    if (prname.size() > MAX_STRING_LEN) {
        throw std::runtime_error("Resulting path exceeds maximum allowed length.");
    }
}

void createNameDatabaseAdios(std::string& prname, int iregionCode, const std::string& localPath) {
    std::ostringstream procnameStream;
    procnameStream << "/reg" << iregionCode << "_";
    prname = localPath + procnameStream.str(); // Using string concatenation for path manipulation
    if (prname.size() > MAX_STRING_LEN) {
        throw std::runtime_error("Resulting path exceeds maximum allowed length.");
    }
}