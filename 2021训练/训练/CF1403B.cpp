#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define size siz
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=2e5+10;
int i,j,k,n,s,t,m,cnt,root,q;
int fa[N],son[N],size[N],dfn[N],rak[N],top[N],ct[N],a[N],dep[N];
vector<int> e[N];
struct Tree{
	int a[N<<2],lazy[N<<2];
	void push_up(int rt){a[rt]=a[rt<<1]+a[rt<<1|1];}
	void push_down(int rt,int len1,int len2)
	{
		if(lazy[rt]==0)return ;
		a[rt<<1]=len1-a[rt<<1],lazy[rt<<1]^=1;
		a[rt<<1|1]=len2-a[rt<<1|1],lazy[rt<<1|1]^=1;
		lazy[rt]=0;
	}
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			a[rt]=1;
			return ;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)
		{
			a[rt]=r-l+1-a[rt],lazy[rt]^=1;
			return ;
		}
		int mid=(l+r)/2;push_down(rt,mid-l+1,r-mid);
		if(x<=mid)updata(l,mid,rt<<1,x,y);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)/2,ret=0;push_down(rt,mid-l+1,r-mid);
		if(x<=mid)ret+=quert(l,mid,rt<<1,x,y);
		if(y>mid)ret+=quert(mid+1,r,rt<<1|1,x,y);
		return ret;
	}
}T;
void predfs(int u)
{
	size[u]=1;
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		fa[v]=u;dep[v]=dep[u]+1;
		predfs(v);size[u]+=size[v];
		if(size[v]>size[son[u]])son[u]=v;
	}
}
void redfs(int u)
{
	dfn[u]=++t,rak[t]=u;
	if(son[fa[u]]==u)top[u]=top[fa[u]];
	else top[u]=u;
	if(son[u])
	redfs(son[u]);	
	
	for(int v:e[u])
	{
		if(fa[u]==v||v==son[u])continue;
		redfs(v);
	}
}
int query(int u,int v)
{
	if(top[u]==top[v])
	{
		if(dep[v]>dep[u])swap(v,u);
		return T.quert(1,n,1,dfn[v],dfn[u]);
	}
	int ret=0;
	if(dep[top[v]]>dep[top[u]])swap(u,v);
	ret+=T.quert(1,n,1,dfn[top[u]],dfn[u]);
	ret+=query(fa[top[u]],v);
	return ret;
}
void update(int u,int v)
{
	if(top[u]==top[v])
	{
		if(dep[v]>dep[u])swap(v,u);
		T.updata(1,n,1,dfn[v],dfn[u]);
		return ;
	}
	if(dep[top[v]]>dep[top[u]])swap(u,v);
	T.updata(1,n,1,dfn[top[u]],dfn[u]);
	update(fa[top[u]],v);
}
signed main()
{
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(q);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
		ct[x]++,ct[y]++;
	}
	for(i=1;i<=n;i++)if(ct[i]>1)root=i;
	
	predfs(root);
	redfs(root);
	T.build(1,n,1);
	for(i=1;i<=n;i++)
	{
		if(size[i]>1)continue;
		cnt++;update(i,root);
	}
	for(j=1;j<=q;j++)
	{
		int d;read(d);
		for(i=1;i<=d;i++)
		{
			int x;read(x);a[i]=x;
			if(size[x] > 1)
			update(x,root);
			size[x]++;
		}
		if(query(root,root) == 0)
		printf("-1\n");
		else
		printf("%d\n",n+d+T.a[1]-2);
		for(i=1;i<=d;i++)
		{
			int x=a[i];
			size[x]--;
			if(size[x]>1)
			update(a[i],root);
			
		}
	}
	return 0;
}

