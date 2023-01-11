#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define earse erase
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
const int N=20;
int i,j,k,n,s,t,m;
int ans;
//dp[s][i]:状态为 s , 终点为 i 的方案数。
//因为会重复计算某个点 , 所以默认 s 中最小的为起点。 
//这样也省掉了枚举起点的复杂度 
int dp[1<<N-1][N];
int mp[N][N];
int low(int x)
{
	return x&(-x);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		mp[y][x]=mp[x][y]=1;
	}
	for(i=1;i<=n;i++)
	dp[1<<i-1][i]=1;
	for(i=1;i<1<<n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if((i&(1<<j-1))==0)continue;
			if(dp[i][j]==0)continue;
			for(k=1;k<=n;k++)
			{
				if((1<<k-1)<low(i))continue;
				if(mp[j][k]==0)continue;
				if(i&(1<<k-1))
				{
					if(low(i)==(1<<k-1)&&__builtin_popcount(i)>2)
					ans+=dp[i][j];
					continue;
				}
				dp[i|(1<<k-1)][k]+=dp[i][j];
			}
		}
	}
	cout<<ans/2; 
	return 0;
}


