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

template<typename T, IsTrapped trapped>
requires ValueType<T>
class Treasure {
    private:
        T value;
    public:
        static const IsTrapped isTrapped = trapped; 
        constexpr Treasure(T value) : value(value) { };
        constexpr T evaluate() { return value; }
        constexpr T getLoot() {
            T res = value;
            value = 0;
            return res;
        }
};

template<typename T>
requires ValueType<T>
using SafeTreasure = Treasure<T, false>;

template<typename T>
requires ValueType<T>
using TrappedTreasure = Treasure<T, true>;


#endif