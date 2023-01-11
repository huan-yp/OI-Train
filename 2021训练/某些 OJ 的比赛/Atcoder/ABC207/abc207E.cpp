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
const int N=3e3+10,mod=1e9+7;
int i,j,k,n,s,t,m,ans;
int a[N],sum[N];
int dp[N][N],p[N][N],cnt[N][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]);
	for(i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	cnt[1][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			dp[i][j]+=cnt[j][sum[i]%j];
			dp[i][j]%=mod;
		}
		for(j=1;j<=n;j++)
		cnt[j][sum[i]%j]+=dp[i][j-1],cnt[j][sum[i]%j]%=mod;
	}
	for(i=1;i<=n;i++)
	ans+=dp[n][i];
	cout<<ans%mod;
	return 0;
}

