#include<bits/stdc++.h>
using namespace std;
#define cmax(a,b) a=max(a,b)
#define bf (nw^1)
int n,m,a[155][505],dp[2][12][155][155],s[155],tmp[155],sm[505][155],ans=-1e9-100;
int main()
{
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sm[i][j]=sm[i][j-1]+a[j][i];
		}
	}
	memset(dp,-0x3f,sizeof(dp));
	int nw=0;
	for(int x=1;x<=m;x++)
	{
		nw^=1;
		memset(dp[nw],-0x3f,sizeof(dp[nw]));
		//1
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				cmax(dp[nw][1][i][j],max(dp[bf][1][i][j],0)+sm[x][j]-sm[x][i-1]);
			}
		}
		if(x==1)
		{
			continue;
		}
		int nwmx=-1e9-100;
		//2
		for(int j=1;j<=n;j++)
		{
			nwmx=-1e9-100;
			for(int i=1;i<=j;i++)
			{
				cmax(dp[nw][2][i][j],nwmx+sm[x][j]-sm[x][i-1]);
				cmax(nwmx,dp[bf][1][i][j]);
			}
		}
		memset(s,-0x3f,sizeof(s));
		for(int j=n;j>=1;j--)
		{
			for(int i=1;i<=j;i++)
			{
				cmax(s[i-1],dp[bf][2][i][j]);
			}
			memset(tmp,-0x3f,sizeof(tmp));
			for(int i=0;i<=j;i++)
			{
				cmax(tmp[min(i+1,j)],s[i]);
			}
			nwmx=-1e9-100;
			for(int i=j;i>=1;i--)
			{
				cmax(nwmx,tmp[i]);
				cmax(dp[nw][2][i][j],max(nwmx,dp[bf][2][i][j])+sm[x][j]-sm[x][i-1]);
			}
		}
		//3
		for(int i=1;i<=n;i++)
		{
			nwmx=-1e9-100;
			for(int j=i;j<=n;j++)
			{
				cmax(dp[nw][3][i][j],max(nwmx,dp[bf][3][i][j])+sm[x][j]-sm[x][i-1]);
				cmax(nwmx,dp[bf][2][i][j]);
			}
		}
		//4
		nwmx=-1e9-100;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				cmax(nwmx,dp[bf][3][i][j]);
			}
		}
		cmax(nwmx,dp[bf][4][1][1]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				dp[nw][4][i][j]=nwmx;
			}
		}
		//5
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				cmax(dp[nw][5][i][j],dp[bf][4][i][j]+sm[x][j]-sm[x][i-1]);
			}
		}
		//6
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				cmax(dp[nw][6][i][j],max(dp[bf][5][i][j],dp[bf][6][i][j])+a[i][x]+a[j][x]);
			}
		}
		//7
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				cmax(dp[nw][7][i][j],dp[bf][6][i][j]+sm[x][j]-sm[x][i-1]);
			}
		}
		//8
		nwmx=-1e9-100;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				cmax(nwmx,dp[bf][7][i][j]);
			}
		}
		cmax(nwmx,dp[bf][8][1][1]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				dp[nw][8][i][j]=nwmx;
			}
		}
		//9
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				cmax(dp[nw][9][i][j],max(dp[bf][9][i][j],dp[bf][8][i][j])+a[i][x]+a[j][x]);
			}
		}
		//10
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				cmax(dp[nw][10][i][j],max(dp[bf][9][i][j],dp[bf][10][i][j])+sm[x][j]-sm[x][i-1]);
			}
		}
		//11
		for(int i=1;i<=n;i++)
		{
			for(int j=i+2;j<=n;j++)
			{
				cmax(dp[nw][11][i][j],max(dp[bf][10][i][j],dp[bf][11][i][j])+a[i][x]+a[j][x]);
				cmax(ans,dp[nw][11][i][j]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
