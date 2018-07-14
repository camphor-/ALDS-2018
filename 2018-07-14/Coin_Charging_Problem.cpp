#include<iostream>
#include<map>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
#define REP(i,b,e) for(int i=(int)b;i<(int)e;i++)
#define Rep(i,n) REP(i,0,n)
typedef long long ll;
int inf=1<<30;

int n,m;
int c[23]; //c[i]:=i番目のコインの額面
int T[50001]; //T[j]:=j円支払うときの最小枚数

int main(){
    cin>>n>>m;
    Rep(i,m) cin>>c[i];
    Rep(i,n+1) T[i]=inf;
    T[0]=0;
    Rep(i,m){
        Rep(j,n+1-c[i]){
            T[j+c[i]]=min(T[j+c[i]],T[j]+1);
        }
    }
    cout<<T[n]<<endl;

    return 0;
}