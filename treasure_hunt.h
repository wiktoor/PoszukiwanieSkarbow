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
    //typename T::strength_t;
    { x.pay() } -> ValueType;
    { T::isArmed } -> std::convertible_to<bool>;
    { [] () constexpr { return T::isArmed; }() };
    // { SafeTreasure<decltype(x.pay())> a(0); x.loot(a) } -> std::same_as<void>;
};

template<typename T>
concept EncounterSide = isTreasure<T> || isAdventurer<T>;

#endif /* TREASURE_HUNT_H */