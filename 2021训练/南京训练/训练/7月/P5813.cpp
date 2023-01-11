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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=128;
int i,j,k,n,s,t,m,na,nb;
struct point{
	int ka,kb,ta,tb;
	int dp[2][N/2][N/2][N/2],ans[N][N];
	void calc()
	{
		memset(dp,31,sizeof(dp));
		memset(ans,31,sizeof(ans));
		dp[0][1][0][1]=ta+ka;
		dp[1][0][1][1]=tb+kb;
		
		for(i=0;i<=na;i++)
		for(j=0;j<=nb;j++)
		for(s=0;s<=1;s++)
		for(k=1;k<=(s?j:i);k++)
		{
			cmin(dp[s^1][i+s][j+(s^1)][1  ],dp[s][i][j][k]+(s?ta+ka:tb+kb));
			cmin(dp[s^0][i+(s^1)][j+s][k+1],dp[s][i][j][k]+(k*2+1)*(s?kb:ka));
			cmin(ans[i][j],dp[s][i][j][k]);
		}
	}
}a[N/4];
bitset<N> dp[N/4][N/2];
bitset<N> pre[N/4][N/2];
int check(int x)
{
	for(i=0;i<N/4;i++)
	for(j=0;j<N/2;j++)
	dp[i][j].reset();
	
	dp[0][0][0]=1;
	for(i=1;i<=n;i++)
	for(j=0;j<=na;j++)
	for(k=0;k<=nb;k++)
	pre[i][j][k]=(a[i].ans[j][k]<=x);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=na;j++)
		for(k=0;k<=nb;k++)
		{
			if(dp[i][j][k]==0)continue;
			for(int c1=0;j+c1<=na;c1++)
			dp[i+1][j+c1]|=pre[i+1][c1]<<k;
		}
		if(dp[i+1][na][nb])return 1;
	}
	return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int i,j;
	read(na),read(nb);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i].ta),read(a[i].tb),read(a[i].ka),read(a[i].kb);
	for(i=1;i<=n;i++)
	a[i].calc();

	int l=1,r=n*(2000)+(na*na*50+nb*nb*50)/n,ans;//
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check(mid))
		r=mid-1,ans=mid;
		else
		l=mid+1;
	}
	cout<<ans;
	return 0;
}
