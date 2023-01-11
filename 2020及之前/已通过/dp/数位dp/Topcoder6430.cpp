#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m;
LL dp[20][2][2],g[20];
LL solve(int x)
{
	if(x<=0)return 0;
	memset(dp,0,sizeof(dp));
	int cnt=0;
	while(x)
	{
		g[++cnt]=x%10;
		x/=10;
	}
	for(i=1;i<=cnt/2;i++)
	swap(g[i],g[cnt-i+1]);
	dp[0][0][1]=0,dp[0][1][1]=1;
	for(i=1;i<=cnt;i++)
	{
		for(j=0;j<=9;j++)
		{
			if(j<g[i])
			dp[i][0][0]+=dp[i-1][0][1]+dp[i-1][1][1]*j,dp[i][1][0]+=dp[i-1][1][1];
			if(j==g[i])
			dp[i][0][1]=dp[i-1][0][1]+dp[i-1][1][1]*j,dp[i][1][1]=dp[i-1][1][1];
			dp[i][0][0]+=dp[i-1][0][0]+dp[i-1][1][0]*j,dp[i][1][0]+=dp[i-1][1][0];
		}
	}
	return dp[cnt][0][0]+dp[cnt][0][1];
}
class SumThemAll{
	public:
	long long getSum(int lowerBound,int upperBound)
	{
		return solve(upperBound)-solve(lowerBound-1);
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	SumThemAll so;
//	cout<<so.getSum(24660,308357171);
//	return 0;
//}


