#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
struct Edge
{
	int to;
	int nxt;
}e[1000005];
int n,m,edgenum,head[1000005];
bool flag[1000005];
ll p[1000005],f[1000005][2];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
void dfs(int node)
{
	f[node][0]=f[node][1]=1;
	if(flag[node])f[node][0]=0;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		dfs(to);
		f[node][0]=((MOD+1-p[to])*f[to][0]%MOD+p[to]*f[to][1]%MOD)*f[node][0]%MOD;
		f[node][1]=((MOD+1-p[to])*f[to][1]%MOD+p[to]*f[to][0]%MOD)*f[node][1]%MOD;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int x;
		scanf("%d",&x);
		if(i==1&&j==1)continue;
		if(x==0)add((i-2)*m+j,(i-1)*m+j);
		else add((i-1)*m+j-1,(i-1)*m+j);
		if(i==1||i==n||j==1||j==m)flag[(i-1)*m+j]=1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int x;
		scanf("%d",&x);
		p[(i-1)*m+j]=x*quick_pow(100,MOD-2)%MOD;
	}
	dfs(1);
	printf("%lld\n",f[1][1]);
	return 0;
}
