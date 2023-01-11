#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
const int N=5e3+10;
long long dp[N][N],a[N],sum[N];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=k&&j*m<=i;j++)
	dp[i][j]=max(dp[i-m][j-1]+sum[i]-sum[i-m],dp[i-1][j]);
	cout<<dp[n][k];
	return 0;
}

