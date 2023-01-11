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
const int N=3e5+10;
int i,j,k,n,s,t,m,ans=1ll*INF*INF;
int a[N],b[N],dp[N][2];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=n;i++)read(b[i]);
	//0: ͬ 0  
	memset(dp,15,sizeof(dp));dp[1][0]=a[1]+b[n];
	for(i=2;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0]+a[i]+b[i-1],dp[i-1][1]+a[i]);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1]+b[i-1]);	
	}
	cmin(ans,dp[n][0]);
	memset(dp,15,sizeof(dp));dp[1][1]=b[n];
	for(i=2;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0]+a[i]+b[i-1],dp[i-1][1]+a[i]);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1]+b[i-1]);	
	}
	cmin(ans,dp[n][1]);
	memset(dp,15,sizeof(dp));dp[1][0]=a[1];
	for(i=2;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0]+a[i]+b[i-1],dp[i-1][1]+a[i]);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1]+b[i-1]);	
	}
	cmin(ans,dp[n][1]);
	memset(dp,15,sizeof(dp));dp[1][1]=0;
	for(i=2;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0]+a[i]+b[i-1],dp[i-1][1]+a[i]);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1]+b[i-1]);	
	}
	cmin(ans,dp[n][0]);
	cout<<ans<<endl;
	return 0;
}

