#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
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
const int N=1e5+10; 
int i,j,k,n,s,t,m,tp1,tp2,df;
int dfn[N],rak[N],sz[N],top[N],fa[N],son[N],dep[N];
int lazy[N<<2];
struct node{
	int t,sm;
	node operator +(const node &a){
		return node{max(t,a.t),a.sm+sm};
	}
};
node a[N<<2];
vector<int> e[N];
void push_up(int rt){
	a[rt]=a[rt<<1]+a[rt<<1|1];
}
void push_down(int l,int r,int rt){
	if(lazy[rt]==0)return;int mid=l+r>>1;
	lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
	a[rt<<1]={lazy[rt],mid-l+1};
	a[rt<<1|1]={lazy[rt],r-mid};lazy[rt]=0;	
}
void updata(int l,int r,int rt,int x,int y,int c,int p=1){
	if(x<=l&&y>=r){
		lazy[rt]=i;
		a[rt]={i*p+a[rt].t*(!p),(r-l+1)*c};
		return ;
	}
	int mid=l+r>>1;
	push_down(l,r,rt);
	if(x<=mid)updata(l,mid,rt<<1,x,y,c,p);
	if(y>mid)updata(mid+1,r,rt<<1|1,x,y,c,p);
	push_up(rt);
}
node quert(int l,int r,int rt,int x,int y){
	if(x>y)return {0,0};
	if(x<=l&&y>=r)return a[rt];
	node ret{0,0};int mid=l+r>>1;
	push_down(l,r,rt);
	if(x<=mid)ret=ret+quert(l,mid,rt<<1,x,y);
	if(y>mid)ret=ret+quert(mid+1,r,rt<<1|1,x,y);
	return ret;
}
void update(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		updata(1,n,1,dfn[top[u]],dfn[u],1);
		if(top[rak[dfn[u]+1]]==top[u])updata(1,n,1,dfn[u]+1,dfn[u]+1,0,0);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(v,u);
	updata(1,n,1,dfn[u],dfn[v],1);
	updata(1,n,1,dfn[u],dfn[u],0);
	if(top[rak[dfn[v]+1]]==top[v])updata(1,n,1,dfn[v]+1,dfn[v]+1,0,0);
}
int query(int u,int v){
	int res=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		res+=quert(1,n,1,dfn[top[u]],dfn[u]).sm;
		auto t1=quert(1,n,1,dfn[top[u]],dfn[top[u]]);
		if(t1.sm){
			auto t2=quert(1,n,1,dfn[fa[top[u]]],dfn[fa[top[u]]]);
			if(t2.t>t1.t)res--;
		}
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(v,u);
	res+=quert(1,n,1,dfn[u]+1,dfn[v]).sm;
	return res;
}
void dfs1(int u){
	sz[u]=1;
	for(auto v:e[u]){
		if(fa[u]==v)continue;
		dep[v]=dep[u]+1,fa[v]=u;dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void dfs2(int u){
	dfn[u]=++df;rak[df]=u;
	if(son[fa[u]]==u)top[u]=top[fa[u]];
	else top[u]=u;
	if(son[u])dfs2(son[u]);
	for(auto v:e[u]){
		if(v==fa[u]||v==son[u])continue;
		dfs2(v);
	}
}
signed main()
{
	int tot;read(tot);
	while(tot--){
		memset(son,0,sizeof(son));
		read(n),read(m);df=0;
		for(i=1;i<=n;i++)e[i].clear();
		for(i=1;i<n;i++){
			int x,y;read(x),read(y);
			e[x].push_back(y),e[y].push_back(x);
		}
		dfs1(1);dfs2(1);
		memset(lazy,0,sizeof(lazy)),memset(a,0,sizeof(a));
		
		for(i=1;i<=m;i++){
			int op,u,v;read(op),read(u),read(v);
			if(op==1)update(u,v);
			else printf("%d\n",query(u,v));
		}
	}
	return 0;
}
