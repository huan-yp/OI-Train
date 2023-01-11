#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=305;
int i,j,k,n,s,t,m,s1,s2,s3;
double dp[N][N][N];
double solve(int x1,int x2,int x3)
{
	if(x1==0&&x2==0&&x3==0)return 0;
	if(dp[x1][x2][x3]>0) return dp[x1][x2][x3];
	if(x1)dp[x1][x2][x3]+=1.0*x1/n*solve(x1-1,x2,x3);
	if(x2)dp[x1][x2][x3]+=1.0*x2/n*solve(x1+1,x2-1,x3);
	if(x3)dp[x1][x2][x3]+=1.0*x3/n*solve(x1,x2+1,x3-1);
	dp[x1][x2][x3]+=1;
	dp[x1][x2][x3]*=1.0*n/(x1+x2+x3);
	return dp[x1][x2][x3];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	dp[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		int x;
		read(x);
		if(x==1)s1++;
		if(x==2)s2++;
		if(x==3)s3++;
	}
	printf("%0.9lf",solve(s1,s2,s3));
	return 0;
}


