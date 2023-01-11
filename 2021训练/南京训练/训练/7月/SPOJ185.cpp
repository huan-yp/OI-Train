#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define earse erase
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
const int N=3e3+10; 
int i,j,k,n,s,t,m,cnt,flag,ans;
vector <int> a[N];
int p[N],fa[N],dep[N],dis[N],dp[N];
queue<int> q;
void dfs(int u)
{
	for(int v:a[u])
	{
		if(v==fa[u]||dep[v])continue;
		fa[v]=u,dep[v]=dep[u]+1;
		dfs(v);
	}
}
void lca(int x,int y)
{
	if(dep[y]>dep[x])swap(x,y);
	while(dep[x]>dep[y])p[x]=1,x=fa[x]; 
	if(x==y)
	{
		p[x]=1;
		return;
	}
	while(x!=y)p[x]=p[y]=1,x=fa[x],y=fa[y];
	p[x]=1; 
} 
void bfs()
{

	q.push(t);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:a[u])
		{
			if(dis[v])continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	} 
}
void dfs()
{
	dis[t]=0;
	q.push(s);dp[s]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(dis[u]<=dp[u])continue;
		ans=max(ans,dis[u]);
		if(p[u])flag=1;
		for(int v:a[u])
		{
			if(dp[v])continue;
			dp[v]=dp[u]+1;
			q.push(v);
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot;
	read(tot);
	while(tot--)
	{
		dep[1]=1;
		ans=flag=cnt=0;
		read(n),read(m),read(s),read(t);
		for(i=1;i<=n;i++)
		a[i].clear();
		for(i=1;i<=m;i++)
		{
			int x,y;
			read(x),read(y);
			a[x].push_back(y);
			a[y].push_back(x);
		}	
		dfs(1);
		for(i=1;i<=n;i++)
		for(int v:a[i])
		{
			if(fa[v]==i||fa[i]==v)continue; 
			lca(v,i);
		}
		bfs();
		dfs();
		if(flag)
		{
			puts("NIE\n");
			continue;
		}
		printf("%d\n",ans);
		memset(p,0,sizeof(p));
		memset(dis,0,sizeof(dis));
		memset(dep,0,sizeof(dep));
		memset(dp,0,sizeof(dp));
	}
	return 0;
}
