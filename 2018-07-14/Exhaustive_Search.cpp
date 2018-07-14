#include<iostream>
#include<map>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
#define Rep(i,n) for(int i=0;i<(int)n;i++)

int n,A[50];

bool solve(int i,int j,int m){
    if(j==m) return true; //和jがmになったらok
    if(i>=n) return false; //添字iがn以上になったらだめ
    return solve(i+1,j,m) || solve(i+1,j+A[i],m); //添字を一つ進めてA[i]を入れる場合と入れない場合で考える
}

int main(){
    int q,m;
    cin>>n;
    Rep(i,n) cin>>A[i];
    cin>>q;
    Rep(i,q) {
        cin>>m;
        if(solve(0,0,m)){
            cout<<"yes"<<endl;
        }
        else cout<<"no"<<endl;
    }
    return 0;
}