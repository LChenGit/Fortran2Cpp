#include <iostream>
using namespace std;

class MathsUtils {
public:
    static int cds1(int nPoints, int dim) {
        if (dim == 1) {
            return nPoints - 1;
        } else {
            return nPoints;
        }
    }
    
    static int cds2(int nPoints, int dim) {
        if (dim == 2) {
            return nPoints - 1;
        } else {
            return nPoints;
        }
    }
};