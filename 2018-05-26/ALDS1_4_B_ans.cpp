#include<cstdio>

// Aにkeyがあるなら1，ないなら0を返す
int binarySearch(int A[],int n,int key){
  int left=0;
  int right = n;
  int mid;
  while(left<right){
    mid = (left+right)/2;
    if(key==A[mid]){
      return 1;
    }
    if(key>A[mid]){
      left = mid+1;
    }
    else if(key<A[mid]){
      right = mid;
    }
  }
  return 0;
}

int main(){
  int n,q;
  scanf("%d",&n);
  int S[n];
  for(int i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int t;
  int sum=0;
  for(int i=0;i<q;i++){
    scanf("%d",&t);
    if(binarySearch(S,n,t)){
      sum++;
    }
  }
  printf("%d\n",sum);

}
