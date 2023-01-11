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
const int N=115,M=2005,mod=998244353;
int i,j,k,n,s,t,m,ans=1;
int a[N][M],sum[N],dp[N][N<<1];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	read(a[i][j]),sum[i]+=a[i][j],sum[i]%=mod;
	
	for(i=1;i<=n;i++)
	ans=1ll*ans*(sum[i]+1)%mod;
	
	for(s=1;s<=m;s++)
	{
		memset(dp,0,sizeof(dp));
		dp[0][N]=1;
		for(i=0;i<n;i++)
		for(j=N-i;j<=N+i;j++)
		{
			dp[i+1][j]+=dp[i][j];dp[i+1][j]%=mod;
			dp[i+1][j+1]+=1ll*dp[i][j]*a[i+1][s]%mod;dp[i+1][j+1]%=mod;
			dp[i+1][j-1]+=1ll*dp[i][j]*(sum[i+1]-a[i+1][s])%mod;dp[i+1][j-1]%=mod;
		}
		
		for(i=N+1;i<2*N;i++)
		ans-=dp[n][i],ans%=mod;
		
	}
	ans--;ans%=mod;
	printf("%d",(ans+mod)%mod);
	return 0;
}

