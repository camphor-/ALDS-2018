# 螺旋本輪読会 第6回
担当: ishiy
範囲: 第9章 二分探索木、第10章 ヒープ

## 第9章 二分探索木
二分探索木とは、二分探索条件を満たす木のことである

二分探索条件:

  ある節点xに対し、xの左部分木の任意の節点をy、xの右部分木の任意の節点をzとしたとき、
  - yのキー <= xのキー
  - xのキー <= zのキー
  が常に成り立つ

ざっくりいうと、
注目点のキーより
- 小さいものを探すのなら左へ
- 大きいものを探すのなら右へ
いけ!!!
というデータ構造

特徴:
- 平衡(バランスがよい)であれば、効率よく挿入、探索、削除が行える
- 辞書、優先度付きキューの実装として使用できる

### 挿入
[ALDS1_8_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_A&lang=jp)

- 木の高さを `h` とすると `O(h)`

### 探索
[ALDS1_8_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_B&lang=jp)

- 木の高さを `h` とすると `O(h)`

### 削除
[ALDS1_8_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_8_C&lang=jp)

- 木の高さを `h` とすると `O(h)`

### おまけ: setとmap
#### set
集合とも呼ばれる

- 要素に順番はない
- 要素に重複がない

重複の削除やフラグ管理で使用できる

#### map
辞書、連想配列とも呼ばれる

- キーと値のペアの集まり
- キーに重複はない

## 第10章 ヒープ
### 完全二分木
[ALDS1_9_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_A&lang=jp)

- すべての葉が同じ深さを持つ二分木
- 節点がn個である完全二分木の高さは log(n)

- この問題の題意が不明
- 二分ヒープという語を乱用している感じがする

### 最大・最小ヒープ
[ALDS1_9_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_B&lang=jp)

- ある条件を満たす完全二分木

- maxヒープ条件: 節点のキーがその親のキー以下である
- minヒープ条件: 節点のキーがその親のキー以上である

maxヒープ条件を満たすものを、最大ヒープ
minヒープ条件を満たすものを、最小ヒープ
と呼ぶ

特徴:
- 最大 (最小) 要素へのアクセスが `O(1)`

### 優先度付きキュー
[ALDS1_9_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C&lang=jp)

- キーが大きい (小さい) ものから順に出てくるキュー
