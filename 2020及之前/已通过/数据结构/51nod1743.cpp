#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,k,n,s,t,m,q;
const int N=2e6+10;
struct edge{
	int u,v,val,p;
}a[N];
int dfn[N],son[N],size[N],dep[N],top[N],fa[N],w[N],f[N],rak[N],lazy[N<<2],T[N<<2];
vector <int> e[N];
bool cmp(edge aa,edge bb)
{
	return aa.val<bb.val;
}
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
void dfs(int u)
{
	size[u]++;
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u,dep[v]=dep[u]+1;
		dfs(v);
		size[u]+=size[v];
		if(size[v]>size[son[u]])
		son[u]=v;
	}
}
void dfs2(int u)
{
	dfn[u]=++t,rak[t]=u;
	if(son[fa[u]]==u)
	top[u]=top[fa[u]];
	else
	top[u]=u;
	if(son[u])
	dfs2(son[u]);
	for(int v:e[u])
	{
		if(v==fa[u]||v==son[u])continue;
		dfs2(v);
	}
}
void kru()
{
	for(i=1;i<=m;i++)
	{
		int u=find(a[i].u),v=find(a[i].v);
		if(u==v)continue;
		a[i].p=1,f[u]=v;
		e[a[i].u].push_back(a[i].v),e[a[i].v].push_back(a[i].u);//注意加的边是什么 
	}
}
void push_up(int rt)
{
	T[rt]=max(T[rt<<1],T[rt<<1|1]);
}
void push_down(int rt)
{
	if(lazy[rt]==-1)return;
	T[rt<<1]=T[rt<<1|1]=lazy[rt];
	lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
	lazy[rt]=-1;
}
void updata(int l,int r,int rt,int x,int y,int c)
{
	if(x<=l&&y>=r)
	{
		T[rt]=c;
		lazy[rt]=c;
		return;
	}
	push_down(rt);
	int mid=(l+r)/2;
	if(x<=mid)
	updata(l,mid,rt<<1,x,y,c);
	if(y>mid)
	updata(mid+1,r,rt<<1|1,x,y,c);
	push_up(rt);
}
int quert(int l,int r,int rt,int x,int y)
{
	if(x<=l&&y>=r)
	return T[rt];
	int ret=0,mid=(l+r)/2;
	push_down(rt);
	if(x<=mid)
	ret=max(ret,quert(l,mid,rt<<1,x,y));
	if(y>mid)
	ret=max(ret,quert(mid+1,r,rt<<1|1,x,y));
	return ret;
}
void update(int u,int v,int c)
{
	if(top[u]==top[v])
	{
		if(u==v)
		return;
		if(dep[u]>dep[v])swap(u,v);
		updata(1,n,1,dfn[u]+1,dfn[v],c);
		return;
	}
	if(dep[top[u]]<dep[top[v]])swap(u,v);
	updata(1,n,1,dfn[top[u]],dfn[u],c);
	update(fa[top[u]],v,c);
}
int query(int u,int v)
{
	if(top[u]==top[v])
	{
		if(u==v)return 0;
		if(dep[u]>dep[v])swap(u,v);
		return quert(1,n,1,dfn[u]+1,dfn[v]);//存的是边，没有LCA 
	}
	if(dep[top[u]]<dep[top[v]])swap(u,v);
	int ret=quert(1,n,1,dfn[top[u]],dfn[u]);
	ret=max(query(fa[top[u]],v),ret);
	return ret;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(T,1,sizeof(T));
	memset(lazy,-1,sizeof(lazy));
	read(n),read(m),read(q);
	for(i=1;i<=n;i++)
	read(w[i]),f[i]=i;
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		a[i].u=x,a[i].v=y;
		a[i].val=abs(w[x]-w[y]);
	}
	sort(a+1,a+m+1,cmp);
	kru();
	for(i=1;i<=n;i++)
	{
		if(dfn[i])continue;
		dfs(i);
		dfs2(i);
	}
	for(i=m;i>=1;i--)
	{
		if(a[i].p)continue;
		update(a[i].u,a[i].v,a[i].val);
	}
	for(i=1;i<=q;i++)
	{
		int x,y;
		read(x),read(y);
		if(find(x)!=find(y))
		printf("infinitely\n");
		else
		{
			int ans=query(x,y);
			if(ans<1e7)
			printf("%d\n",query(x,y));
			else
			printf("infinitely\n");
		}
	}
	return 0;
}
