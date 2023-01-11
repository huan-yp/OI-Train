#include<bits/stdc++.h>
#define INF 2147483647
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
const int N=5e5+10;mt19937 mt_rand(0);
int i,j,n,s,t,m,T[N];
struct node{
	int key,ls,rs,val,sz;
}a[N*50];
int new_node(int val){
	return a[++t]=node{int(mt_rand()>>1),0,0,val,1}, t;
}
void push_up(int u){
	a[u].sz=a[a[u].ls].sz+a[a[u].rs].sz+1;
}
pii split(int u,int k){
	if(!u)return {0,0};	
	int t1,t2;a[t1=++t]=a[u];
	if(a[u].val<=k){
		tie(a[t1].rs,t2)=split(a[t1].rs,k);
		push_up(t1);return make_pair(t1,t2);
	}
	else{
		tie(t2,a[t1].ls)=split(a[t1].ls,k);
		push_up(t1);return make_pair(t2,t1);
	}
}
int merge(int u,int v){
	if(!u||!v)return u^v;
	if(a[u].key>a[v].key){
		a[u].rs=merge(a[u].rs,v);
		push_up(u);return u;
	}
	else{
		a[v].ls=merge(u,a[v].ls);
		push_up(v);return v;
	}
}
int get_rank(int root,int val){
	auto [t1,t2]=split(root,val-1);
	int res=a[t1].sz;merge(t1,t2);
	return res;
}
int get_val(int u,int k){
	while(1){
		if(a[a[u].ls].sz==k)return a[u].val;
		if(a[a[u].ls].sz+1>k)u=a[u].ls;
		else k-=a[a[u].ls].sz+1,u=a[u].rs;
	}
}
void insert(int &u,int x){
	if(a[u].key<a[x].key){
		tie(a[x].ls,a[x].rs)=split(u,a[x].val);
		u=x;push_up(x);return ;
	}
	a[++t]=a[u];u=t;a[t].sz++;
	if(a[x].val<a[u].val)insert(a[u].ls,x);
	else insert(a[u].rs,x);
}
void remove(int &u,int x){
	a[++t]=a[u],u=t;
	if(a[u].val)
	int t1,t2,t3;
	tie(t2,t3)=split(root,x);
	tie(t1,t2)=split(t2,x-1);
	return merge(t1,merge(merge(a[t2].ls,a[t2].rs),t3));
}
signed main()
{
	read(n);
	insert(T[0],new_node(INF));
//	T[0]=new_node(INF);a[T[0]].key=INF;
	insert(T[0],new_node(-INF));
	for(i=1;i<=n;i++){
		int ve,op,x;
		read(ve),read(op),read(x);
		if(op==1)insert(T[i]=T[ve],new_node(x));
		if(op==2)remove(T[i]=T[ve]);
		if(op==3)printf("%d\n",get_rank(T[i]=T[ve],x));
		if(op==4)printf("%d\n",get_val(T[i]=T[ve],x));
		if(op==5)printf("%d\n",get_val(T[i]=T[ve],get_rank(T[ve],x)-1));
		if(op==6)printf("%d\n",get_val(T[i]=T[ve],get_rank(T[ve],x+1)));
	}
	return 0;
}
