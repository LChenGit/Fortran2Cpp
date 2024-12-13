#include <cmath>
void switch1(float& sw, float& dsw, float z, float p1, float ip1, float zmemb1, float zmemb2) {
    float delz, delzp1;

    if (z >= (zmemb2 + p1) || z <= (zmemb1 - p1)) {
        sw = 0.0f;
        dsw = 0.0f;
    } else {
        if (z > zmemb2) {
            delz = z - zmemb2;
            delzp1 = delz * ip1;
            sw = 1.0f + (2.0f * delzp1 - 3.0f) * pow(delzp1, 2);
            dsw = -6.0f * (delzp1 - 1.0f) * ip1 * delzp1;
        } else if (z < zmemb1) {
            delz = zmemb1 - z;
            delzp1 = delz * ip1;
            sw = 1.0f + (2.0f * delzp1 - 3.0f) * pow(delzp1, 2);
            dsw = 6.0f * (delzp1 - 1.0f) * ip1 * delzp1;
        } else {
            sw = 1.0f;
            dsw = 0.0f;
        }
    }
}