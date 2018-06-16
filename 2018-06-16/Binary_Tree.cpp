#include<iostream>
#include<algorithm>
using namespace std;

int nil=-1;

struct Node{
	int parent,left,right;
};

Node T[10000];
int Depth[10000],Height[10000];

void setDepth(int u,int d){
	if(u==nil) return;
	Depth[u]=d;
	setDepth(T[u].left,d+1);
	setDepth(T[u].right,d+1);
}

int setHeight(int u){
	int h1,h2;
	h1=h2=0;
	if(T[u].left!=nil){
		h1= setHeight(T[u].left)+1;
	}
	if(T[u].right!=nil){
		h2=setHeight(T[u].right)+1;
	}
	Height[u]=max(h1,h2);
	return Height[u];
}

int getSibling(int u){
	if(T[u].parent==nil) return nil;
	if(T[T[u].parent].left!=u && T[T[u].parent].left!=nil){
		return T[T[u].parent].left;
	}
	if(T[T[u].parent].right!=u && T[T[u].parent].right!=nil){
		return T[T[u].parent].right;
	}
	return nil;
}

int degree(int u){
	int deg=0;
	if(T[u].left!=nil) deg++;
	if(T[u].right!=nil) deg++;
	return deg;
}

void print(int u){
	cout<<"node "<<u<<": ";
	cout<<"parent = "<<T[u].parent<<", ";
	cout<<"sibling = "<<getSibling(u)<<", ";
	cout<<"degree = "<<degree(u)<<", ";
	cout<<"depth = "<<Depth[u]<<", ";
	cout<<"height = "<<Height[u]<<", ";
	if(T[u].parent==nil) cout<<"root"<<endl;
	else if(T[u].left==nil && T[u].right==nil) cout<<"leaf"<<endl;
	else cout<<"internal node"<<endl;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) T[i].parent=nil;
	int u,l,r;
	for(int i=0;i<n;i++){
		cin>>u>>l>>r;
		T[u].left=l;
		T[u].right=r;
		if(l!=nil) T[l].parent=u;
		if(r!=nil) T[r].parent=u;
	}
	int root;
	for(int i=0;i<n;i++) if(T[i].parent==nil) root=i;

	setDepth(root,0);
	setHeight(root);

	for(int i=0;i<n;i++) print(i);

	return 0;


}

