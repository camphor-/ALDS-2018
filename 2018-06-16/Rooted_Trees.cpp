#include<iostream>
#include<algorithm>
using namespace std;

int nil =-1;

struct Node {
	int parent, left_child, right_sibling;
};
// parentで節点の親を参照　
// left_childで節点の一番左の子を参照
// right_sibilingで節点の一番右の兄弟を参照


Node T[100005];
int Depth[100005];

void print(int u){
	cout<<"node "<<u<<": ";
	cout<<"parent = "<<T[u].parent<<", ";
	cout<<"depth = "<<Depth[u]<<", ";

	if(T[u].parent==nil) cout<<"root, ";
	else if(T[u].left_child==nil) cout<<"leaf, ";
	else cout<<"internal node, ";

	cout<<"[";
	int child=T[u].left_child;
	while(child!=nil){
		cout<<child;
		child=T[child].right_sibling;
		if(child!=nil) cout<<", ";
	}
	cout<<"]"<<endl;
}

void setdepth(int u,int p){
	Depth[u]=p;
	if(T[u].right_sibling!=nil) setdepth(T[u].right_sibling,p);
	if(T[u].left_child!=nil) setdepth(T[u].left_child,p+1);
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) T[i].parent = T[i].left_child = T[i].right_sibling = nil;

	int u,m,child,right;
	for(int i=0;i<n;i++){
		cin>>u>>m;
		for(int j=0;j<m;j++){
			cin>>child;
			if(j==0) T[u].left_child=child;
			else T[right].right_sibling=child;
			right=child; //一番右のchildを保持
			T[child].parent=u; //節点uの子の親はu
		}
	}

	int root;
	for(int i=0;i<n;i++){
		if(T[i].parent==nil) root=i; //iの親がnilならiがroot
	}

	setdepth(root,0);

	for(int i=0;i<n;i++) print(i);

	return 0;
}
