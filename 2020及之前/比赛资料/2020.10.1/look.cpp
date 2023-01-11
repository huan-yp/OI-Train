#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t,cnt0,cnt1;
const int N=4e2+10;
int mod=998244353;
int a[N],dp[401][401][201];
int main()
{
//	freopen("look.in","r",stdin);
//	freopen("look.out","w",stdout);
	scanf("%d%d",&n,&m);
	cnt0=cnt1=n;
	for(i=1;i<=m;i++)
	scanf("%d",&a[i]);
	dp[0][0][0]=1;
	//dp[i][j][k]考虑到第i个位置，形成j个队列中的人，站了k个女生。 
	for(i=1;i<=2*n;i++)
	for(j=0;j<=m&&j<=i;j++)
	for(k=0;k<=n&&k<=i;k++)
	{
		int tmp=i-k;//前面的男生数 
		if(n-tmp>=n-k&&i-k!=0)//站男生。
		dp[i][j][k]=(dp[i][j][k]+((a[j]==1&&j)?dp[i-1][j-1][k]:dp[i-1][j][k]))%mod;
		if(k!=0&&n-tmp>=n-k)//站女生。
		dp[i][j][k]=(dp[i][j][k]+((a[j]==0&&j)?dp[i-1][j-1][k-1]:dp[i-1][j][k-1]))%mod;
	}
	cout<<dp[n*2][m][n];
	return 0;
}
