#include <cstdint>
#include <cmath>

extern "C" {
    std::int32_t MurmurHash2(const void* key, int N, std::int32_t seed);
}

namespace hashing {

int murmurhash_bit_string(const int* f, int N, std::int32_t seed) {
    int hash;
    int nbytes = static_cast<int>(std::ceil(static_cast<float>(N) / 32.0) * 4);
    const void* key = static_cast<const void*>(f);

    hash = MurmurHash2(key, nbytes, seed);

    return hash;
}

} // namespace hashing