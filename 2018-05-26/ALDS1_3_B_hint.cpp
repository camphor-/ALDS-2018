#include <iostream>
using namespace std;
#define LEN 100005

// プロセスを表す構造体
struct Process {
  char name[100];
  int t;
};

// データを格納する配列
Process Q[LEN];
int head = 1;
int tail = 1;
int n;

// tailの位置にxを追加する
void enqueue(Process x){
  // tailの位置に追加して，tailを増やす
  // TODO
}

// headの位置の要素を取り出す
Process dequeue(){
  // headが指していた要素を返す
  // TODO
}

int isEmpty(){
  return head == tail;
}

int main(){
  int n;
  int q;
  cin >> n >> q;
  Process p;

  // 全てのプロセスをキューに順番に追加する
  for(int i=1;i<=n;i++){
    cin >> p.name >> p.t;
    // TODO
  }

  int elaps = 0;
  while(!isEmpty()){
    // TODO
    // キューから取り出す
    // qまたはu.tだけ処理を行う
    // 残りの必要時間を計算
    // 経過時間を加算
    // 処理が完了していなければキューに追加
  }

  return 0;
}
