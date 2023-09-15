
#include <cstdint>
#include <iostream>
#include <valarray>
#include <algorithm>

#include <atcoder/modint>

using i32 = std::int32_t;
using mint = atcoder::modint998244353;

int main() {
    int n; std::cin >> n;
    std::valarray<i32> a(n); for(i32& v : a) std::cin >> v;

    std::sort(std::begin(a), std::end(a));

    mint ans = 1;
    {
        int con = 1;
        i32 prev_v = -1;
        for(const i32 v : a) {
            if(v == prev_v) ++con;
            else con = 1;
            ans *= con;
            prev_v = v;
        }
    }

    std::cout << ans.val() << "\n";

    return 0;
}
