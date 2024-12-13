#ifndef FORTIUM_DEFINES_HPP
#define FORTIUM_DEFINES_HPP

#include <cstdint>

namespace fortium_defines {

    constexpr std::int64_t crypto_hash_sha512_BYTES = 64;

    constexpr std::int64_t crypto_auth_hmacsha512_BYTES = 64;
    constexpr std::int64_t crypto_auth_hmacsha512_KEYBYTES = 64;

    constexpr const char *crypto_auth_PRIMITIVE = "hmacsha512256";

    constexpr std::int64_t crypto_auth_hmacsha512256_BYTES = 32;
    constexpr std::int64_t crypto_auth_hmacsha512256_KEYBYTES = 32;
    constexpr std::int64_t crypto_auth_BYTES = crypto_auth_hmacsha512256_BYTES;
    constexpr std::int64_t crypto_auth_KEYBYTES = crypto_auth_hmacsha512256_KEYBYTES;

}

#endif // FORTIUM_DEFINES_HPP