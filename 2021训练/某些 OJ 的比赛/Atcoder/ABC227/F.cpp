#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=35;
int i,j,k,n,s,t,m,ans=1e18;
int a[N][N],dp[N][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(k);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	read(a[i][j]);
	for(int posx=1;posx<=n;posx++)
	for(int posy=1;posy<=m;posy++)
	{
		memset(dp,1,sizeof(dp));
		dp[1][1]=max(a[1][1]-a[posx][posy],0ll);
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(i!=1)dp[i][j]=min(dp[i][j],dp[i-1][j]+max(a[i][j]-a[posx][posy],0ll));
			if(j!=1)dp[i][j]=min(dp[i][j],dp[i][j-1]+max(a[i][j]-a[posx][posy],0ll));
		}
		cmin(ans,dp[n][m]+k*a[posx][posy]);
	}
	cout<<ans<<endl;
	return 0;
}

