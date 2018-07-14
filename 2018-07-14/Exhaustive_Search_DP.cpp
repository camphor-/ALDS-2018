#include<iostream>
#include<map>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
#define REP(i,b,e) for(int i=(int)b;i<(int)e;i++)

int n,A[50];

bool dp[30][2018]; //dp[i][j]でi番目まで使ってjを作れるかのbool値を返す

int main(){
    cin>>n;
    REP(i,1,n+1) cin>>A[i];
    REP(i,0,n+1) dp[i][0]=true; //i番目まで使って0は作れるのでtrue
    REP(i,0,n+1){
        REP(j,0,2001){
            if(j+A[i]<=2000&&dp[i][j]){
                dp[i+1][j+A[i+1]]=dp[i+1][j]=true; //i番目まで使ってjが作れるならi+1番目まで使ってj+A[i+1]とjが作れる
            }
            else if(dp[i][j]) dp[i+1][j]=true; //j+A[i]>2000のときは考えない
        }
    }
    int q,m;
    cin>>q;
    REP(i,0,q){
        cin>>m;
        if(dp[n][m]) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}