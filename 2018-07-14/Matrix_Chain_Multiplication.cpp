#include<iostream>
#include<map>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
typedef long long ll;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define Rep(i,n) REP(i,0,n)
ll longinf=1ll<<60;

ll n,p[101],m[101][101];
int main(){
    cin>>n;
    Rep(i,n){
        cin>>p[i]>>p[i+1];
    }
    REP(i,1,n+1) m[i][i]=0; //i番目からi番目までの行列の積の計算回数は0
    REP(len,2,n+1){ //行列積の長さでループ
        REP(i,1,n-len+2){ //積の最初の添字
            int j=i+len-1; //積の最後の添字
            m[i][j]=longinf; //無限大の値で初期化
            REP(k,i,j+1){
                m[i][j]=min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout<<m[1][n]<<endl;
    return 0;
}