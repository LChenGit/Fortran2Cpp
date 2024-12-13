// juslin_scr.hpp
#ifndef JUSLIN_SCR_HPP
#define JUSLIN_SCR_HPP

#include <iostream>

namespace juslin_scr {
    bool init_juslin() {
        std::cout << "Juslin module initialized." << std::endl;
        return true;
    }
}

#endif // JUSLIN_SCR_HPP