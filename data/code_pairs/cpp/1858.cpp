#include <iostream>
#include <cstdbool> // For bool type in C++

// Assuming the function signature from the previous example:
void meshFEM3DModelCrust(double lat, double lon, double r, double& vpc,
                         double& vsc, double& rhoc, double& moho,
                         bool& foundCrust, bool elemInCrust) {
    vpc = lat + lon + r;
    vsc = lat * lon * r;
    rhoc = lat - lon - r;
    moho = lat / lon / r;
    foundCrust = elemInCrust;
}

int main() {
    double lat = 45.0, lon = 90.0, r = 6371.0;
    double vpc, vsc, rhoc, moho;
    bool foundCrust, elemInCrust = true;

    meshFEM3DModelCrust(lat, lon, r, vpc, vsc, rhoc, moho, foundCrust, elemInCrust);

    std::cout << "VPC: " << vpc << std::endl;
    std::cout << "VSC: " << vsc << std::endl;
    std::cout << "RHOC: " << rhoc << std::endl;
    std::cout << "MOHO: " << moho << std::endl;
    std::cout << "Found Crust: " << std::boolalpha << foundCrust << std::endl;

    return 0;
}