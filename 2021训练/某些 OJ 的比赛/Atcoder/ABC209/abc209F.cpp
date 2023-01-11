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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*


*/
const int N=4005,mod=1e9+7;
int i,j,k,n,s,t,m,cntminu,cntmenu,minu=mod,menu=mod;
int a[N],f[N]={1},inv[N]={1},dp[N][N],sum[N][N];
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)
		ret=1ll*ret*a%mod;
		s>>=1;
		a=1ll*a*a%mod;
	}
	return ret;
}
int C(int n,int m)
{
	if(m>n)return 0;
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]),f[i]=1ll*i*f[i-1]%mod,inv[i]=quick(f[i],mod-2);
	
	if(n==1)
	{
		printf("%d\n",n);
		return 0;
	}
	sum[1][0]=dp[1][0]=1;
	for(i=1;i<n;i++)
	{
		dp[1][i]=1;
		sum[1][i]=sum[1][i-1]+dp[1][i];
	}
	sum[1][n]=sum[1][n-1];
	//dp[i][j] 前面 i 个 ,第 i 个排名为 j. 
	//
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{	
			if(a[i]>a[i-1]&&i||(a[i]==a[i-1]||i==0))
			{
				//j+1~n
				//
				dp[i][j]+=(sum[i-1][n]-sum[i-1][j])%mod;
				dp[i][j]%=mod;
			}
			if((a[i]<a[i-1]&&i||(a[i]==a[i-1]||i==0)))
			{
				//j
				if(n-i>=j)
				dp[i][j]+=sum[i-1][j]%mod;
				dp[i][j]%=mod;
			}	
			sum[i][j]=dp[i][j];
			if(j)
			sum[i][j]+=sum[i][j-1],sum[i][j]%=mod;
		}
	}
	cout<<(dp[n][0]+mod)%mod;
	return 0;
}

