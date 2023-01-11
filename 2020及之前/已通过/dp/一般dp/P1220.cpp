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
const int N=51;
int a[51],sum[51],dp[51][51][2],b[51],c[51];//0×ó1ÓÒ 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&b[i],&a[i]);	
		sum[i]=sum[i-1]+a[i];	
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	dp[i][j][0]=dp[i][j][1]=1e9+10;
	dp[t][t][0]=dp[t][t][1]=0;
	for(int l=2;l<=n;l++)
	for(i=1;i+l-1<=n;i++)
	{
		dp[i][i+l-1][0]=min(dp[i+1][i+l-1][0]+(b[i+1]-b[i])*(sum[n]-(sum[i+l-1]-sum[i])),dp[i+1][i+l-1][1]+(b[i+l-1]-b[i])*(sum[n]-(sum[i+l-1]-sum[i])));
		dp[i][i+l-1][1]=min(dp[i][i+l-2][0]+(b[i+l-1]-b[i])*(sum[n]-(sum[i+l-2]-sum[i-1])),dp[i][i+l-2][1]+(b[i+l-1]-b[i+l-2])*(sum[n]-(sum[i+l-2]-sum[i-1])));
	}
	printf("%d",min(dp[1][n][1],dp[1][n][0]));
	return 0;
}

