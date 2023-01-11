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
const int N=2005,mod=1e9+7;
int i,j,k,n,s,t,m,inv;
int dp[N][N];
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=a*a%mod;s>>=1;
	}
	return ret;
}
//dp[n][n]=n*k
//dp[n][m]=max(min(dp[n-1][m-1]+x,dp[n-1][m]-x))
signed main()
{
	//dp[n][i]>dp[n][i-1]
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	inv=quick(2,mod-2);
	for(i=1;i<=2000;i++)
	{
		dp[i][0]=0;
		for(j=1;j<i;j++)
		dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])*inv%mod;
		dp[i][i]=i;
	}
	read(t);
	while(t--)
	{
		read(n),read(m),read(k);
		printf("%lld\n",1ll*dp[n][m]*k%mod);
	}

	return 0;
}

