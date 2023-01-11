#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m,x1,y1;
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
int dp[N][N],cnt[3][N][N],sum,pd,a[N][N],ans=1e9;
char mp1[N][N],mp2[N][N];
char mp[N<<2];
void print(int x,int y)
{
	while(x!=1||y!=1)
	{
		mp[++sum]=mp1[x][y];
		if(mp1[x][y]=='D')
		x--;
		else
		y--;
	}
	for(i=sum;i>=1;i--)
	putchar(mp[i]);
} 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>n;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{ 
		scanf("%d",&t);
		a[i][j]=t;
		if(t==0)
		{
			ans=1,pd=1,x1=i,y1=j;
			continue;
		}
		while(t%2==0)
		{
			t/=2;
			cnt[1][i][j]++;
		}
		while(t%5==0)
		{
			t/=5;
			cnt[2][i][j]++;
		}
	}
	dp[1][1]=cnt[1][1][1];
	for(i=2;i<=n;i++)
	if(a[i][1]!=0)
	dp[i][1]=dp[i-1][1]+cnt[1][i][1],mp1[i][1]='D';
	else
	dp[i][1]=1e9;
	for(i=2;i<=n;i++)
	if(a[1][i]!=0)
	dp[1][i]=dp[1][i-1]+cnt[1][1][i],mp1[1][i]='R';
	else
	dp[1][i]=1e9;
	for(i=2;i<=n;i++)
	for(j=2;j<=n;j++)
	if(a[i][j]!=0)
	dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cnt[1][i][j],mp1[i][j]=(dp[i-1][j]<dp[i][j-1]?'D':'R');
	else
	dp[i][j]=1e9;
	ans=min(ans,dp[n][n]);
	dp[1][1]=cnt[2][1][1];
	for(i=2;i<=n;i++)
	if(a[i][1]!=0)
	dp[i][1]=dp[i-1][1]+cnt[2][i][1],mp2[i][1]='D';
	else
	dp[i][1]=1e9;
	for(i=2;i<=n;i++)
	if(a[1][i]!=0)
	dp[1][i]=dp[1][i-1]+cnt[2][1][i],mp2[1][i]='R';
	else
	dp[1][i]=1e9;
	for(i=2;i<=n;i++)
	for(j=2;j<=n;j++)
	if(a[i][j]!=0)
	dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cnt[2][i][j],mp2[i][j]=(dp[i-1][j]<dp[i][j-1]?'D':'R');
	else
	dp[i][j]=1e9;
	if(ans>dp[n][n])
	{
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		mp1[i][j]=mp2[i][j];
	}
	ans=min(dp[n][n],ans);
	printf("%d\n",ans);
	if(ans&&pd)
	{
		for(i=1;i<=x1-1;i++)
		putchar('D');
		for(j=1;j<=y1-1;j++)
		putchar('R');
		for(i=x1+1;i<=n;i++)
		putchar('D'); 
		for(j=y1+1;j<=n;j++)
		putchar('R');
		return 0;
	}
	print(n,n);
	return 0;
}

