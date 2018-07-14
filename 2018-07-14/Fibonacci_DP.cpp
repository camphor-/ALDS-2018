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

int n;
ll fib[100];

int main(){
    cin>>n;
    fib[0]=fib[1]=1;
    Rep(i,n) fib[i+2]=fib[i+1]+fib[i];
    cout<<fib[n]<<endl;
    return 0;
}