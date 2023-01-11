#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define int unsigned long long
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
//https://csacademy.com/contest/round-20/task/stepping-number
int i,j,k,n,s,t,m,base;
int dp[20][11][2],g[20];
int solve(int x)
{
	memset(dp,0,sizeof(dp));
	int cnt=0,ret=0;
	while(x)
	{
		g[++cnt]=x%10;
		x/=10;
	}
	for(i=1;i<=cnt/2;i++)swap(g[i],g[cnt-i+1]);
	for(i=1;i<g[1];i++)dp[1][i][0]=1;dp[1][g[1]][1]=1;
	for(i=2;i<=cnt;i++)
	{
		if(dp[i-1][g[i-1]][1]==1)
		{
			if((long long)g[i]-(long long)g[i-1]>=-1&&(long long)g[i]-(long long)g[i-1]<=1)
			dp[i][g[i]][1]=1;
			if(g[i-1])dp[i][g[i-1]-1][0]+=(g[i]>(g[i-1]-1));
			dp[i][g[i-1]][0]+=(g[i]>(g[i-1])),dp[i][g[i-1]+1][0]+=(g[i]>(g[i-1]+1));
		}
		for(j=0;j<=9;j++)
		{
			dp[i][j][0]+=(j!=0)+dp[i-1][j][0]+dp[i-1][j+1][0];
			if(j)dp[i][j][0]+=dp[i-1][j-1][0];
		}
	}
	for(i=0;i<=9;i++)
	ret+=dp[cnt][i][0]+dp[cnt][i][1];
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>k>>n;
	int l=n,r=(1ll<<62)+((1ll<<62)-1ll),ans;
	k+=solve(n);
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(solve(mid-1)<k)
		ans=mid,l=mid+1;
		else
		r=mid-1;
	}
	printf("%llu",ans);
	return 0;
}


