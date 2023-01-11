#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
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



*/
const int N=100005,M=105;
int i,j,k,n,s,t,m;
int dp[M][N];
int w[N],v[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	read(w[i]),read(v[i]);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		dp[i][j]=dp[i-1][j];
		if(j-w[i]>=0)
		dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
	}
	int ans=0;
	for(i=1;i<=m;i++)
	ans=max(ans,dp[n][i]);
	cout<<ans;
	return 0;
}

