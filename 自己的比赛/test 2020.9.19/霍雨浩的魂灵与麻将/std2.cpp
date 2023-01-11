#include<bits/stdc++.h>
using namespace std;
int k,m,n,s,t;
const int N=1e6+10,M=1e5+10;
struct fu{
	int next,v,val;
}a[N];
int head[M],fa[M],size[M];
long long dp[M][2][5],b[M],mod=998244353;
void work(int aa,int bb,int cc)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].val=cc;
	a[k].v=bb;
}
void dfs(int u)
{
	int i,js=0,j;
	for(i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(fa[u]==v)
		continue;
		fa[v]=u;
		dfs(v);
		js++;
		for(j=1;j<=4;j++)
		dp[u][js%2][j]=0;
		dp[u][(js-1)%2][0]=1;
		for(j=1;j<=4;j++)
		for(int ii=0;ii<=a[i].val&&ii<=j;ii++)
		{
			dp[u][js%2][j]=(dp[u][js%2][j]+dp[u][(js-1)%2][j-ii]*dp[v][size[v]%2][ii]%mod)%mod;
		}
	}
	js++;
	for(j=1;j<=4;j++)
	dp[u][js%2][j]=0;
	dp[u][(js-1)%2][0]=1;
	for(j=1;j<=4;j++)
	dp[u][js%2][j]=(dp[u][js%2][j]+dp[u][(js-1)%2][j-1]*b[u]%mod+dp[u][(js-1)%2][j])%mod;
	dp[u][js%2][0]=1;
	size[u]=js;
}
int main()
{
//	freopen("data.in","r",stdin);
	//freopen("data20.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%lld",&b[i]);
	int x,y,z;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		work(x,y,z);
		work(y,x,z);
	}
	dfs(1);
	printf("%lld",dp[1][size[1]%2][4]);
	return 0;
}
