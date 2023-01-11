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
/*
dp[i][j][0/1][0/1] 
i 是否涂色，i 是否有儿子涂色
dp[i][j][0][0]=//做一遍树上背包([0][1/0])
dp[i][j][0][1]=//任选减去上一个的答案 
dp[i][j][1][1]=//树上背包,判断一下是否会覆盖掉儿子 
dp[i][j][1][0]=//不算这个，这是占位的 
初值:dp[i][1][1][1]=1,dp[i][0][0][0]=1; 
 
*/
const int N=2e3+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int dp[N][N][2][2],size[N];
vector <int> e[N];
void dfs(int u,int fa)
{
	dp[u][1][1][1]=1,dp[u][0][0][0]=1,dp[u][0][0][1]=1; 
	size[u]++;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		for(j=size[u]+size[v];j>=0;j--)
		{
			if(j-size[u]>0)
			dp[u][j][0][0]=dp[u][j][0][1]=0;
			if(j<2)
			dp[u][j][1][1]=0;
			if(j>=2)
			dp[u][j][1][1]=dp[u][j-1][1][1];
			for(k=max(1ll,j-size[u]-1);k<=size[v]&&k<=j;k++)
			{
				dp[u][j][0][0]+=dp[u][j-k][0][0]*(dp[v][k][0][1]+dp[v][k][0][0]),dp[u][j][0][0]%=mod;
				dp[u][j][0][1]+=dp[u][j-k][0][1]*(dp[v][k][0][1]+dp[v][k][0][0]+dp[v][k][1][1]),dp[u][j][0][1]%=mod; 
				if(k==j)continue; 
				dp[u][j][1][1]+=(dp[u][j-k-1][1][1])*(dp[v][k][0][0])+(dp[u][j-k][1][1])*(dp[v][k][0][1]+dp[v][k][1][1]),dp[u][j][1][1]%=mod;
			}
		}
		size[u]+=size[v];
	}
	for(int j=size[u];j>=1;j--)
	dp[u][j][0][1]=dp[u][j-1][0][1]-dp[u][j-1][0][0],dp[u][j][0][1]%=mod;
	dp[u][0][0][1]=0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1,0);
	for(i=0;i<=n;i++)
	printf("%lld\n",((dp[1][i][0][0]+dp[1][i][0][1]+dp[1][i][1][1])%mod+mod)%mod);
	return 0;
}
