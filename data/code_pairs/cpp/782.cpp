#include <vector>
#include <iostream>

class SoopStars {
public:
    std::vector<std::vector<float>> position;

    SoopStars(int numRows, int numCols) {
        position.resize(numRows, std::vector<float>(numCols, 0.0f));
    }
};

class Show {
public:
    SoopStars rocket;

    Show(const SoopStars& boom) : rocket(boom) {}
};

Show newShow(const SoopStars& boom) {
    return Show(boom);
}

void testShowInitialization() {
    SoopStars fireworks(2, 2);
    for (auto& row : fireworks.position) {
        std::fill(row.begin(), row.end(), 33.0f);
    }
    
    Show july4 = newShow(fireworks);

    bool testPassed = true;
    for (const auto& row : july4.rocket.position) {
        for (float pos : row) {
            if (pos != 33.0f) {
                testPassed = false;
                break;
            }
        }
        if (!testPassed) break;
    }

    if (testPassed) {
        std::cout << "Test Passed: All positions are 33.0" << std::endl;
    } else {
        std::cout << "Test Failed: Position mismatch" << std::endl;
    }
}

int main() {
    testShowInitialization();
    return 0;
}