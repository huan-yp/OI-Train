#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
char ch;
inline void read(int &x)
{
	x=0;int f=1;
	ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
const int N=5e5+10;
struct operation{
	int u,v,op;
}q[N];
int i,j,k,n,s,t,m;
int fa[N],ans[N],f[N][20],dep[N],dis[N];
vector<pair<int,int> > e[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void dfs(int u)
{
	for(int i=1;i<=19;i++)
	f[u][i]=f[f[u][i-1]][i-1];
	for(auto tmp:e[u])
	{
		int v=tmp.first,val=tmp.second;
		if(v==f[u][0])continue;
		f[v][0]=u,dep[v]=dep[u]+1;
		dis[v]=dis[u]+val,dfs(v);
	}
}
int lca(int x,int y)
{
	if(dep[y]>dep[x])swap(x,y);
	for(int i=19;i>=0;i--)
	if(dep[f[x][i]]>=dep[y])
	x=f[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
	if(f[x][i]!=f[y][i])
	x=f[x][i],y=f[y][i];
	return f[x][0];
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u!=v)fa[u]=v;
}
signed main()
{
	memset(ans,0,sizeof(ans));
	read(n),read(m);for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)
	{
		int w;
		read(q[i].u),read(q[i].v);
		if(ch=='\n')
		q[i].op=2;
		else
		{
			read(w);q[i].op=1;
			e[q[i].u].push_back(make_pair(q[i].v,w));
			e[q[i].v].push_back(make_pair(q[i].u,w));		
		}
	}
	for(i=1;i<=n;i++)
	{
		if(dep[i]==0)
		{
			dep[i]=1;
			dfs(i);
		}
	}
	for(i=1;i<=m;i++)
	{
		if(q[i].op==2)
		ans[i]=dis[q[i].u]+dis[q[i].v]-2*dis[lca(q[i].u,q[i].v)];
	}
	for(i=1;i<=m;i++)
	{
		if(q[i].op==1)
		merge(q[i].u,q[i].v);
		else
		if(find(q[i].u)!=find(q[i].v))
		ans[i]=-1;
	}
	for(i=1;i<=m;i++)
	if(q[i].op==2)
	printf("%d\n",ans[i]);
	return 0;
}

