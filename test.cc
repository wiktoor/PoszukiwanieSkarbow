#include <bits/stdc++.h>
#include "treasure.h"
using namespace std;

int main() {
    static_assert(numeric_limits<int16_t>::is_integer);

    int x = 5;
    Treasure<int, true> t(x);
    SafeTreasure<int> s(x);
    cout << t.isTrapped << endl;

    long long z = 5;
    Treasure<long long, false> r(z);
    TrappedTreasure<long long> v(z);
    cout << v.isTrapped << endl;

    //double y = 5;
    //SafeTreasure<double> u(y);
}