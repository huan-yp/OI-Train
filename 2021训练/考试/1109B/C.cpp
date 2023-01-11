#include<bits/stdc++.h>
#define size siz
#define int long long
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int mod=1e9+7,M=2e6+10;
int i,j,k,m,n,s,t,ans,maxn,root,at;
int fa[M],deg[M],dp[M],dep[M],size[M],dis[M][3],cnt[M];
vector<int> e[M];
void dfs(int u,int fa=0)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		dep[v]=dep[u]+1,dfs(v,u);
		size[u]+=size[v];
	}
	if(dep[u]>dep[root])root=u;
}
void redfs(int u,int fa=0)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		dep[v]=dep[u]+1,redfs(v,u);
	}
	if(dep[u]>dep[at])at=u;
}
void dfs2(int u,int op,int fa=0)
{
	for(int v:e[u])
	{
		if(fa==v)continue;
		dis[v][op]=dis[u][op]+1;
		dfs2(v,op,u);
	}
}
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;a=1ll*a*a%mod;
	}
	return ret;
}
signed main()
{
	read(n);
	for(i=1;i<=2*n;i++)fa[i]=i;

	for(i=1;i<n;i++)
	{
		int x,y;read(x),read(y);
		deg[x]++,deg[y]++;
		e[x].push_back(y);e[y].push_back(x);
	}
	dfs(1);dep[root]=0;int now=n;
	redfs(root);
	dp[dep[at]]=quick(2,n);
	dfs2(root,1);dfs2(at,2);
	for(i=1;i<=n;i++)
	cmax(maxn,min(dis[i][1],dis[i][2])),cnt[max(dis[i][1],dis[i][2])]++;
	for(i=dep[at];i>maxn;i--)
	{
		now-=cnt[i];
		dp[i-1]=quick(2,now+1);
	}
	for(i=maxn;i<=dep[at];i++)
	ans+=1ll*(dp[i]-dp[i-1])*i%mod,ans%=mod;
	cout<<(ans+mod)%mod;
	return 0;
}

