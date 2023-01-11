#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LNF 2000000000000000000ll
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
const int N=20,M=110;
int i,j,k,n,s,t,m,b,ans=LNF;
int dp[2][1<<N];
struct fri{
	int x,k,mask;
	friend bool operator >(fri aa,fri bb)
	{
		return aa.k>bb.k;
	}
	friend bool operator <(fri aa,fri bb)
	{
		return aa.k<bb.k;
	}
}a[M];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(b);
	for(i=1;i<=n;i++)
	{
		read(a[i].x),read(a[i].k),read(s);
		for(j=1;j<=s;j++)
		{
			int x;
			read(x);
			a[i].mask|=1<<x-1;
		}
	}
	sort(a+1,a+n+1);
	for(i=0;i<1<<m;i++)
	dp[0][i]=dp[1][i]=LNF;
	
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(int mask=0;mask<1<<m;mask++)
		dp[i&1][mask]=LNF;
		for(int mask=0;mask<1<<m;mask++)	
		{
			dp[i&1][mask|a[i].mask]=min(dp[i&1][mask|a[i].mask],dp[(i-1)&1][mask]+a[i].x);
			dp[i&1][mask]=min(dp[(i-1)&1][mask],dp[i&1][mask]);
		}
		ans=min(ans,dp[i&1][(1<<m)-1]+a[i].k*b);
	}
	if(ans>=LNF)
	printf("-1");
	else
	printf("%lld",ans);
	return 0;
}


