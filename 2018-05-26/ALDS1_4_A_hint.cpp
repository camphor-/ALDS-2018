#include <iostream>
#include<cstdio>
using namespace std;

// Aにkeyがあるなら1，ないなら0を返す
int search(int A[],int n,int key){
  // TODO
  // 番兵を使って書き換える
  A[n] = key;
  for(int i=0;i<n;i++){
    if(A[i]==key){
      return 1;
    }
  }
  return 0;
}

int main(){
  int n,q;
  scanf("%d",&n);
  int S[n+1];
  for(int i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int t;
  int sum=0;
  for(int i=0;i<q;i++){
    scanf("%d",&t);
    // TODO
  }
  printf("%d\n",sum);

}
