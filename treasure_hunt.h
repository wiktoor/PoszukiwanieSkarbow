#ifndef TREASURE_HUNT_H
#define TREASURE_HUNT_H

#include "treasure.h"
#include "member.h"
#include <type_traits>
#include <concepts>

template <typename T>
concept isTreasure =
requires (T x) {
    { Treasure(x) } -> std::same_as<T>;
};

template<typename T>
concept isAdventurer = 
requires (T x) {
    { x.pay() } -> ValueType;
    { T::isArmed } -> std::convertible_to<bool>;
};

#endif /* TREASURE_HUNT_H */