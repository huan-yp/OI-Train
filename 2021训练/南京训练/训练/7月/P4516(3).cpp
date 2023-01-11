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
/*
*/
const int N=100005,M=105,mod=INF+7;
int i,j,k,n,s,t,m;
int dp[N][M][2][2],size[N];
vector<int> e[N];
 
void dfs(int u,int fa)
{
	size[u]++;
	dp[u][1][1][0]=dp[u][0][0][0]=1;
	dp[u][0][0][1]=dp[u][1][1][1]=1;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		for(i=min(k,size[u]+size[v]);i>=0;i--)
		{
			LL v00=0,v01=0,v10=0,v11=0;
			for(j=max(0,i-size[u]);j<=size[v]&&j<=i;j++)
			{
				v00+=1ll*dp[u][i-j][0][0]*dp[v][j][0][1]%mod;
				v01+=1ll*dp[u][i-j][0][1]*(dp[v][j][1][1]+dp[v][j][0][1])%mod;
				v10+=1ll*dp[u][i-j][1][0]*(dp[v][j][0][1]+dp[v][j][0][0])%mod;
				v11+=1ll*dp[u][i-j][1][1]*((LL)dp[v][j][0][1]+dp[v][j][1][0]+dp[v][j][1][1]+dp[v][j][0][0])%mod;
			}
			dp[u][i][0][0]=v00%mod;
			dp[u][i][0][1]=v01%mod;
			dp[u][i][1][0]=v10%mod;
			dp[u][i][1][1]=v11%mod;
		}
		size[u]+=size[v];
	}
	for(i=0;i<=k;i++)
	{
		dp[u][i][0][1]-=dp[u][i][0][0],dp[u][i][0][1]%=mod;
		dp[u][i][1][1]-=dp[u][i][1][0],dp[u][i][1][1]%=mod;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1,0);
	cout<<((dp[1][k][0][1]+dp[1][k][1][1])%mod+mod)%mod;
	return 0;
}
