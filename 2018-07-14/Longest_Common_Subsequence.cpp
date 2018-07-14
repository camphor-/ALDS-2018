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

int q;
string X,Y;

int main(){
    cin>>q;
    Rep(i,q){
        cin>>X>>Y;
        X= ' '+X; //X[0]=' 'とする
        Y= ' '+Y; //Y[0]=' 'とする
        int m,n;
        int maxl=0;
        m=X.size();
        n=Y.size();
        int c[m+3][n+3]; //c[i][j]でX(長さiまで)とY(長さjまで)の共通部分列の最大の長さ(=c[i][j])を保持する配列
        Rep(j,m)Rep(k,n) c[j][k]=0; //0で初期化
        REP(j,1,m){
            REP(k,1,n){
                if(X[j]==Y[k]) c[j][k]=c[j-1][k-1]+1; //X[j]とY[k]が一致したら1足す
                else c[j][k]=max(c[j-1][k],c[j][k-1]); //そうでなければそのまま
                maxl=max(maxl,c[j][k]); //最大値を保持
            }
        }
        cout<<maxl<<endl;
    }
    return 0;
}