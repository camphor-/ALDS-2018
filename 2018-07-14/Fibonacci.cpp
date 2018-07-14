#include<iostream>
#include<map>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
#define REP(i,b,e) for(int i=(int)b;i<(int)e;i++)
typedef long long ll;

ll fib(int n){
    if(n==0||n==1) return 1;
    else return fib(n-1)+fib(n-2);
}

int n;
int main(){
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}