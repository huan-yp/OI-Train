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
const int N=1e5+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int dp[N][2];
vector<int> a[N];
void dfs(int u,int fa=0)
{
	dp[u][1]=dp[u][0]=1;
	for(int v:a[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		dp[u][1]=1ll*dp[u][1]*dp[v][0]%mod;
		dp[u][0]=1ll*dp[u][0]*(dp[v][0]+dp[v][1])%mod;
	}
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
		a[x].push_back(y),a[y].push_back(x);
	}
	dfs(1);
	printf("%d",(dp[1][0]+dp[1][1])%mod);
	return 0;
}

