#include <iostream>
#include <fstream>
#include <string>

class Utils {
public:
    // Constants for floating point precision
    static const int sp = 6; // Placeholder for simplicity
    static const int dp = 15; // Placeholder for simplicity
    static const int qp = 33; // Placeholder for simplicity

private:
    std::ofstream logFile;

public:
    // Initialize the log file
    void logInit(const std::string &filename) {
        logFile.open(filename, std::ios::out);
        if (!logFile) {
            std::cerr << "Error opening file: " << filename << std::endl;
        }
    }

    // Log a warning message
    void logWarn(const std::string &message) {
        if (logFile.is_open()) {
            logFile << " ---- WARNING: " << message << std::endl;
        } else {
            std::cerr << "Log file not open!" << std::endl;
        }
    }

    // Log an error message
    void logError(const std::string &message) {
        if (logFile.is_open()) {
            logFile << " **** ERROR: " << message << std::endl;
        } else {
            std::cerr << "Log file not open!" << std::endl;
        }
    }

    // Log a note message
    void logNote(const std::string &message) {
        if (logFile.is_open()) {
            logFile << " NOTE: " << message << std::endl;
        } else {
            std::cerr << "Log file not open!" << std::endl;
        }
    }

    // Close the log file
    void logClose() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }
};

int main() {
    Utils utils;
    utils.logInit("test_logfile.txt");
    utils.logWarn("This is a warning message.");
    utils.logError("This is an error message.");
    utils.logNote("This is a note message.");
    utils.logClose();

    return 0;
}