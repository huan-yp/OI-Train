#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define size siz
#define INF 1000000000
#define int long long
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
const int N=2e3+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int dp[N][N][2][2][2],size[N],son[N];
vector <int> e[N];
void dfs(int u,int fa)
{
	dp[u][1][1][1][son[u]&1]=1,dp[u][0][0][0][son[u]&1]=1,dp[u][0][0][1][son[u]&1]=1; 
	size[u]++;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		son[u]++;
		for(j=size[u]+size[v];j>=0;j--)
		{
			dp[u][j][0][0][son[u]&1]=dp[u][j][0][1][son[u]&1]=dp[u][j][1][1][son[u]&1]=0;
			for(k=max(0ll,j-size[u]-1);k<=size[v]&&k<=j;k++)
			{
				dp[u][j][0][0][son[u]&1]+=dp[u][j-k][0][0][(son[u]-1)&1]*(dp[v][k][0][1][son[v]&1]+dp[v][k][0][0][son[v]&1]),dp[u][j][0][0][son[u]&1]%=mod;
				dp[u][j][0][1][son[u]&1]+=dp[u][j-k][0][1][(son[u]-1)&1]*(dp[v][k][0][1][son[v]&1]+dp[v][k][0][0][son[v]&1]+dp[v][k][1][1][son[v]&1]),dp[u][j][0][1][son[u]&1]%=mod; 
				if(k==j)continue; 
				dp[u][j][1][1][son[u]&1]+=dp[u][j-k-1][1][1][(son[u]-1)&1]*(dp[v][k][0][0][son[v]&1])+(dp[u][j-k][1][1][(son[u]-1)&1])*(dp[v][k][0][1][son[v]&1]+dp[v][k][1][1][son[v]&1]),dp[u][j][1][1][son[u]&1]%=mod;
			}
		}
		size[u]+=size[v];
	}//滚动数组，记得清零 
	for(int j=size[u];j>=1;j--)
	dp[u][j][0][1][son[u]&1]=dp[u][j-1][0][1][son[u]&1]-dp[u][j-1][0][0][son[u]&1],dp[u][j][0][1][son[u]&1]%=mod;
	dp[u][0][0][1][son[u]&1]=0;
}
signed main()
{
	read(n);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1,0);
	for(i=0;i<=n;i++)
	printf("%lld\n",((dp[1][i][0][0][son[1]&1]+dp[1][i][0][1][son[1]&1]+dp[1][i][1][1][son[1]&1])%mod+mod)%mod);
	return 0;
}

