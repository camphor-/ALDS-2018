#include <iostream>
#include<cstdio>
using namespace std;

// Aにkeyがあるなら1，ないなら0を返す
int search(int A[],int n,int key){
  A[n] = key;

  int i=0;
  while(A[i]!=key){
    i++;
  }
  return i!=n;
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
    if(search(S,n,t)){
      sum++;
    }
  }
  printf("%d\n",sum);

}
