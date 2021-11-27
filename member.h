#ifndef MEMBER_H
#define MEMBER_H

#include <numeric>
#include <concepts>
#include "treasure.h"

using IsArmed = bool;
using strength_t = size_t;
using CompletedExpeditions = size_t;

template<typename T, typename IsArmed armed>
requires ValueType<T> 
class Adventurer {
	private:
		T treasure;
		IsArmed isArmed = armed;
		strength_t strength;
	public:
		constexpr Adventurer<T, false>() : treasure(0), strenght(0) {}
		constexpr Adventurer<T, true>(strengh_t strength) : treasure(0), strenght(strenght) {}
		constexpr strength_t getStrenght<T, true>() {
			return strength;
		}
		constexpr bool isArmed() {
			return isArmed;
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
}

template<typename T> requires ValueType<T> 
using Explorer = Adventurer<T, false>;

templete<typename T, typename CompletedExpeditions N>
requires ValueType<T> && N < 25
class Veteran {
	private:
		T treasure;
		IsArmed isArmed;
		CompletedExpeditions n = N;
	public: 
		constexpr Veteran {

		}
}


#endif