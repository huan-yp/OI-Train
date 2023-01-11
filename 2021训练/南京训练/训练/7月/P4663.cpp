#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
/*



*/
int i,j,k,n,s,t,m;
int dp[65][65][2][2][2];
int charToInt(char ch)
{
	return ch=='X';
}
bool check(string x)
{
	int num=0;
	string rx=" ";
	for(i=1;i<n;i++)
	num+=x[i]!=x[i+1];
	for(i=n;i>=1;i--)
	rx+=x[i];
	return num<=m&&rx>=x;
}
int solve(string x)
{
	memset(dp,0,sizeof(dp));
	if(n==1)return s+1;
	if(s==n)return check(x);
	if(s)
	{
		if(x[1]=='X')
		dp[1][0][1][1][0]=1;
		else	
		dp[1][0][0][1][1]=1,dp[1][0][0][0][0]=1;
	}
	else
	dp[1][0][0][1][1]=dp[1][0][1][1][0]=dp[1][0][0][0][0]=1;
	for(i=1;i<n/2;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(s<=i||(s<n-i&&x[i+1]=='X')||(x[i+1]=='X'&&x[n-i]=='X'))
			{
				for(int x1=0;x1<=1;x1++)
				for(int x2=0;x2<=1;x2++)
				for(int t1=0;t1<=1;t1++)
				dp[i+1][j+(x1==0)+(x2==0)][1][1][t1]+=dp[i][j][x1][x2][t1];
			}
			if(s<=i||(s<n-i&&x[i+1]=='X')||(x[i+1]=='X'&&x[n-i]=='I'))
			{
				for(int x1=0;x1<=1;x1++)
				for(int x2=0;x2<=1;x2++)
				dp[i+1][j+(x1==0)+x2][1][0][1]+=dp[i][j][x1][x2][1];
			}
			if(s<=i||(s<n-i&&x[i+1]=='I')||(x[i+1]=='I'&&x[n-i]=='X'))
			{
				for(int x1=0;x1<=1;x1++)
				for(int x2=0;x2<=1;x2++)
				for(int t1=0;t1<=1;t1++)
				dp[i+1][j+x1+(x2==0)][0][1][1]+=dp[i][j][x1][x2][t1];
			}
			if(s<=i||(s<n-i&&x[i+1]=='I')||(x[i+1]=='I'&&x[n-i]=='I'))
			{
				for(int x1=0;x1<=1;x1++)
				for(int x2=0;x2<=1;x2++)
				for(int t1=0;t1<=1;t1++)
				dp[i+1][j+x1+x2][0][0][t1]+=dp[i][j][x1][x2][t1];
			}
		}
	}
	int ret=0;
	if(n%2)
	{
		for(i=0;i<=m;i++)
		for(int x0=0;x0<=1;x0++)
		for(int x1=0;x1<=1;x1++)
		for(int x2=0;x2<=1;x2++)
		{
			if(i-((x0!=x1)+(x0!=x2))<0||(x0!=charToInt(x[n/2+1])&&s>=n/2+1))continue;
			ret+=dp[n/2][i-((x0!=x1)+(x0!=x2))][x1][x2][0];
			ret+=dp[n/2][i-((x0!=x1)+(x0!=x2))][x1][x2][1];
		}
	}
	else
	{
		for(i=0;i<=m;i++)
		for(int x1=0;x1<=1;x1++)
		for(int x2=0;x2<=1;x2++)
		{
			if(i-(x1!=x2)<0)continue;
			ret+=dp[n/2][i-(x1!=x2)][x1][x2][1];
			ret+=dp[n/2][i-(x1!=x2)][x1][x2][0];
		}
	}
	s++;
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(k);
	string ans="";
	for(i=1;i<=n+1;i++)
	ans+=" ";
	if(solve(ans)<k)
	{
		printf("NO SUCH STONE\n");
		return 0;
	}
	for(t=1;t<=n;t++)
	{
		ans[t]='I';
		int tmp=solve(ans);
		if(tmp<k)
		ans[t]='X',k-=tmp;
	}
	for(i=1;i<=n;i++)
	cout<<ans[i];
	return 0;
}
