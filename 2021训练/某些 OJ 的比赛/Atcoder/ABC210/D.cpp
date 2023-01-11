#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LNF 1000000000000000000ll
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
const int N=1005;
int i,j,k,n,s,t,m,ans=LNF;
int val[N],dp[N][N],a[N][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(k);
	for(j=0;j<=m+1;j++)
	val[j]=LNF;
	
	for(i=1;i<=n;i++)
	{
		a[i][0]=a[i][m+1]=LNF/2;
		for(j=1;j<=m;j++)
		read(a[i][j]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=m+1;j++)
		dp[i][j]=LNF;
		
		for(j=1;j<=m;j++)
		{
			dp[i][j]=min(dp[i][j-1]+k-a[i][j-1]+a[i][j],val[j]+k+a[i][j]);
			dp[i][j]=min(dp[i][j],a[i][j-1]+a[i][j]+k);
			ans=min(ans,dp[i][j]);
		}	
		for(j=0;j<=m+1;j++)
		dp[i][j]=LNF;
		
		for(j=m;j>=1;j--)
		{
			dp[i][j]=min(dp[i][j+1]+k-a[i][j+1]+a[i][j],a[i][j]+val[j]+k);
			dp[i][j]=min(dp[i][j],a[i][j+1]+a[i][j]+k);
			ans=min(ans,dp[i][j]);
		}
		for(j=1;j<=m;j++)
		val[j]=min(val[j]+k,a[i][j]);
	}
	cout<<ans;
	return 0;
}

