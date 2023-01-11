#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
int i,j,k,n,s,t,m;
int pd[N],dis[N],dep[N],dp[N];
vector<int> e[N];
void dfs(int u,int fa=0)
{
	dis[u]=1e9;dp[u]=0;
	if(pd[u])dis[u]=0;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dep[v]=dep[u]+1,dfs(v,u);
		cmin(dis[u],dis[v]+1);
		dp[u]+=dp[v];
	}
	if(dp[u]==0)dp[u]=1e9;
	if(dep[u]>=dis[u])dp[u]=1;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(k);
		for(i=1;i<=n;i++)pd[i]=0,dp[i]=1e9,e[i].clear();
		for(i=1;i<=k;i++)
		{
			int x;read(x);
			pd[x]=1;
		}
		for(i=1;i<n;i++)
		{
			int x,y;read(x),read(y);
			e[x].push_back(y),e[y].push_back(x);
		}
		dfs(1);
		if(dp[1]>n)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}

