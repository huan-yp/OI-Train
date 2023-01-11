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
const int N=1e3+10;
int i,j,k,n,s,t,m;
//dp[i-1][j-(i-pos)]->dp[i][j]
int dp[N][N*10],sum[N][N*10];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	sum[0][0]=dp[0][0]=1;
	read(n),read(m);
	for(i=1;i<=n;++i)
	{
		for(j=0;j<=m;++j)
		{
			sum[0][j]=1;
			dp[i][j]=(sum[i-1][j]-(j-(i-max(1,i-j))-1<0?0:sum[i-1][j-(i-max(1,i-j))-1])+10000)%10000;
			if(j==0)sum[i][j]=dp[i][j];
			else sum[i][j]=sum[i][j-1]+dp[i][j],sum[i][j]%=10000;
		}
	}
	cout<<dp[n][m];
	return 0;
}


