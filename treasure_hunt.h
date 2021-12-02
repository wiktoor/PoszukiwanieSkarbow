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
    //SafeTreasure<decltype(x.pay())> a(x.pay());
    { x.loot(SafeTreasure<decltype(x.pay())>(0)) } -> std::same_as<void>;
};

template<typename T>
concept EncounterSide = (isTreasure<T> || isAdventurer<T>);

template<typename T, typename U>
requires EncounterSide<T> && EncounterSide<U>
class Encounter {
    public: 
        T& sideA;
        U& sideB;
        constexpr Encounter(T& A, U& B) : sideA(A), sideB(B) { };
};

template <typename T> 
concept isEncounter = 
requires (T x) {
    { Encounter(x) } -> std::same_as<T>;
};

template <typename T>
concept Weapon = 
requires (T x) {
	x.getStrength();
};

template <typename T> 
concept Armored = (isAdventurer<T> && Weapon<T>);

template <typename T> 
concept Unarmored = (isAdventurer<T> && !Weapon<T>);

/* ***** FUNKCJE RUN ***** */
template <typename T, typename U>
requires isTreasure<T> && isAdventurer<U>
constexpr void run(Encounter<T, U> encounter) {
    encounter.sideB.loot(std::move(encounter.sideA));
}

template <typename T, typename U>
requires isAdventurer<T> && isTreasure<U>
constexpr void run(Encounter<T, U> encounter) {
    encounter.sideA.loot(std::move(encounter.sideB));
}

template <typename T, typename U> 
requires Armored<T> && Armored<U>
constexpr void run(Encounter<T, U> encounter) {
    T& A = encounter.sideA;
    U& B = encounter.sideB;
	if (A.getStrength() > B.getStrength()) {
	    auto value = B.pay();
	    SafeTreasure<decltype(value)> treasure(value);
	    A.loot(std::move(treasure));
	}
	if (A.getStrength() < B.getStrength()) {
	    auto value = A.pay();
	    SafeTreasure<decltype(value)> treasure(value);
	    B.loot(std::move(treasure));
	}
}

template <typename T, typename U>
requires Armored<T> && Unarmored<U>
constexpr void run(Encounter<T, U> encounter) {
    T& A = encounter.sideA;
    U& B = encounter.sideB;
	auto value = B.pay();
	SafeTreasure<decltype(value)> treasure(value);
	A.loot(std::move(treasure));
}

template <typename T, typename U>
requires Unarmored<T> && Armored<U>
constexpr void run(Encounter<T, U> encounter) {
    T& A = encounter.sideA;
    U& B = encounter.sideB;
	auto value = A.pay();
	SafeTreasure<decltype(value)> treasure(value);
	B.loot(std::move(treasure));
}

template <typename T, typename U>
requires Unarmored<T> && Unarmored<U>
constexpr void run([[maybe_unused]]Encounter<T, U> encounter) {
	return;
}

/* ***** FUNKCJA EXPEDITION  ***** */
constexpr void expedition(void) {
	return;
}

template<typename T, typename... Args>
requires isEncounter<T> 
constexpr void expedition(T t, Args... args) {
	run(t);
	expedition(args...);
}

#endif /* TREASURE_HUNT_H */