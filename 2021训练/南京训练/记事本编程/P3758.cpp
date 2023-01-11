#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m,now=1;
const int N=35,mod=2017;
int dp[N][N][N];
int ans[N][N];
int sum;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		dp[x][y][0]=1;	
		dp[y][x][0]=1;
	}
	read(t);
	for(i=1;i<=n+1;i++)
	dp[i][n+1][0]=1,dp[i][i][0]=1;
	n++;
	for(s=1;s<=20;s++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		for(k=1;k<=n;k++)
		dp[i][j][s]+=dp[i][k][s-1]*dp[k][j][s-1];
		dp[i][j][s]%=mod;
	}
	ans[1][now]=1;
	for(s=20;s>=0;s--)
	if(t&(1<<s))
	{
		now++;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			ans[i][now]+=ans[j][now-1]*dp[j][i][s];
			ans[i][now]%=mod;
		}
	}
	for(i=1;i<=n;i++)
	sum+=ans[i][now];
	cout<<sum%mod;
	return 0;
}


