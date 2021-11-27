#ifndef MEMBER_H
#define MEMBER_H

#include <numeric>
#include <concepts>
#include <cstdlib>
#include "treasure.h"

using IsArmed = bool;
using strength_t = size_t;
using CompletedExpeditions = size_t;

template<typename T, IsArmed armed>
requires ValueType<T> 
class Adventurer {
	private:
		T treasure;
		strength_t strength;
	public:
		static const IsArmed isArmed = armed;
		constexpr Adventurer() requires (isArmed == false) : treasure(0), strength(0) {}
		constexpr Adventurer(strength_t strength) requires (isArmed == true): treasure(0), strength(strength) {}
		constexpr strength_t getStrength() requires (isArmed == true) {
			return strength;
		}
		constexpr void loot(T &&treasure) {
			if (treasure.isTrapped && isArmed && strength > 0) 
				strength /= 2;
			else
				return;
			this->treasure += treasure.getLoot();
		}
		constexpr T pay() {
			T result = treasure;
			treasure = 0;
			return result;
		}
};

template<typename T> requires ValueType<T> 
using Explorer = Adventurer<T, false>;

/*
template<typename T, CompletedExpeditions N>
requires ValueType<T> && (N < 25)
class Veteran {
	private:
		T treasure;
		IsArmed isArmed;
		CompletedExpeditions n = N;
	public: 
		constexpr Veteran {

		}
};
*/


#endif