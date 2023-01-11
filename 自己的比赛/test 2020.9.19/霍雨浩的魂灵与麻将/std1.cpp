#include<iostream>
#include<cstdio>
#define Re register
#define In inline
#define LL long long
using namespace std;
const int maxn=1e5+5,mod=998244353;
int n,knum,t[maxn],w[maxn],head[maxn],val[maxn][5],ans[maxn][5],dp[maxn][5];
struct road
{
	int en,w,nxt;
}ed[maxn<<1];
In void buildedge(int x,int y,int z)
{
	knum++;
	ed[knum].nxt=head[x];
	head[x]=knum;
	ed[knum].en=y;
	ed[knum].w=z;
}
In void dfs(int x,int f)
{
	for(Re int i=head[x];i!=-1;i=ed[i].nxt)
		if(ed[i].en!=f)
			dfs(ed[i].en,x);
	int cnt=0;
	for(Re int i=head[x];i!=-1;i=ed[i].nxt)
		if(ed[i].en!=f)
		{
			cnt++;
			w[cnt]=ed[i].w;
			for(Re int j=0;j<=4;j++)
				val[cnt][j]=ans[ed[i].en][j];
		}
	for(Re int i=0;i<=cnt;i++)
		for(Re int j=0;j<=4;j++)
			dp[i][j]=0;
	dp[0][0]=1;
	dp[0][1]=t[x];
	for(Re int i=1;i<=cnt;i++)
		for(Re int j=0;j<=4;j++)
		{
			dp[i][j]=dp[i-1][j];
			for(Re int k=1;k<=min(j,w[i]);k++)
				dp[i][j]=(dp[i][j]+(LL)dp[i-1][j-k]*(LL)val[i][k]%(LL)mod)%mod;
		}
	for(Re int i=0;i<=4;i++)
		ans[x][i]=dp[cnt][i];
}
int main()
{
	scanf("%d",&n);
	for(Re int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		head[i]=-1;
	}
	for(Re int i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		buildedge(x,y,z);
		buildedge(y,x,z);
	}
	dfs(1,1);
	printf("%d",ans[1][4]);
	return 0;
}
