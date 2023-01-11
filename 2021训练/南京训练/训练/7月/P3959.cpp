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
const int N=1<<12,M=15;
int i,j,k,n,s,t,m;
int mp[M][M],e[N][3],dp[N][M],g[N][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	memset(mp,1,sizeof(mp));
	for(i=1;i<=m;i++)
	{
		int x,y,c;
		read(x),read(y),read(c);
		mp[x][y]=min(mp[x][y],c);
		mp[y][x]=min(mp[y][x],c);
	}
	for(int mask=1;mask<1<<n;mask++)
	for(int mask2=(mask-1)&mask;mask2;mask2=(mask2-1)&mask)
	{
		for(i=1;i<=n;i++)
		{
			if((mask2&(1<<i-1))==0)continue;
			int minu=INF;
			for(j=1;j<=n;j++)
			if((1<<j-1)&(mask2^mask))
			minu=min(minu,mp[i][j]);
			
			g[mask^mask2][mask2]+=minu;
		}
	}
	int ans=INF;
	for(k=0;k<n;k++)
	for(int mask=0;mask<1<<n;mask++)
	dp[mask][k]=INF;
	
	for(k=1;k<=n;k++)
	dp[1<<k-1][0]=0;
	for(k=0;k<n-1;k++)
	{
		for(int mask1=0;mask1<1<<n;mask1++)	
		{
			if(dp[mask1][k]>=INF)continue;
			int val=((1<<n)-1)^mask1;
			for(int mask2=val;mask2;mask2=(mask2-1)&val)
			dp[mask1|mask2][k+1]=min(dp[mask1|mask2][k+1],dp[mask1][k]+g[mask1][mask2]*(k+1));
		}
	}
	for(k=0;k<n;k++)
	ans=min(ans,dp[(1<<n)-1][k]);
	cout<<ans;
	return 0;
}
