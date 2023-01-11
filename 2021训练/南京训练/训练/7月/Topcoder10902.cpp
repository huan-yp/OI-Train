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
/*
不合法条件： 


*/
const int M=55,N=1005;
int i,j,k,m,n,s,t;
LL dp[2][N<<1][N<<1];
class TheMoviesLevelThreeDivOne{
	public:
	int solve(vector<int> a,vector<int> b)
	{
		memset(dp,0,sizeof(dp));
		int ret=0;
		dp[0][N][N]=1;
		for(i=0;i<n;i++)
		for(j=0;j<N<<1;j++)
		for(k=0;k<N<<1;k++)
		{
			if(dp[i&1][j][k]==0)continue;
			dp[(i&1)^1][j+a[i]-b[i]][min(k,j-b[i])]+=dp[i&1][j][k];
			dp[(i&1)^1][j+a[i]][k+a[i]]+=dp[i&1][j][k];
			dp[(i&1)][j][k]=0; 
		}	
		for(i=0;i<N<<1;i++)
		for(j=0;j<N;j++)
		ret+=dp[n&1][i][j];
		return ret;
	}
	LL find(vector<int> a,vector<int> b)
	{
		n=a.size();
		return (1ll<<n)-solve(a,b)-solve(b,a);
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	TheMoviesLevelThreeDivOne solve;
//	cout<<solve.find(	
//{4, 4},
//{4, 4}
//);
//	return 0;
//}

