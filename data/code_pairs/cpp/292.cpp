#ifndef MODREPORT_H
#define MODREPORT_H

#include <string>

class ModReport {
public:
    int tests = 0;
    int nfailed = 0;
    int npassed = 0;
    int reportfileu = 0;
    std::string reportfilename = "";
    std::string testplan_name = "";
    std::string tdirectory = "";
    std::string testunitname = "";
    std::string inputf = "";
    std::string outputf = "";

    // Constructor and Destructor
    ModReport() = default;
    ~ModReport() = default;
};

#endif // MODREPORT_H