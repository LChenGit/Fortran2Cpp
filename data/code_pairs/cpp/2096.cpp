#include <fstream>
#include <iomanip>

void writesta(int istep, int j, int icutb, int l, double ttime, double time, double dtime) {
    std::ofstream fileStream("unit8.txt", std::ios_base::app);

    if (!fileStream.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    fileStream << std::fixed << std::setprecision(6)
               << " " << std::setw(5) << istep
               << " " << std::setw(10) << j
               << " " << std::setw(5) << icutb + 1
               << " " << std::setw(5) << l
               << " " << std::setw(13) << std::scientific << ttime + time
               << " " << std::setw(13) << std::scientific << time
               << " " << std::setw(13) << std::scientific << dtime << std::endl;

    fileStream.close();
}