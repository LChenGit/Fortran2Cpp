int Array[2][3];
int elements[] = {1, 4, 2, 5, 3, 6};
int index = 0;

// Initialize Array in column-major order
for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < 2; ++i) {
        Array[i][j] = elements[index++];
    }
}

int Brray[2][3] = {0}; // All elements initialized to 0