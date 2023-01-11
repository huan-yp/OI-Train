#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1005,M=2*10005;
int i,j,k,n,t,m,s;
int dp[N][M];
struct block{
	int w,s,v;
	//w1+x<s2;
	//s1s
	friend bool operator <(block aa,block bb)
	{
		return aa.w+aa.s<bb.w+bb.s;
	}
}a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i].w),read(a[i].s),read(a[i].v);
	
	sort(a+1,a+n+1);
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	for(j=0;j<M;j++)
	{
		dp[i][j]=dp[i-1][j];
		if(a[i].s>=j-a[i].w&&j-a[i].w>=0)
		dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].w]+a[i].v);	
	}
	int ans=0;
	for(i=0;i<M;i++)
	ans=max(ans,dp[n][i]);
	
	cout<<ans;
	return 0;
}


