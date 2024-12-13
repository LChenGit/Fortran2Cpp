#include <iostream>
#include <cstring>
#include <cstdlib>

void T(char A[], char B[], int lenA, int lenB);

int main() {
    char A[11]; // Correct length including null terminator
    char B[9];  // Correct length including null terminator
    strcpy(A, "gfortran  "); // Correctly copying strings into the character arrays, considering the null terminator
    strcpy(B, "rocks!  "); 

    T(A, B, 10, 8); // Passing the strings and their intended fixed lengths to the subroutine
    
    return 0;
}

void T(char A[], char B[], int lenA, int lenB) {
    if(strlen(A) != lenA) abort();
    if(strlen(B) != lenB) abort();
}