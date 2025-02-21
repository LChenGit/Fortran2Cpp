// utilbd.cpp
#include <iostream>

class UtilBD {
public:
    int IU[14];
    int NQ, NF, IF[1], JX, JY;
    double QX[1], QY[1];

    void initUtilbd() {
        IU[0] = 1; 
        IU[1] = 1;
        IU[2] = 10;
        IU[3] = 10;
        IU[4] = 50;
        IU[5] = 2;
        IU[6] = 1;
        IU[7] = 1;
        IU[8] = 1;
        IU[9] = 8000;
        IU[10] = 0;
        IU[11] = 1;
        IU[12] = 1000;
        IU[13] = 1000;

        NQ = 1;
        QX[0] = 0.0; 
        QY[0] = 0.0;
        NF = 1;
        IF[0] = 1; 
        JX = 0;
        JY = 0;
    }

    void printValues() {
        std::cout << "IU: ";
        for (int i = 0; i < 14; ++i) {
            std::cout << IU[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "NQ, NF, IF, JX, JY: " << NQ << ", " << NF << ", " << IF[0] << ", " << JX << ", " << JY << std::endl;
        std::cout << "QX, QY: " << QX[0] << ", " << QY[0] << std::endl;
    }

    double add(double x, double y) {
        return x + y;
    }
};

int main() {
    UtilBD utilbd;
    utilbd.initUtilbd();
    utilbd.printValues();

    std::cout << "Addition test: " << utilbd.add(5.0, 3.0) << std::endl;

    return 0;
}