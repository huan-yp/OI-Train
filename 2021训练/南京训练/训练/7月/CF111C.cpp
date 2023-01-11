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
const int N=6,M=45;
const int full[]={0,1,3,7,15,31,63,127,255,511};
const int p[]={1,5,25,125,625,3125,15625};
int i,j,k,n,s,t,m;
int dp[M][1<<N][1<<N],mask[15625][3],cnt[1<<N*2];
void init()
{	
	for(i=1;i<1<<m*2;i++)
	cnt[i]=__builtin_popcount(i);
	
	for(i=0;i<p[6];i++)
	{
		for(j=1;j<=m;j++)
		{
			//0 上, 1 下, 2 左, 3 右 
			int g=i/p[j-1]%p[1];
			if(j==1&&g==2||j==m&&g==3)
			{
				mask[i][0]=-1;
				break;
			}
			mask[i][0]|=(g==0)<<j-1;//向上的 
			mask[i][1]|=(g==1)<<j-1;//向下的 
			if(g==2)
			mask[i][2]|=1<<j-2;//当前行 
			if(g==3)
			mask[i][2]|=1<<j;
			if(g==4)
			mask[i][2]|=1<<j-1;
		}
		if(mask[i][0]&full[6])continue;
		dp[1][mask[i][2]][mask[i][1]]=cnt[mask[i][2]];
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	if(m>n)swap(n,m);
	memset(dp,1,sizeof(dp));
	
	init(); 
	for(i=1;i<n;i++)
	{
		for(int mask1=0;mask1<1<<m;mask1++)
		for(int mask2=0;mask2<1<<m;mask2++)
		{
			if(dp[i][mask1][mask2]>40)continue;
			for(int mask3=0;mask3<p[m];mask3++)
			{
				if(mask[mask3][0]==-1)continue;
				int &x=dp[i+1][mask[mask3][2]|mask2][mask[mask3][1]];
				int val=dp[i][mask1][mask2]+cnt[mask[mask3][0]|mask1]-cnt[mask1];
				x=min(x,val+cnt[mask2|mask[mask3][2]]);
			}
		}
	}
	int ans=INF;
	for(i=0;i<1<<m;i++)
	ans=min(ans,dp[n][i][0]);
	
	cout<<n*m-ans;
	return 0;
}


