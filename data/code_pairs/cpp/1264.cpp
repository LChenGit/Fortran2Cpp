#ifndef PRECISION_H
#define PRECISION_H

#include <cstddef> // For std::size_t
#include <cstdint> // For fixed width integer types

namespace Precision {

constexpr std::int16_t B1Ki = std::numeric_limits<std::int16_t>::max();
constexpr std::int32_t B2Ki = std::numeric_limits<std::int32_t>::max();
constexpr std::int32_t B4Ki = std::numeric_limits<std::int32_t>::max();
constexpr std::int64_t B8Ki = std::numeric_limits<std::int64_t>::max();

using QuKi = long double; // Highest precision
using R8Ki = double;      // Double precision
using SiKi = float;       // Single precision

constexpr std::size_t BYTES_IN_SiKi = sizeof(SiKi);
constexpr std::size_t BYTES_IN_R8Ki = sizeof(R8Ki);
constexpr std::size_t BYTES_IN_QuKi = sizeof(QuKi);

using IntKi = std::int32_t; // Default integer kind
constexpr std::size_t BYTES_IN_INT = sizeof(IntKi);

#ifndef DOUBLE_PRECISION
using ReKi = SiKi;
using DbKi = R8Ki;

constexpr std::size_t BYTES_IN_REAL = BYTES_IN_SiKi;
constexpr std::size_t BYTES_IN_DBL = BYTES_IN_R8Ki;
#else
using ReKi = R8Ki;
using DbKi = QuKi;

constexpr std::size_t BYTES_IN_REAL = BYTES_IN_R8Ki;
constexpr std::size_t BYTES_IN_DBL = BYTES_IN_QuKi;
#endif

} // namespace Precision

#endif // PRECISION_H