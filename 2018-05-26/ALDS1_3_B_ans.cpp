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
  Q[tail] = x;
  tail = (tail+1)%LEN;
}

// headの位置の要素を取り出す
Process dequeue(){
  // headが指していた要素を返す
  Process x = Q[head];
  head = (head+1)%LEN;
  return x;
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
    enqueue(p);
  }

  int elaps = 0;
  while(!isEmpty()){
    Process u = dequeue();
    // qまたはu.tだけ処理を行う
    int diff = min(q,u.t);
    // 残りの必要時間を計算
    u.t -= diff;
    // 経過時間を加算
    elaps += diff;
    // 処理が完了していなければキューに追加
    if (u.t > 0){
      enqueue(u);
    }
    else{
      cout << u.name << " " << elaps << endl;
    }
  }

  return 0;
}
