#include <bits/stdc++.h>
#include "treasure.h"
#include "member.h"
#include "treasure_hunt.h"
using namespace std;

template <typename T>
requires isAdventurer<T>
void tryAdventurer(T a) {
    cout << "test " << a.isArmed << endl;
}

int main() {
    static_assert(numeric_limits<int16_t>::is_integer);

    int x = 5;
    Treasure<int, true> t(x);
    SafeTreasure<int> s(x);
    cout << t.isTrapped << endl;
    cout << t.evaluate() << endl;
    cout << t.getLoot() << endl;
    cout << t.evaluate() << endl;

    long long z = 5;
    Treasure<long long, false> r(z);
    TrappedTreasure<long long> v(z);
    cout << v.isTrapped << endl;

    strength_t strength = 42;

    Adventurer<int, true> a(strength);
    cout << a.isArmed << endl;
    cout << a.getStrength() << endl;

    tryAdventurer(a);
    //tryAdventurer(t);

    //double y = 5;
    //SafeTreasure<double> u(y);
}