#include <iostream>

class FoX_wcml {
public:
    void cmlBeginFile() {
        std::cout << "Beginning file..." << std::endl;
    }

    void cmlFinishFile() {
        std::cout << "Finishing file..." << std::endl;
    }

    void cmlAddNamespace() {
        std::cout << "Adding namespace..." << std::endl;
    }

    void cmlStartCml() {
        std::cout << "Starting CML..." << std::endl;
    }

    void cmlEndCml() {
        std::cout << "Ending CML..." << std::endl;
    }
};