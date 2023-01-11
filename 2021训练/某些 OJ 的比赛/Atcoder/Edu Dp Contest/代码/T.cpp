#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=3005,mod=INF+7;
int i,j,k,n,s,t,m;
int dp[N][N],sum[N];
char ch[N];
//dp[i][j]:考虑到第 i 个,还剩有 j 个比第 i 个数大.
//<:dp[i][j]->
//>: 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	scanf("%s",ch+1);
	for(i=0;i<n;i++)
	dp[1][i]=1;
	
	for(i=2;i<=n;i++)
	{
		sum[0]=dp[i-1][0];
		for(j=1;j<n;j++)
		sum[j]=sum[j-1]+dp[i-1][j],sum[j]%=mod;
		for(j=0;j<n;j++)
		{
			if(ch[i-1]=='<')
			{
				dp[i][j]=sum[n-1]-sum[j];
				dp[i][j]+=mod,dp[i][j]%=mod;
			}
			else
			{
				if(n-i+1-j<1)continue;
				dp[i][j]=sum[j];
			}
		}
	}
	cout<<dp[n][0];
	return 0;
}
