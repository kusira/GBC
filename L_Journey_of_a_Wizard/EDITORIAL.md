$f(x) = \begin{cases} x \div 2 & xが偶数 \\ x \times 2 & xが奇数\end{cases}$ 　とします。

$4N$ の頂点 $x_1, \ldots, x_N, y_1, \ldots, y_N, z_1, \ldots, z_N, w_1, \ldots, w_N$ を用意します。

まず道$i = (a_i, b_i, c_i)~(i = 1, \ldots, M)$ について、以下のように辺を張ります。

- $x_{a_i} \to x_{b_i}$ に重み $c_i$ の辺
- $y_{b_i} \to y_{a_i}$ に重み $c_i$ の辺
- $z_{a_i} \to z_{b_i}$ に重み $f(c_i)$ の辺
- $w_{b_i} \to w_{a_i}$ に重み $f(c_i)$ の辺

さらに、

$i = 1, \ldots, N$ について、

- $x_i \to y_i$ に重み $X$ の辺
- $x_i \to z_i$ に重み $Y$ の辺
- $y_i \to z_i$ に重み $Y$ の辺
- $z_i \to w_i$ に重み $X$ の辺

を張ります。

このグラフに対して、辺の張り方より以下が成り立ちます:
- $\{x_1, \ldots, x_N \}$ の誘導部分グラフは、魔法を使っていないときの国のグラフと一致する
- $\{y_1, \ldots, y_N \}$ の誘導部分グラフは、魔法1を使ったときの国のグラフと一致する
- $\{z_1, \ldots, z_N \}$ の誘導部分グラフは、魔法2を使ったときの国のグラフと一致する
- $\{w_1, \ldots, w_N \}$ の誘導部分グラフは、魔法1と魔法2を使ったときの国のグラフと一致する

魔法を一度も使っていない状態で頂点 $i$ にいて、魔法1を使うことを考えます。
魔法を一度も使っていない状態は、今考えているグラフで $x_i$ にいることに対応します。
魔法1を使うと、今考えているグラフで $y_i$ にいることに対応します。

つまり、「魔法を一度も使っていない状態で頂点 $i$ にいて、魔法1を使う」は、「$x_i \to y_i$ の重み $X$ の辺を通る」ことに対応します。
同様のことが $x_i \to z_i, y_i \to z_i, z_i \to w_i$ の辺についても言えます。

よって、このグラフについて $x_1$ からスタートし、$x_N, y_N, z_N, w_N$ まで移動するときの最短時間をそれぞれダイクストラ法を用いて計算し、そのうち最小のものが答えになります。

```rust
use proconio::{input, marker::Usize1};

#[derive(Debug, Clone, Copy)]
struct Edge {
    to: usize,
    cost: usize,
}

fn main() {
    input! {
        n: usize,
        m: usize,
        x: usize,
        y: usize,
        edges: [(Usize1, Usize1, usize); m],
    }

    let magic2 = |cost| if cost % 2 == 0 { cost / 2 } else { cost * 2 };

    // 頂点 i を 4 * i, 4 * i + 1, 4 * i + 2, 4 * i + 3 として、
    // それぞれ 魔法を使っていない、魔法1のみ使った、魔法2のみ使った、両方使った ときのグラフを作る
    let mut graph = vec![vec![]; 4 * n];
    for &(a, b, c) in &edges {
        graph[4 * a].push(Edge { to: 4 * b, cost: c });
        graph[4 * b + 1].push(Edge { to: 4 * a + 1, cost: c });
        graph[4 * a + 2].push(Edge { to: 4 * b + 2, cost: magic2(c) });
        graph[4 * b + 3].push(Edge { to: 4 * a + 3, cost: magic2(c) });
    }
    // 魔法を使ったときの辺を追加
    for i in 0..n {
        graph[4 * i].push(Edge { to: 4 * i + 1, cost: x });
        graph[4 * i].push(Edge { to: 4 * i + 2, cost: y });
        graph[4 * i + 1].push(Edge { to: 4 * i + 3, cost: y });
        graph[4 * i + 2].push(Edge { to: 4 * i + 3, cost: x });
    }

    // 頂点 0 からDijsktra, 4 * (n - 1), 4 * (n - 1) + 1, 4 * (n - 1) + 2, 4 * (n - 1) + 3 への最短距離のうち最小のものが答え
    let mut dist = vec![std::usize::MAX; 4 * n];
    let mut heap = std::collections::BinaryHeap::new();
    dist[0] = 0;
    heap.push(std::cmp::Reverse((0, 0)));
    while let Some(std::cmp::Reverse((cost, v))) = heap.pop() {
        if dist[v] < cost {
            continue;
        }
        for &Edge { to, cost: c } in &graph[v] {
            if dist[to] > dist[v] + c {
                dist[to] = dist[v] + c;
                heap.push(std::cmp::Reverse((dist[to], to)));
            }
        }
    }

    let ans = *dist[4 * (n - 1)..4 * n].iter().min().unwrap();
    println!("{}", if ans == std::usize::MAX { -1 } else { ans as i32 });
}
```