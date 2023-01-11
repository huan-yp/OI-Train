#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define low(x) (x)&(-x)
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
const int N=10,M=N*N;
int i,j,k,n,s,t,m;
int e[M][3],dp[1<<N][1<<N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(k);
	for(i=1;i<=m;i++)
	{
		read(e[i][1]),read(e[i][2]);
		e[i+m][1]=e[i][2],e[i+m][2]=e[i][1];
	}
	m*=2;
	for(i=1;i<=m;i++)
	{
		int u=e[i][1],v=e[i][2];
		dp[(1<<u-1)|(1<<v-1)][(1<<u-1)|(1<<v-1)]=1;
	}
	
	for(int mask1=0;mask1<1<<n;mask1++)
	for(int mask2=mask1;mask2;mask2=mask2-1&mask1)
	{
		if(dp[mask1][mask2]==0)continue;	
		for(i=1;i<=m;i++)
		{
			int u=e[i][1],v=e[i][2],val=mask2|(1<<v-1);
			if(((1<<u-1)&mask1)==0||((1<<v-1)&mask1))continue;
			if(mask2&(1<<u-1)) 
			val^=1<<u-1;
			if(32-__builtin_clz(val)!=v)continue;
			dp[mask1|(1<<v-1)][val]+=dp[mask1][mask2];
		}
	}
	int ans=0;
 	for(i=0;i<1<<n;i++)
	if(__builtin_popcount(i)==k)
	ans+=dp[(1<<n)-1][i];
	cout<<ans;
	return 0;
}


