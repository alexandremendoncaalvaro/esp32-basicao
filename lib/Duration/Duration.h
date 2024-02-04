#pragma once

#include <cstdint>
#include <ratio>

/// A simple duration type similar to the standard library.
///
/// This duration is simplified for the usage in embedded code.
/// The type definitions will use unsigned types, so there are
/// only positive durations possible.
///
/// The idea is to allow a syntax like `20_ms` in the code,
/// which can be verified by functions to make sure the correct
/// durations are passed. It does also greatly improve the
/// readability of the code.
///
template <typename TickType, typename Ratio>
class Duration
{
public:
    /// Create a new duration.
    ///
    constexpr explicit Duration(TickType ticks) noexcept : _ticks(ticks) {}

public: // Operators
    constexpr inline bool operator==(const Duration &other) const noexcept { return _ticks == other._ticks; }
    constexpr inline bool operator!=(const Duration &other) const noexcept { return _ticks != other._ticks; }
    constexpr inline bool operator>(const Duration &other) const noexcept { return _ticks > other._ticks; }
    constexpr inline bool operator>=(const Duration &other) const noexcept { return _ticks >= other._ticks; }
    constexpr inline bool operator<(const Duration &other) const noexcept { return _ticks < other._ticks; }
    constexpr inline bool operator<=(const Duration &other) const noexcept { return _ticks <= other._ticks; }
    constexpr inline Duration operator+(const Duration &other) const noexcept { return Duration(_ticks + other._ticks); }
    constexpr inline Duration operator-(const Duration &other) const noexcept { return Duration(_ticks - other._ticks); }

public:
    /// Get the number of ticks.
    ///
    constexpr inline TickType ticks() const noexcept { return _ticks; }

    /// Convert to Milliseconds.
    ///
    constexpr inline Duration<TickType, std::milli> toMilliseconds() const noexcept
    {
        typedef std::ratio_divide<Ratio, std::milli> r;
        return Duration<TickType, std::milli>(_ticks * r::num / r::den);
    }

private:
    TickType _ticks; ///< The number of ticks.
};

/// Seconds
///
typedef Duration<uint32_t, std::ratio<1, 1>> Seconds;
constexpr Seconds operator"" _s(unsigned long long int ticks)
{
    return Seconds(static_cast<uint32_t>(ticks));
}

/// Milliseconds.
///
typedef Duration<uint32_t, std::milli> Milliseconds;
constexpr Milliseconds operator"" _ms(unsigned long long int ticks)
{
    return Milliseconds(static_cast<uint32_t>(ticks));
}

/// Microseconds.
///
typedef Duration<uint32_t, std::micro> Microseconds;
constexpr Microseconds operator"" _us(unsigned long long int ticks)
{
    return Microseconds(static_cast<uint32_t>(ticks));
}

/// Nanoseconds.
///
typedef Duration<uint32_t, std::nano> Nanoseconds;
constexpr Nanoseconds operator"" _ns(unsigned long long int ticks)
{
    return Nanoseconds(static_cast<uint32_t>(ticks));
}

static Duration<uint32_t, std::milli> getMillis() noexcept
{
    return Duration<uint32_t, std::milli>(millis());
}
