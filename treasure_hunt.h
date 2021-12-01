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
concept EncounterSide = (isTreasure<T> || isAdventurer<T>);

template<typename T, typename U>
requires EncounterSide<T> && EncounterSide<U>
class Encounter {
    public: 
        T sideA;
        U sideB;
        constexpr Encounter(T A, U B) : sideA(A), sideB(B) { };
};

/*
template <typename T, typename U>
requires isTreasure<T> && isAdventurer<U>
void run(Encounter<T, U> encounter) {
    encounter.sideB.loot(encounter.sideA);
}

template <typename T, typename U>
requires isAdventurer<T> && isTreasure<U>
void run(Encounter<T, U> encounter) {
    encounter.sideA.loot(encounter.sideB);
}

template <typename T, typename U>
requires isAdventurer<T> && isAdventurer<U>
void run(Encounter<T, U> encounter) {
    T& A = encounter.sideA;
    U& B = encounter.sideB;
    if (A.isArmed && B.isArmed) {
        if (A.getStrength() > B.getStrength()) {
            auto value = B.pay();
            SafeTreasure<decltype(value)> treasure(value);
            A.loot(treasure);
        }
        if (A.getStrength() < B.getStrength()) {
            run(B, A);
        }
        return;
    }
    if (A.isArmed) {
        auto value = B.pay();
        SafeTreasure<decltype(value)> treasure(value);
        A.loot(treasure);
        return;
    }
    if (B.isArmed) {
        run(B, A);
    }
}
*/

#endif /* TREASURE_HUNT_H */