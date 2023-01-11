#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m;
int dp[7][1<<14][15];
int minu[7][1<<14][4],p[1<<14]={1};
vector<string> T;
int calc(int x,int y)
{
	return (T[x][y]=='1')+(T[x][m-y]=='1')+(T[n-x][y]=='1')+(T[n-x][m-y]=='1');
}
class 	PalindromeMatrix{
	public:
	int minChange(vector<string> A,int rowCount, int columnCount)
	{
		T=A;
		n=A.size()-1,m=A[0].length()-1;
		memset(dp,1,sizeof(dp));
		for(i=0;i<=n/2;i++)
		{
			for(s=0;s<1<<m+1;s++)//n,m不要写反 
			for(j=0;j<=m/2;j++)//0开始 
			{
				if(s==25)
				s=s;
				if(s&(1<<j)&&s&(1<<m-j))
				{
					minu[i][s][0]+=(A[i][j]!=A[n-i][j])+(A[i][m-j]!=A[n-i][m-j]);
					minu[i][s][3]+=min(4-calc(i,j),calc(i,j));
					minu[i][s][2]+=min(4-calc(i,j),calc(i,j));
					minu[i][s][1]+=min(4-calc(i,j),calc(i,j));
				}
				if(s&(1<<j)&&(s&(1<<m-j))==0)
				{
					minu[i][s][0]+=(A[i][j]!=A[n-i][j]);
					minu[i][s][1]+=(A[i][j]!=A[i][m-j]||A[i][j]!=A[n-i][j]);
					minu[i][s][2]+=(A[i][j]!=A[n-i][j]||A[n-i][j]!=A[n-i][m-j]);
					minu[i][s][3]+=min(4-calc(i,j),calc(i,j));
				}
				if((s&(1<<j))==0&&s&(1<<m-j))
				{
					minu[i][s][0]+=(A[i][m-j]!=A[n-i][m-j]);
					minu[i][s][1]+=(A[i][j]!=A[i][m-j]||A[i][m-j]!=A[n-i][m-j]);
					minu[i][s][2]+=(A[n-i][m-j]!=A[n-i][j]||A[n-i][m-j]!=A[i][m-j]);
					minu[i][s][3]+=min(4-calc(i,j),calc(i,j));
				}
				if((s&(1<<j))==0&&(s&(1<<m-j))==0)
				{
					minu[i][s][0]+=0;
					minu[i][s][1]+=(A[i][j]!=A[i][m-j]);
					minu[i][s][2]+=(A[n-i][j]!=A[n-i][m-j]);
					minu[i][s][3]+=(A[i][j]!=A[i][m-j])+(A[n-i][j]!=A[n-i][m-j]);
				}
			}
		}
		for(s=0;s<1<<m+1;s++)
		dp[0][s][1]=min(minu[0][s][1],minu[0][s][2]),dp[0][s][0]=minu[0][s][0],dp[0][s][2]=minu[0][s][3];
		for(i=0;i<n/2;i++)
		{
			for(s=0;s<1<<m+1;s++)
			{
				for(j=0;j<=rowCount;j++)
				{
					dp[i+1][s][j+0]=min(dp[i+1][s][j+0],minu[i+1][s][0]+dp[i][s][j]);
					dp[i+1][s][j+1]=min(dp[i+1][s][j+1],minu[i+1][s][1]+dp[i][s][j]);
					dp[i+1][s][j+1]=min(dp[i+1][s][j+1],minu[i+1][s][2]+dp[i][s][j]);
					dp[i+1][s][j+2]=min(dp[i+1][s][j+2],minu[i+1][s][3]+dp[i][s][j]);
				}
			}
		}
		int ans=1e9;
		for(i=0;i<1<<m+1;i++)
		if(__builtin_popcount(i)>=columnCount)
		ans=min(ans,dp[n/2][i][rowCount]);
		return ans;
	}
};
//signed main()
//{
//	PalindromeMatrix solve;
//	cout<<solve.minChange(
//{"000000000000"
//,"011101110111"
//,"010001010101"
//,"010001010101"
//,"011101010101"
//,"010101010101"
//,"010101010101"
//,"011101110111"
//,"000000000000"
//,"000000000000"},
//5,
//9
//);
//	return 0;
//}


