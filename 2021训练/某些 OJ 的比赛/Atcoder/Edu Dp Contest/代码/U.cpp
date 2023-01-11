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
//https://atcoder.jp/contests/dp/tasks/dp_u
const int N=16;
int i,j,k,n,s,t,m,val1,val2,cnt;
int a[N+5][N+5];
long long g[1<<N],dp[1<<N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	read(a[i][j]);
	
	for(int mask=1;mask<1<<n;mask++)
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	if((1<<i-1)&mask&&(1<<j-1)&mask)
	g[mask]+=a[i][j];
	
	for(int mask=1;mask<1<<n;mask++)
	{
		for(int mask2=mask;mask2;mask2=(mask2-1)&mask)
		dp[mask]=max(dp[mask],dp[mask^mask2]+g[mask2]);
	}
	printf("%lld",dp[(1<<n)-1]);
	return 0;
}


