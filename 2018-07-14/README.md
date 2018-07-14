# 螺旋本輪読会 第7回
担当: shinohara

範囲: 第11章 動的計画法 (第17章動的計画法)

## 第11章 動的計画法
動的計画法は、一度計算した結果を記録して、同じ計算を繰り返し行う無駄を避けて、それらを再利用して効率化を図る手法のひとつ

- 漸化式を立てる
- ~~難しい~~

### フィボナッチ数列  
[ALDS1_10_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A&lang=jp)

- みんな大好きフィボナッチ数列
- 関数で定義すると`O(fib(n))`よりは大きい(ほんまか？)
- 計算結果を配列に記憶させておくと`O(n)`

### 部分和問題
[ALDS1_5_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=jp)

- 素直に全探索すると`O(2^n)`
- 和の値ごとに記録しておくと`O(n*max(m_i))`

### 最長共通部分列
[ALDS1_10_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=jp)

- 共通部分列の最大の長さを求める

### 連鎖行列積
[ALDS1_10_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=jp)

- 行列積の最小の計算回数を求める

## 第17章 動的計画法

動的計画法を用いる代表的な問題たちを紹介

### コイン問題
[DPL_1_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=jp)

- n円払うための最小のコイン枚数を求める

### 0-1ナップザック問題
[DPL_1_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp)

- みんな大好きナップザック問題
- 価値と重さを持つ品物たちから一定の重さを超えずかつ価値が最大となるように品物を選ぶか選ばないかを決める
- 同じ品物は最大1つまでしか選べない

### ナップザック問題
[DPL_1_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=jp)

- 同じ品物を複数選べるタイプ


### 最小増加部分列
[DPL_1_D](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp)

- 与えられた数列の最長の増加部分列の長さを求める
- 二分探索と動的計画法の合わせ技

お疲れ様でした