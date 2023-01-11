#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
const int N=18;
int i,j,k,n,s,t,m;
double dp[1<<N],a[N+10][N+10];
inline int low(int x)
{
	return x&(-x);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%lf",&a[i][j]);

	dp[0]=1;
	
	for(int mask=0;mask<1<<n;mask++)
	{
		const int cnt=n-__builtin_popcount(mask);
		const double chose=1.0/(cnt*(cnt-1)/2);
		for(i=1+0;i<=n;i++)
		for(j=i+1;j<=n;j++)
		{
			if(mask&(1<<j-1)||mask&(1<<i-1))continue;
			dp[mask|(1<<j-1)]+=chose*dp[mask]*a[i][j];
			dp[mask|(1<<i-1)]+=chose*dp[mask]*a[j][i];
		}
	}
	for(i=1;i<=n;i++)
	printf("%0.6lf ",dp[((1<<n)-1)^(1<<i-1)]);
	return 0;
}


