#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=6e5+10;
int i,j,k,n,s,t,m,q;
int fa[N],dfn[N],rak[N],val[N],dep[N],f[N][20];
vector<int> e[N];
tuple<int,int,int> a[N];
struct Tree{
	int a[2][N<<2],lazy[N<<2],val[2][N<<2];
	void push_up(int rt)
	{
		a[0][rt]=max(a[0][rt<<1],a[0][rt<<1|1]);
		a[1][rt]=min(a[1][rt<<1],a[1][rt<<1|1]);
	}
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			a[0][rt]=0,a[1][rt]=INF;
			val[0][rt]=val[1][rt]=dfn[l];
			return ;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		val[0][rt]=max(val[0][rt<<1],val[0][rt<<1|1]);
		val[1][rt]=min(val[1][rt<<1],val[1][rt<<1|1]);
		push_up(rt);
	}
	void push_down(int rt)
	{
		if(lazy[rt]==-1)return ;
		if(lazy[rt]==0)a[0][rt<<1]=a[0][rt<<1|1]=0,a[1][rt<<1]=a[1][rt<<1|1]=INF;	
		else 
		{
			a[0][rt<<1]=val[0][rt<<1],a[1][rt<<1]=val[1][rt<<1],
			a[0][rt<<1|1]=val[0][rt<<1|1],a[1][rt<<1|1]=val[1][rt<<1|1];
		}	
		lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];lazy[rt]=-1;
	}
	void updata(int l,int r,int rt,int x,int y,int c)
	{
		if(x<=l&&y>=r)
		{
			if(c==0)a[0][rt]=0,a[1][rt]=INF;
			else cmax(a[0][rt],val[0][rt]),cmin(a[1][rt],val[1][rt]);
			lazy[rt]=c;
			return ;
		}
		push_down(rt);
		int mid=(l+r)/2;
		if(x<=mid)updata(l,mid,rt<<1,x,y,c);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y,c);
		push_up(rt);
	}
}T;
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void Kru()
{
	t=n;
	for(i=1;i<n;i++)
	{
		int u,v,w;tie(w,u,v)=a[i];
		u=find(u),v=find(v);
		fa[u]=fa[v]=++t;val[t]=w;
		e[t].push_back(v),e[t].push_back(u);
	}
}
void dfs(int u)
{
	dfn[u]=++s,rak[s]=u;
	for(int i=1;i<20;i++)
	f[u][i]=f[f[u][i-1]][i-1];
	for(int v:e[u])
	dep[v]=dep[u]+1,f[v][0]=u,dfs(v);
}
int lca(int x,int y)
{
	if(dep[y]>dep[x])swap(x,y);int p=dep[x]-dep[y];
	for(int i=19;i>=0;i--)if(1<<i&p)x=f[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
signed main()
{
	read(n),read(q);
	for(i=1;i<=n;i++)val[i]=-1;
	for(i=1;i<=n<<1;i++)fa[i]=i;
	for(i=1;i<n;i++)
	{
		int x,y,z;read(x),read(y),read(z);
		a[i]=make_tuple(z,x,y);
	}
	sort(a+1,a+n);
	Kru();dep[t]=1;dfs(t);
	T.build(1,n,1);
	for(i=1;i<=q;i++)
	{
		int op,l,r,x;
		read(op);
		if(op==1)
		{
			read(l),read(r);
			T.updata(1,n,1,l,r,1);
		}
		if(op==2)
		{
			read(l),read(r);
			T.updata(1,n,1,l,r,0);
		}
		if(op==3)
		{
			int ans=-1,x;read(x);
			int x1=T.a[0][1],x2=T.a[1][1];
			if(x1!=0)cmax(ans,val[lca(rak[x1],x)]);
			if(x2!=INF)cmax(ans,val[lca(rak[x2],x)]);
			printf("%d\n",ans);
		}
	}
	return 0;
}

