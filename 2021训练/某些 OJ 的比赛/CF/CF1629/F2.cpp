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
const int N=1000005,mod=1e9+7;
int i,j,k,n,s,t,m;
int f[N],inv[N];
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
int C(int n,int m)
{
	if(m<0)return 0;
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
//dp[n][n]=n*k
//dp[n][m]=max(min(dp[n-1][m-1]+x,dp[n-1][m]-x))
signed main()
{
	//dp[n][i]>dp[n][i-1]
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	f[0]=inv[0]=1;
	for(i=1;i<N;i++)f[i]=f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	read(t);
	while(t--)
	{
		read(n),read(m),read(k);
		int ans=0;
		if(n==m)
		{
			printf("%lld\n",n*k%mod);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			ans+=i*C(n-i-1,m-i)%mod*quick(quick(2,n-i),mod-2)%mod;
			ans%=mod;
		}
		printf("%lld\n",ans*k%mod);
	}

	return 0;
}

