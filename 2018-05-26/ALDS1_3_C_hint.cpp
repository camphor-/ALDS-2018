#include <iostream>
using namespace std;

struct Node{
  int key;
  Node *prev;
  Node *next;
};

Node *NIL;

// 空のリストとして番兵を作る．
void init(){
  NIL = (Node*)malloc(sizeof(Node));
  NIL->prev = NIL;
  NIL->next = NIL;
}

// keyをキーとして持つノードを作る．
void insert(int key){
  Node *x = (Node*)malloc(sizeof(Node));
  // 番兵の直後に要素を追加
  // TODO
}

// 全ノードを出力
void printList(){
  Node *cur = NIL->next;
  int isf = 0;
  while(cur != NIL){
    if(isf++ > 0){
      printf(" ");
    }
    printf("%d",cur->key);
    cur = cur->next;
  }
  printf("¥n");
}

// keyをキーとして持つノードを探す
Node* listSearch(int key){
  // 番兵の次の要素からnextをたどる
  // TODO
}

void deleteNode(Node *t){
  // tが番兵の場合は処理しない
  if(t == NIL){
      return;
  }
  // tの前後のノードをつなぐ
  // TODO
  // メモリから開放
  free(t);
}

// keyをキーとして持つノードを削除する
void deleteKey(int key){
  // TODO
}

int main(){
  int n;
  scanf("%d",%n);
  char command[10];
  int key;
  init();
  for(int i=0;i<n;i++){
    // 高速な入力関数を使用
    scanf("%s%d",command,&key);
    if(command[0] == 'i'){
      // TODO
    }
    else{
      // TODO
    }
  }
  printList();
  return 0;
}
