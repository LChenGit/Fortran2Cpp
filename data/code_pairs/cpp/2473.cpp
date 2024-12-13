#include <iostream>
#include <vector>
#include <string>
#include <Eigen/Dense>

using DOUBLE = double;

void drcout(const Eigen::MatrixXd& XYZ3, const Eigen::MatrixXd& GEO3, const Eigen::MatrixXd& VEL3, 
            int NVAR, DOUBLE TIME, const Eigen::Vector3d& ESCF3, const Eigen::Vector3d& EKIN3, 
            const Eigen::Vector3d& ETOT3, const Eigen::Vector3d& XTOT3, int ILOOP, 
            const std::vector<DOUBLE>& CHARGE, DOUBLE FRACT, const std::string& TEXT1, 
            const std::string& TEXT2, int II, int& JLOOP) {

    std::cout << "XYZ3:\n" << XYZ3 << std::endl;
    std::cout << "GEO3:\n" << GEO3 << std::endl;
    std::cout << "VEL3:\n" << VEL3 << std::endl;
    std::cout << "TIME: " << TIME << std::endl;
    std::cout << "ESCF3: " << ESCF3.transpose() << std::endl;
    std::cout << "EKIN3: " << EKIN3.transpose() << std::endl;
    std::cout << "ETOT3: " << ETOT3.transpose() << std::endl;
    std::cout << "XTOT3: " << XTOT3.transpose() << std::endl;
    std::cout << "ILOOP: " << ILOOP << std::endl;

    std::cout << "CHARGE: ";
    for (double charge : CHARGE) std::cout << charge << " ";
    std::cout << std::endl;

    std::cout << "FRACT: " << FRACT << std::endl;
    std::cout << "TEXT1: " << TEXT1 << std::endl;
    std::cout << "TEXT2: " << TEXT2 << std::endl;
    std::cout << "II: " << II << std::endl;
    std::cout << "JLOOP: " << JLOOP << std::endl;
}

int main() {
    int NVAR = 3;
    Eigen::MatrixXd XYZ3(3, NVAR), GEO3(3, NVAR), VEL3(3, NVAR);
    XYZ3 << 1, 2, 3,
            4, 5, 6,
            7, 8, 9;
    GEO3 << 1.1, 2.1, 3.1,
            4.1, 5.1, 6.1,
            7.1, 8.1, 9.1;
    VEL3 << 0.1, 0.2, 0.3,
            0.4, 0.5, 0.6,
            0.7, 0.8, 0.9;
    DOUBLE TIME = 10.0;
    Eigen::Vector3d ESCF3(1.0, 2.0, 3.0), EKIN3(4.0, 5.0, 6.0), ETOT3(7.0, 8.0, 9.0), XTOT3(10.0, 11.0, 12.0);
    int ILOOP = 2;
    std::vector<DOUBLE> CHARGE = {0.5, 0.6, 0.7};
    DOUBLE FRACT = 0.3;
    std::string TEXT1 = "ABC";
    std::string TEXT2 = "XY";
    int II = 1;
    int JLOOP = 0;

    drcout(XYZ3, GEO3, VEL3, NVAR, TIME, ESCF3, EKIN3, ETOT3, XTOT3, ILOOP, CHARGE, FRACT, TEXT1, TEXT2, II, JLOOP);

    return 0;
}