#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
/*



*/
const int N=1e5+10;
int i,j,k,n,s,t,m;
int dp[N][4];
int val[N][4];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(val[i][1]),read(val[i][2]),read(val[i][3]);
	dp[1][1]=val[1][1];
	dp[1][2]=val[1][2];
	dp[1][3]=val[1][3];
	for(i=2;i<=n;i++)
	for(j=1;j<=3;j++)
	for(k=1;k<=3;k++)
	{
		if(k==j)continue;
		dp[i][j]=max(dp[i][j],dp[i-1][k]+val[i][j]);
	}
	printf("%d",max(dp[n][1],max(dp[n][2],dp[n][3])));
	return 0;
}

