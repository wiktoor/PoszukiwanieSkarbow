
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

template<typename T>
requires EncounterSide<T>
void tryEncounterSide(T a) {

}

int main() {
    static_assert(numeric_limits<int16_t>::is_integer);

    int x = 5;
    Treasure<int, false> t(x);
    SafeTreasure<int> s(x);
    cout << t.isTrapped << endl;
    cout << t.evaluate() << endl;
    cout << t.getLoot() << endl;
    cout << t.evaluate() << endl;

    SafeTreasure<int> u = { 5 };

    long long z = 5;
    Treasure<long long, false> r(z);
    TrappedTreasure<long long> v(z);
    cout << v.isTrapped << endl;

    Adventurer<int, true>::strength_t strength = 42;

    Adventurer<int, true> a(strength);
    cout << a.isArmed << endl;
    cout << a.getStrength() << endl;

    Adventurer<int, false> b;
    Adventurer<int, true> c(strength);
    Adventurer<int, false> d;

    Veteran<int, 5> w;

    tryAdventurer(a);
    tryAdventurer(b);
    //tryAdventurer(s);

    tryEncounterSide(a);
    tryEncounterSide(s);

    Encounter<decltype(b), decltype(s)> encounter1 = {b, s};
    Encounter<decltype(a), decltype(b)> encounter2 = {a, b};

	expedition(encounter1, encounter2);

    cout << a.pay() << endl;
    cout << b.pay() << endl;


    //double y = 5;
    //SafeTreasure<double> u(y);
}