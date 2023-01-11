#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000ll
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
const int N=55;
LL i,j,k,n,s,t,m,minu=0,maxn=-INF*INF,ans=0;
LL val[N][2],a[N],sum[N],dp[N],dis[N];
class RowGame{
	public:
	LL score(vector<int> board,int K)
	{
		k=K;n=board.size();
		for(i=1;i<=n;i++)
		dis[i]=INF;
		for(i=1;i<=n;i++)
		{
			minu=min(minu,sum[i]);
			a[i]=board[i-1],sum[i]=sum[i-1]+a[i];
		}
		for(i=n;i>=1;i--)
		{
			maxn=max(maxn,sum[i]);
			val[i][1]=maxn-sum[i-1];
		}
		//
		//
		//
		dis[1]=0;
//		for(i=1;i<=n;i++)
//		{
//			for(j=i+1;j<=n;j++)
//			{
//				LL need=val[j][1]+(sum[j-1]-sum[i-1]);
//				LL l=0,r=k,opt=-1;
//				while(r>=l)
//				{
//					int mid=(l+r)/2;
//					if(dp[i]+val[i][1]*2*mid+need>=0)
//					r=mid-1,opt=mid;
//					else
//					l=mid+1;
//				} 
//				LL d=dis[i]+2*opt+2,w=opt*2*val[i][1]+dp[i]+need+val[j][1];
//				if(opt==-1)continue;
//				if(dis[j]>d||(dis[j]==d&&dp[j]<w))
//				dis[j]=d,dp[j]=w;
//			}
//		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(j==i)continue;
				LL need;
				if(j>i)
				need=val[j][1]+(sum[j-1]-sum[i-1]);
				else
				need=val[i][1]*2-(sum[i-1]-sum[j-1]);
				
				LL l=0,r=k,opt=-1;
				while(r>=l)
				{
					int mid=(l+r)/2;
					if(dp[i]+val[i][1]*2*mid+need>=0)
					r=mid-1,opt=mid;
					else
					l=mid+1;
				} 
				LL d=dis[i]+2*opt+2,w=opt*2*val[i][1]+dp[i]+need+val[j][1];
				if(opt==-1)continue;
				if(dis[j]>d||(dis[j]==d&&dp[j]<w))
				dis[j]=d,dp[j]=w;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(dis[i]>k)continue;
			ans=max(ans,dp[i]+val[i][1]*(k-dis[i]));
		}
		return ans;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	RowGame solve;
//	cout<<solve.score(	
//{7, -221771379, -194580718, -156070137, 12, 6, 3, -209077926, 10, 13, -286798365, -236599601, -334030091, -255803307, 4, 4, 11, 6, 1, -307029796, -312701340, -241036688, 18, 5, 1, 17, 17, -283995862, 8, 4, 9, 12, -292493953, -257516915, -382451663, 1, 2, 3, -111786687, -162718458, -21071263, -43911817, 16, -81084483, -117350141, -215706663, -11822263, -5229982, 1, 1}, 334156991);
//	return 0;
//}

