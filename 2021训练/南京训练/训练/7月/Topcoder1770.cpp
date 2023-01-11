#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define vi vector<int>
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
const int N=10005,M=55;
int i,j,k,n,s,t,m;
double dp[M][N];
struct station{
	int pos,val;
	friend bool operator <(const station &a,const station &b)
	{
		return a.pos<b.pos;
	}
}a[M];
class GasStations{
	public:
	double tripCost(vi dist,vi price,int mpg,int tankSize,int tripLength)
	{
		k=mpg,m=tankSize,s=tripLength,n=dist.size();double ans=INF;
		
		if(m*k>=s)return 0.0;
		
		for(i=1;i<=n;i++)
		a[i].pos=dist[i-1],a[i].val=price[i-1];
		sort(a+1,a+n+1);
		
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=m*k;j++)
			{
				dp[i][j]=INF;
				for(int from=0;from<i;from++)
				{
					int need=j+a[i].pos-a[from].pos;
					if(need>m*k)continue;
					dp[i][j]=min(dp[i][j],dp[from][need]);
				}
				if(j==0)continue;
				dp[i][j]=min(dp[i][j],dp[i][j-1]+1.0*a[i].val/k);
			}
		}
		for(j=0;j<=m*k;j++)
		{
			dp[n+1][j]=INF;
			for(int from=0;from<=n;from++)
			{
				int need=j+s-a[from].pos;
				if(need>m*k)continue;
				dp[i][j]=min(dp[i][j],dp[from][need]);
			}
			ans=min(ans,dp[n+1][j]);
		}
		return ans;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	GasStations solve;
//	printf("%0.9lf",solve.tripCost({100,400},
//{1549,1649},
//25,
//16,
//600
//
//));
//	return 0;
//}

