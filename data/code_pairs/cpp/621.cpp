#include <fstream>
#include <iostream>
#include <string>

void GenerateKML(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    file << R"(<?xml version="1.0" encoding="UTF-8"?>)" << std::endl
         << R"(<kml xmlns="http://www.opengis.net/kml/2.2">)" << std::endl
         << "<Document>" << std::endl
         << "<Placemark>" << std::endl
         << "<name>Simple Placemark</name>" << std::endl
         << "<Point>" << std::endl
         << "<coordinates>-122.0822035425683,37.42228990140251,0</coordinates>" << std::endl
         << "</Point>" << std::endl
         << "</Placemark>" << std::endl
         << "</Document>" << std::endl
         << "</kml>" << std::endl;

    file.close();
}

int main() {
    GenerateKML("test_cpp.kml");
    return 0;
}