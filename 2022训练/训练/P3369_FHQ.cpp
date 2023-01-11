#include<bits/stdc++.h>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
const int N=1e5+10;
mt19937 mt_rand(0);
int i,j,k,n,s,t=1,m,root=1;
struct node{
	int key,sz,val;
	int ls,rs;
}a[N];
void push_up(int u){
	a[u].sz=a[a[u].ls].sz+a[a[u].rs].sz+1;
}
void split(int u,int &x,int &y,int k){
	if(!u){x=y=0;return ;}
	if(a[u].val<=k)split(a[x=u].rs,a[u].rs,y,k);
	else split(a[y=u].ls,x,a[u].ls,k);
	push_up(u);
}
int merge(int u,int v){
	//u<=v
	if(!u||!v)return u^v;
	if(a[u].key>a[v].key){
		a[u].rs=merge(a[u].rs,v);
		push_up(u);return u;
	}
	a[v].ls=merge(u,a[v].ls);
	push_up(v);return v;
}
void insert(int x){
	int u,v;
	split(root,u,v,x);
	a[++t]={int(mt_rand()>>1),1,x,0,0};
	root=merge(merge(u,t),v);
}
int get_rank(int k){
	int u,v,res=0;
	split(root,u,v,k-1);
	res=a[u].sz;
	root=merge(u,v);
	return res;
}
int get_val(int k){
	int u=root;
	while(1){
		if(k==a[a[u].ls].sz)return a[u].val;
		if(k<a[a[u].ls].sz+1)u=a[u].ls;
		else k-=a[a[u].ls].sz+1,u=a[u].rs;
	}
}
signed main()
{
	read(n);
	a[1]={2147483647,1,int(-1e9),0,0};
	insert(1e9);
	for(i=1;i<=n;i++){
		int op,k;read(op),read(k);
		if(op==1)insert(k);
		if(op==2){
			int u,v,w;
			split(root,u,v,k);
			split(u,u,w,k-1);
			w=merge(a[w].ls,a[w].rs);
			root=merge(merge(u,w),v);
		}	
		if(op==3)printf("%d\n",get_rank(k));
		if(op==4)printf("%d\n",get_val(k));
		if(op==5)printf("%d\n",get_val(get_rank(k)-1));
		if(op==6)printf("%d\n",get_val(get_rank(k+1)));
	}
	return 0;
}
