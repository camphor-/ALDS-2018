#include <iostream>
using namespace std;

int top = 0; // 最後の要素の位置
int S[1000]; // Stackのデータ

// topにxを追加する
void push(int x){
  // topを加算してからSのその位置へ挿入
  // TODO
}

// topから要素を取り出す
int pop(){
  //topが指していた要素を返す
  // TODO
}

int main(){
  // 読み込んだ1シンボル(オペランドや演算子)
  char s[100];
  // 計算する時に一時的に使う変数
  int a,b;

  // スペースまで読む．
  // sには12などのオペランドや+などの演算子が入る
  while(cin>>s){
    if(s[0] == '+'){
      // TODO
    }
    else if(s[0] == '-'){
      // TODO
    }
    else if(s[0] == '*'){
      // TODO
    }
    else{
      // TODO
      // スタックにはintしか入れないので
      // atoi(s)でcharの配列をintに変換する必要がある
    }
  }

  // 最後の1シンボルが計算結果になる
  cout << pop() << endl;
  return 0;
}
