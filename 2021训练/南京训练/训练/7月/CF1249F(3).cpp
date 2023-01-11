#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=405*405;
int i,j,k,n,s,t,m,cnt;
int a[N],dp[N],maxn[N],dep[N],val[N],son[N],fa[N];
int *f[N];
vector<int> e[N];
void predfs(int u)
{
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;
		predfs(v);
		if(dep[v]>=dep[son[u]])
		son[u]=v;
	}
	dep[u]=dep[son[u]]+1;
}
void dfs(int u)
{	
	if(son[fa[u]]!=u)
	f[u]=&val[s],s+=dep[u]+1;
	else
	f[u]=f[fa[u]],f[u]++;
	
	if(son[u])
	dfs(son[u]);
	
	for(int v:e[u])
	{
		if(v==fa[u]||v==son[u])continue;
		dfs(v);
	}
	f[u][0]=max(f[u][1],(k>=dep[u]?0:f[u][k+1])+a[u]);
	for(int v:e[u])
	{
		if(v==fa[u]||v==son[u])continue;
		for(i=1;i<=dep[v];i++)
		{
			int l1=max(i-1,k-i),l2=max(i,k-i+1);
			f[u][i]=max(f[u][i]+(l1>dep[v]?0:f[v][l1]),(l2>dep[u]?0:f[u][l2])+f[v][i-1]);
			cnt++;
		}
		if(dep[v]>=k)f[u][0]+=f[v][k];
		for(i=dep[v]-1;i>=0;i--)
		f[u][i]=max(f[u][i],f[u][i+1]);
	}	
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)
	read(a[i]);
	
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	predfs(1);
	dfs(1);
	
	if(cnt>400)
	printf("Boom");
	cout<<f[1][0];
	
	
	return 0;
}
