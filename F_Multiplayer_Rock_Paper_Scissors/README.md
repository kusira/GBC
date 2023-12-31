# 問題文

$N$ 人の人がいます。$i~(1 \leq i \leq N)$ 番目の人はじゃんけんをするとき、必ず $A_i$ の手を出します。

クエリが $Q$ 個与えられるので、それぞれ答えてください。

- クエリ $i$ : 整数 $L_i, R_i~(1 \leq L_i < R_i \leq N)$ が与えられます。
  $L_i, L_i+1, \ldots, R_i$ 番目の人と**あなた**で大人数じゃんけんをします。ここで、大人数じゃんけんは次のルールで勝敗を決定します。

> - 1人以上が出した手のうち、一番出した人が少ない手が1種類のとき、その手を出した人全員が勝ち、それ以外の人は負ける。
> - 1人以上が出した手のうち、一番出した人が少ない手が2種類のとき、その2種類のうち通常のじゃんけんで勝つ方の手を出した人全員が勝ち、それ以外の人は負ける。
> - 上記以外のとき、全員あいこになる。

  あなたは何の手を出したら勝てますか？勝てる手が存在するならその手をすべて `G`、`C`、`P` の順番で空白区切りで、存在しないなら `-1` を出力してください。

ここで、通常のじゃんけんにおいてグーはチョキに、チョキはパーに、パーはグーにそれぞれ勝つものとします。

# 制約

- $1 \leq N \leq  10^5$
- $A_i~(1 \leq i \leq N)$ は `G`, `C`, `P` のいずれかで、 $i$ 番目の人はじゃんけんをするとき $A_i$ が `G` のときグーを、`C` のときチョキを、`P` のときパーを必ず出すことを表す。
- $1 \leq Q \leq 10^5$
- $1 \leq L_i < R_i \leq N$ 
- 入力はすべて整数。

# 入力

入力は以下の形式で標準入力から与えられる。

```
N
A_1 ... A_N
Q
L_1 R_1
...
L_Q R_Q
```

# 出力

$Q$行出力せよ。 $i$ 行目ではクエリ $i$ に対する答えを出力せよ。

---

# 入出力例1

```入力
10
C C G C P C C G G C
3
1 10
1 7
6 8
```

```出力
P
-1
G P
```

- クエリ1では、グーを3人、チョキを6人、パーを1人出しています。このとき、あなたはパーを出すことで大人数じゃんけんに勝つことができます。それ以外の手を出すと負けてしまいます。
- クエリ2では、グーを1人、チョキを5人、パーを1人出しています。このとき、あなたはどんな手を出しても負けてしまうので、`-1`を出力します。
- クエリ3では、グーを1人、チョキを2人、パーを0人出しています。このとき、あなたはグーを出してもパーを出しても勝つことができます。よって `G` と `P` を出力します。複数勝つ手が存在するとき、`G` `C` `P` の順で空白区切りで出力し、最後に改行してください。

# 入出力例2

```入力
20
C G C C G P C G P C G C G C P C P C P C
10
9 15
7 11
15 19
9 18
15 16
2 7
13 14
5 6
6 17
7 16
```

```出力
-1
-1
G C
-1
-1
P
-1
-1
-1
P
```