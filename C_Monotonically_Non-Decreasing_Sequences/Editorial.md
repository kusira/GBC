# 解説
この問題はつまり、「列 $A$ を単調非減少に並べ替える方法は何通りあるだろうか？」ということです。  

列 $A$ を適当にソートすると、単調非減少となる並べ替えが一つ得られます。  
このとき、値が同じ $2$ 要素を自由に交換しても、列 $A$ が単調非減少であるという条件は満たされ続けます。  

したがって、$A$ に属する要素の値ごとに、何通りの並べ替えが許されるかを調べ、それらをすべて掛け合わせたものを答えればよいです。

$n \scriptsize \; (n \in \Z^+_0)$ 個の (互いに区別できる) モノを一列に並べる方法が $n!$ 通りであることを踏まえると、結局、この問題の答えは以下の値に一致します：
- $\displaystyle \prod_x \mathrm{count}(x)!$
    - ただし，任意の数 $x$ について $\mathrm{count}(x) = |\{\, k \;\colon A_k = x \,\}|$ を満たす。

なお、これは、$A$ が左から右へ一列に並んでいるとして、「各要素を『自分より左にある要素であって、自分自身と値が等しいもの』と交換できる」と考えるとスムーズかもしれません。(次項の実装例はこの考えに基づいています。)

解説：uni_kakurenbo

# 実装例
```cpp:C++
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

```
