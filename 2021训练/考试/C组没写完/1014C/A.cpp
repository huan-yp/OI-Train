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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=505;
int i,j,k,n,s,t,m;
int a[N],sum[N],dp[N][N];
int solve(int l,int r)
{
	if(dp[l][r]!=-1)return dp[l][r];
	if(l>r)return dp[l][r]=0;
	dp[l][r]=INF;
	for(int i=l;i<=r;i++)
	cmin(dp[l][r],max(sum[r]-sum[i]+solve(l,i-1),sum[i-1]-sum[l-1]+solve(i+1,r)));
	return dp[l][r];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);memset(dp,-1,sizeof(dp));
	for(i=1;i<=n;i++)read(a[i]),sum[i]=sum[i-1]+a[i];
	printf("%d",solve(1,n));
	return 0;
}

