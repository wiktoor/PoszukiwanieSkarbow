#ifndef TREASURE_H
#define TREASURE_H

#include <numeric>
#include <concepts>

using IsTrapped = bool;

template <typename T>
struct isInteger {
    static constexpr bool value = std::numeric_limits<T>::is_integer;
};

template<typename T>
concept ValueType = isInteger<T>::value;

template<typename T>
requires ValueType<T>
class Treasure {
    private:
        T value;
        IsTrapped isTrapped;
    public: 
        constexpr Treasure(T value, IsTrapped isTrapped) : value(value), isTrapped(isTrapped) { };
};

#endif