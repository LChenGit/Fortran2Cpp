#include <vector>
#include <iostream>

struct evtlist_type {
    std::vector<float> p1;
    std::vector<float> p2;
    std::vector<float> p3;
    std::vector<float> p4;
};

int main() {
    evtlist_type event;

    // Resize arrays
    event.p1.resize(10);
    event.p2.resize(10);
    event.p3.resize(10);
    event.p4.resize(10);

    // Assign values
    for (int i = 0; i < 10; ++i) {
        event.p1[i] = (i + 1) * 1.0f;
        event.p2[i] = (i + 1) * 2.0f;
        event.p3[i] = (i + 1) * 3.0f;
        event.p4[i] = (i + 1) * 4.0f;
    }

    // Print the values to verify
    std::cout << "p1 values: ";
    for (auto val : event.p1) std::cout << val << " ";
    std::cout << "\np2 values: ";
    for (auto val : event.p2) std::cout << val << " ";
    std::cout << "\np3 values: ";
    for (auto val : event.p3) std::cout << val << " ";
    std::cout << "\np4 values: ";
    for (auto val : event.p4) std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}