#include <string>

class GlobalPHMF {
public:
    static int ioutPHMF;
    static int iprecision;
    static int ndigits;
    static std::string outfile;

    static void initialize() {
        ioutPHMF = 0;
        iprecision = 2;
        ndigits = 7;
        outfile = "PreHeadsMF_output.txt";
    }
};

// Initialize static members outside the class definition
int GlobalPHMF::ioutPHMF = 0;
int GlobalPHMF::iprecision = 2;
int GlobalPHMF::ndigits = 7;
std::string GlobalPHMF::outfile = "PreHeadsMF_output.txt";