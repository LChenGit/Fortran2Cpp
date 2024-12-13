#include <limits>
#include <cmath>

class GeohashMod {
public:
    static int geohash(float lon, float lat) {
        const float scale = 120.0f;
        const float offset = 0.5f;
        const int rowlen = static_cast<int>(std::round(scale * 360.0f));
        int i = static_cast<int>(std::round(offset + scale * (lon + 180.0f)));
        int j = static_cast<int>(std::round(offset + scale * (lat + 90.0f)));
        return i + rowlen * (j - 1);
    }
};