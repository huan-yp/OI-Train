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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N = 1005,S = 5005;
int i,j,k,n,s,t,m,r,c;
double dp[S][N],p1[S],p2[S];
double ans;
double C(int x)
{
	double ret=1;int now=s;
	for(int i=1;i<=x;i++)
	{
		ret*=(s-i+1),ret/=i;
		while(ret>1&&now)
		ret*=0.5,now--;
	}
	while(now)
	ret*=0.5,now--;
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(r),read(c),read(s);r++,c++;
	dp[0][r]=1;p1[0]=1;
	for(i=1;i<=s;i++)
	for(j=1;j<=n;j++)
	dp[i][j]=dp[i-1][j+1]*0.5+dp[i-1][j-1]*0.5,p1[i]+=dp[i][j];

	memset(dp,0,sizeof(dp));
	dp[0][c]=1;p2[0]=1;
	for(i=1;i<=s;i++)
	for(j=1;j<=m;j++)
	dp[i][j]=dp[i-1][j+1]*0.5+dp[i-1][j-1]*0.5,p2[i]+=dp[i][j];
	
	for(i=0;i<=s;i++)
	{
		double p=C(i);
		ans+=p*p1[i]*p2[s-i];
	}
	printf("%0.9lf\n",ans);
	return 0;
}

