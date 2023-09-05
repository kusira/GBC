/*
 * @uni_kakurenbo
 * https://github.com/uni-kakurenbo/competitive-programming-workspace
 *
 * CC0 1.0  http://creativecommons.org/publicdomain/zero/1.0/deed.ja
 */
/* #language C++ GCC */
/* #region template */
#include <bits/stdc++.h>
// using namespace std;

#include "template.hpp"
/* #endregion */

#include "random/generator.hpp"

signed main(const int, const char *argv[]) {
    u32 seed = std::stoi(argv[1]);
    lib::random_engine<std::mt19937> rng(seed);

    const unsigned n = std::stoi(argv[2]);
    const unsigned m = rng(10) == 0 ? n : (1 << (rng(std::bit_width(n) + 1)));
    debug(n, m);

    const int p = rng(1, 30) + 1;
    std::set<i32> st;

    valarray<i32> a(m);
    REP(i, m) {
        do {
            if(m < n) a[i] = rng(1 << (rng(p) + 1));
            else a[i] = rng(1 << 30);
        } while(st.contains(a[i]));
        if(m >= n) st.insert(a[i]);
    }

    valarray<i64> b(n);
    REP(i, n) b[i] = a[lib::mod(i, m)];
    std::shuffle(ALL(b), rng);

    print(n);
    print(b);

    return 0;
}
