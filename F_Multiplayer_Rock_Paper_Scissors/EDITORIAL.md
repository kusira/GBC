$f(g, c, p)$ を、グーが $g$ 人、チョキが $c$ 人、パーが $p$ 人のときの勝ち手（引き分けなら $D$）を返す関数とします。この関数自体は $O(1)$ で計算できます。

クエリ $i$ について、$L_i, \ldots, R_i$ 番目の人のうち、グーを出した人の人数を $g$、チョキを出した人の人数を $c$、パーを出した人の人数を $p$ とします。

あなたがグーを出したときに大人数じゃんけんに勝てるかどうかを考えます。このとき、$f(g + 1, c, p)$ が $G$ ならば勝つことができます。なぜならば、$L_i, \ldots, R_i$ 番目の人とあなたのうち、グーを出した人の人数は $g + 1$ 人で、チョキ・パーを出した人の人数はそれぞれ $c$、$p$ だからです。
同様に、$f(g, c + 1, p)$ が $C$ ならばチョキを出したときに勝つことができ、$f(g, c, p + 1)$ が $P$ ならばパーを出したときに勝つことができます。

これより、$L_i, \ldots, R_i$ 番目の人のうち、グー・チョキ・パーをそれぞれ出す人の人数を高速にもとめられればこの問題を解くことができます。これは累積和を使うことで $O(1)$ で求めることができます。

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<char> A(N);
    for (auto &a : A) cin >> a;

    vector<int> G(N + 1), C(N + 1), P(N + 1);
    for (int i = 0; i < N; i++) {
        if (A[i] == 'G') G[i + 1]++;
        if (A[i] == 'C') C[i + 1]++;
        if (A[i] == 'P') P[i + 1]++;
    }
    for (int i = 0; i < N; i++) {
        G[i + 1] += G[i];
        C[i + 1] += C[i];
        P[i + 1] += P[i];
    }

    // グーがg人、チョキがc人、パーがp人のときの勝ち手　引き分けならD
    auto win_hand = [](int g, int c, int p) -> char {
        if (g == 0 && c == 0) return 'P';
        if (g == 0 && p == 0) return 'C';
        if (c == 0 && p == 0) return 'G';
        if (g == 0) {
            if (c <= p) return 'C';
            else return 'P';
        }
        if (c == 0) {
            if (p <= g) return 'P';
            else return 'G';
        }
        if (p == 0) {
            if (g <= c) return 'G';
            else return 'C';
        }
        if (g < c && g < p) return 'G';
        if (c < g && c < p) return 'C';
        if (p < g && p < c) return 'P';
        if (g == c && g < p) return 'G';
        if (g == p && g < c) return 'P';
        if (c == p && c < g) return 'C';
        return 'D';
    };

    int Q; cin >> Q;
    while (Q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int g = G[r + 1] - G[l];
        int c = C[r + 1] - C[l];
        int p = P[r + 1] - P[l];
        vector<char> ans;
        if (win_hand(g + 1, c, p) == 'G') ans.push_back('G');
        if (win_hand(g, c + 1, p) == 'C') ans.push_back('C');
        if (win_hand(g, c, p + 1) == 'P') ans.push_back('P');

        if (ans.empty()) {
            cout << -1 << endl;
        } else {
            for (int i = 0; i < (int)ans.size(); i++) {
                cout << ans[i] << (i == (int)ans.size() - 1 ? "\n" : " ");
            }
        }
    }
}
```