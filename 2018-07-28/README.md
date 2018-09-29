# 螺旋本輪読会 第8回
担当: ishiy

範囲: 第12章 グラフ、第13章 重み付きグラフ

## 第12章 グラフ
頂点(ノード)と辺(エッジ)からなるデータ構造
- 無向グラフ
- 有向グラフ
- 重み付き無向グラフ
- 重み付き有向グラフ

ある2頂点間に辺があるとき、この2頂点は隣接しているという。
隣接している頂点の列をパスという。
始点と終点が同じパスを閉路という。
閉路のない有向グラフをDirected Acyclic Graph(DAG)という。

ある頂点につながっている辺の数をその頂点の次数という。

2つのグラフGとG'について、G'の頂点集合と辺集合の両方がGの頂点集合と辺集合の部分集合となっているとき、G'をGの部分グラフという。

### グラフの表現
[ALDS1_11_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_A&lang=jp)

- 隣接リスト表現: 各頂点に対して隣接する頂点のリストを保持する
  - ノード数x辺の数のメモリが必要
- 隣接行列表現: ある2つの頂点間に辺が存在するかを保持する
  - ノード数の2乗のメモリが必要
  - 頂点間の関係を定数時間で判定できる
  - 双方向が表現できない (?)

### 深さ優先探索
[ALDS1_11_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B&lang=jp)

実装:
- 再帰呼び出し
- スタック

### 幅優先探索
[ALDS1_11_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=jp)

- キューを使って実装できる

### 連結成分
[ALDS1_11_D](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=jp)

グラフの任意の2頂点に対して、片方からもう片方へのパスが存在するとき、そのグラフは連結であるという。

DFS を使って実装する

## 第13章 重み付きグラフ
### 最小全域木
[ALDS1_12_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A&lang=jp)

グラフの全域木とは、グラフの全ての頂点を含む部分グラフであり、木である限りできるだけ多くの辺を持つものである。
あるグラフに対して複数の全域木が存在しうる。

最小全域木とは、グラフの全域木のなかで、辺の重みの総和が最小のものである。

プリムのアルゴリズム
1. グラフから任意の頂点を選び、木のルートとする
2. 木に属する頂点から木に属していない頂点への辺のうち重さが最小のものを選びその頂点を木に追加する

See: クラスカルのアルゴリズム ([GRL_2_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp))

### 単一始点最短経路
[ALDS1_12_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B&lang=jp)

ダイクストラのアルゴリズム
- 候補の頂点のなかで最も近いものをとる
- 候補の頂点とそこまでの距離を更新する

注意
- ダイクストラのアルゴリズムは負の重みをもつグラフには適用できない
- 負の重みをもつグラフに対しては、ベルマンフォードのアルゴリズムやワーシャルフロイドのアルゴリズムを適用する
