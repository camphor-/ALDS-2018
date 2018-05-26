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

void insert(int key){
  Node *x = (Node*)malloc(sizeof(Node));
  // 番兵の直後に要素を追加
  x->next = NIL->next;
  x->prev = NIL;
  x->key = key;
  NIL->next->prev = x;
  NIL->next = x;
}

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

Node* listSearch(int key){
  // 番兵の次の要素からたどる
  Node *cur = NIL->next;
  while(cur != NIL && cur->key != key){
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node *t){
  // tが番兵の場合は処理しない
  if(t == NIL){
      return;
  }
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteKey(int key){
  deleteNode(listSearch(key));
}

int main(){
  int n;
  scanf("%d",&n);
  char command[10];
  int key;
  init();
  for(int i=0;i<n;i++){
    // 高速な入力関数を使用
    scanf("%s%d",command,&key);
    if(command[0] == 'i'){
      insert(key);
    }
    else{
      deleteKey(key);
    }
  }
  printList();
  return 0;
}
