#include <string>

class tableb_mod {
public:
    void TABLEB(int X, int Y, int VER, int& SCALE, int& REFVAL, int& WIDTH, std::string& IFORMAT, std::string& NAME, std::string& UNIT) {
        SCALE = X + Y;
        REFVAL = X - Y;
        WIDTH = X * Y;
        IFORMAT = "Format-A";
        NAME = "TestName";
        UNIT = "Unit-X";
    }
};