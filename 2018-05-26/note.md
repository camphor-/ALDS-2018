# 競技プログラミング輪読会
## 今日の進め方
- 担当: @shiba6v
- 説明と演習を何回か繰り返して進めます
  - 説明
    - 知ってるよ，という人は先に問題を解いていてもOKです
    - 分からなくなったら，いつでも止めて質問してください (xxが分からない，という漠然とした質問でもOK)
    - 作ってきたノートとAOJのNoteを参照します
  - 演習
    - 参考実装はC++で，実装例は教科書に近いコードにします．
    - 別言語でやってもOKですが，ポインタを使ってスタック，キュー，リストを実装するのでC++をおすすめします
    - 穴埋め形式にしたコードと実装例を提供します．
    - 穴埋めにしたコードはできるだけC++を知らなくてもできるようにしてあります．
    - わからない人はpaiza.ioを使ってコンパイルするのをおすすめします．

## データ構造
- 集合
  - データが配列や構造体に入っている．
- 規則
  - データの挿入，取り出しなどのデータ管理の決まり
- 操作
  - 挿入，取り出し，空かどうか調べる，要素数を調べるなど

## スタック
スタック作ったことありますか
### 規則
![stack](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)
- LIFO (last in first out)
  - 最後に入れたものが最初に出てくる
### 操作
  - push
  - pop
  - isEmpty
  - isFull

### 演習
[ALDS1_3_A](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_A&lang=jp)

### 逆ポーランド記法
- 数字ならスタックにpushする
- +ならスタックから2つpopして足した値をpushする
- 他の演算子も同じ
- これらの操作を1シンボル読む度に行えば，最後は数字が一つになる

### スタックの実装
- top
- push
- pop
- ドット演算子(.)はメンバ変数を呼び出す

## キュー
### 規則
![queue](https://upload.wikimedia.org/wikipedia/commons/5/52/Data_Queue.svg)
- FIFO (first in first out)
  - 最初に入れたものが最初に出てくる
### 操作
  - enqueue
  - dequeue
  - isEmpty
  - isFull

### 演習
[ALDS1_3_B](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B&lang=jp)

### キューの実装
- head
- tail
- enqueue
- dequeue
- リングバッファ

## 双方向リスト
### 規則
- 配列とは異なり，要素の挿入・削除がO(1)で行える．
- key
- next,prev
![Node](https://upload.wikimedia.org/wikipedia/commons/5/5e/Doubly-linked-list.svg)
- 番兵
  - リストの先頭を指す特別なノード
  - 初期化時に空のリストとして作る
  - アロー演算子(->)は，ポインタからメンバ変数を呼び出す

### 操作
- insert
  - リストの先頭への挿入
- listSearch
- deleteNode
### 演習
[ALDS1_3_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_C&lang=jp)

### 双方向リストの実装
- Node
- insert
- listSearch
- deleteNode
- その他delete系
  - deleteFirst
  - deleteLast
  - deleteKey
- printList
