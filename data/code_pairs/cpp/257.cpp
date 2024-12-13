#include <iostream>
#include <vector>

void instef(float effic, int xext, int yext, std::vector<std::vector<float>>& image) {
    for (int j = 0; j < yext; ++j) {
        for (int i = 0; i < xext; ++i) {
            image[i][j] = image[i][j] * effic;
        }
    }
}

int main() {
    int xext = 3;
    int yext = 2;
    float effic = 2.0f;
    std::vector<std::vector<float>> image(xext, std::vector<float>(yext));

    // Initialize the image array
    for (int j = 0; j < yext; ++j) {
        for (int i = 0; i < xext; ++i) {
            image[i][j] = i + j + 2; // +2 to adjust for 0-based indexing in C++
        }
    }

    // Call the instef function
    instef(effic, xext, yext, image);

    // Print the modified image array
    for (int j = 0; j < yext; ++j) {
        for (int i = 0; i < xext; ++i) {
            std::cout << "image(" << i << "," << j << ") = " << image[i][j] << std::endl;
        }
    }

    return 0;
}