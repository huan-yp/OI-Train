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
int mod=998244353;
int a[101][2001],sum[101],ans,dp[210][2001];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		a[i][j]=read(); 
		sum[i]=(sum[i]+a[i][j])%mod;
	}
	ans=1;
	for(i=1;i<=n;i++)
	ans=(long long)ans*(sum[i]+1)%mod;
	ans--;
	for(i=1;i<=m;i++)
	{
		dp[0][102]=1;
		for(j=1;j<=n;j++)//101钦定的多1个 
		for(k=1;k<=n+102;k++)
		dp[j][k]=((long long)dp[j-1][k]+((long long)dp[j-1][k+1]*(sum[j]-a[j][i])%mod+(long long)dp[j-1][k-1]*a[j][i]%mod)%mod)%mod; 
		for(k=103;k<=n+102;k++)
		ans=(ans-dp[n][k])%mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}

