#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=2e5+10;
int i,j,k,n,s,t,m,tp1,tp2,r;
int fa[N],c[N];
template<typename T>
struct pri_queue{
	priority_queue<T> q1,q2;
	bool empty(){
		while(!q2.empty()&&!q1.empty()&&q1.top()==q2.top())q1.pop(),q2.pop();
		return q1.empty();
	}
	T top(){
		empty();return q1.top();
	}
	void pop(){
		empty();q1.pop();
	}
	void push(const T &a){
		q1.push(a);
	}
	void erase(const T &a){
		q2.push(a);
	}
	void clear(){
		while(!q1.empty())q1.pop();
		while(!q2.empty())q2.pop();
	}
};
struct node{
	int u,sz,sm,as;
	friend bool operator <(const node &a,const node &b){
		if(a.sz*b.sm!=b.sz*a.sm)return a.sz*b.sm>b.sz*a.sm;
		return a.u<b.u;
	}
	friend bool operator ==(const node &a,const node &b){
		return a.u==b.u&&a.sz==b.sz;
	}
	void operator +=(const node &a){
		as+=a.as+sz*a.sm;
		sm+=a.sm;sz+=a.sz;
	}
	void print(){
		printf("%lld\n",as);
	}
}nd[N];
namespace dsu{
	int fa[N];
}
vector<int> e[N];
pri_queue<node> q;
int find(int x){
	using dsu::fa;
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	if(u!=r)q.erase(nd[u]);
	nd[u]+=nd[v];dsu::fa[v]=u;
	if(u!=r)q.push(nd[u]);
}
void dfs(int u){
	q.push(nd[u]={u,1,c[u],0});
	for(auto v:e[u]){
		if(fa[u]==v)continue;
		fa[v]=u;dfs(v);
	}
}
signed main()
{
 	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
//	freopen(".in","w",stdout);
	while(~scanf("%lld%lld",&n,&r)){
		q.clear();
		for(i=1;i<=n;i++)read(c[i]);
		for(i=1;i<=n;i++)e[i].clear(),fa[i]=0,dsu::fa[i]=i;
		for(i=1;i<n;i++){
			int x,y;read(x),read(y);
			e[x].push_back(y),e[y].push_back(x);
		}
		dfs(r);
		while(!q.empty()){
			auto val=q.top();q.pop();
			if(val.u==r)continue;
			int f=find(fa[val.u]);
			merge(f,val.u);
		}
		cout<<nd[r].as+nd[r].sm<<endl;
	}
	return 0;
}
