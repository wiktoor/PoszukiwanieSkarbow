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
		constexpr Adventurer() requires (armed == false) : treasure(0), strength(0) {}
		constexpr Adventurer(strength_t strength) requires (armed == true): treasure(0), strength(strength) {}
		constexpr strength_t getStrength() requires (isArmed == true) {
			return strength;
		}
		constexpr void loot(Treasure<T, true> &&treasure) {
			if (treasure.isTrapped && isArmed && strength > 0) 
				strength /= 2;
			else
				return;
			this->treasure += treasure.getLoot();
		}
		constexpr void loot(Treasure<T, false> &&treasure) {
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

template<typename T, CompletedExpeditions N>
requires ValueType<T> && (N < 25)
class Veteran {
	private:
		T treasure;
		CompletedExpeditions n = N;
	public: 
		static const IsArmed isArmed = true;
		constexpr Veteran() : treasure(0) {}
		constexpr strength_t getStrength() {
			if (n == 0)
				return 0;
			if (n == 1)
				return 1;
			
			strength_t f2 = 0, f1 = 1, res;
			for (CompletedExpeditions i = 2; i <= n; i++) {
				res = f2 + f1;
				f2 = f1;
				f1 = res;
			}
			return res;
		}
		constexpr void loot(T &&treasure) {
			n++;
			this->treasure += treasure.getLoot();
		}
		constexpr T pay() {
			T result = treasure;
			treasure = 0;
			return result;
		}
	
};


#endif