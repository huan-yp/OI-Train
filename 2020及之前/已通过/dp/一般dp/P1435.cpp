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
const int N=1e3+10;
int dp[N][N];
char a[N];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s",a+1);
	n=strlen(a+1);
	for(i=1;i<=n;i++)
	dp[i][i]=0;
	for(int l=2;l<=n;l++)
	for(i=1;i+l-1<=n;i++)
	{
		if(a[i]==a[i+l-1])
		dp[i][i+l-1]=dp[i+1][i+l-2];
		else
		dp[i][i+l-1]=1e9;
		dp[i][i+l-1]=min(min(dp[i+1][i+l-1]+1,dp[i][i+l-2]+1),dp[i][i+l-1]); 
	}
	cout<<dp[1][n];
	return 0;
}

