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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=3005;
int i,j,k,n,s,t,m,mod;
int dp[N][N],inv[N*N*2],f[N*N*2],g[N][N];
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;
		a=1ll*a*a%mod;
	}
	return ret;
}
int C(int n,int m)
{
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(mod);f[0]=1;
	for(i=1;i<=2*n*n+1;i++)
	f[i]=1ll*f[i-1]*i%mod;
	inv[2*n*n+1]=quick(f[2*n*n+1],mod-2);
	for(i=2*n*n;i>=0;i--)
	inv[i]=1ll*inv[i+1]*(i+1)%mod;
	
	int ctl=1ll*C(2*n,n)*inv[n+1]%mod*f[n]%mod;
	g[n][n]=dp[0][0]=1;
	for(i=n;i>=0;i--)
	for(j=i-(i==n);j>=0;j--)
	{
		g[i][j]=g[i+1][j]+g[i][j+1];
		g[i][j]%=mod;
	}
	for(i=1;i<=n;i++)
	{
		dp[i][0]=1;
		for(j=1;j<=i;j++)
		{
			dp[i][j]=dp[i-1][j];
			int lst=2*n*n-i-j-(j-1)*2*n;
			if(i!=j)
			{
				dp[i][j]+=1ll*dp[i][j-1]*g[0][0]%mod*C(lst,2*n)%mod;
				dp[i][j]%=mod;
			}
			else
			{
				for(k=0;k<=n;k++)
				{
					dp[i][j]+=1ll*dp[i][j-1]*g[k][0]%mod*C(lst-k-1,2*n-k)%mod;
					dp[i][j]%=mod;
				}
			}
		}
	}
	cout<<dp[n][n-1];
	return 0;
}

