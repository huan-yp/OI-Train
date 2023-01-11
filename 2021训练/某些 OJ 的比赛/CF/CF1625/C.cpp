#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=505;
int i,j,k,n,s,t,m,l;
int d[N],a[N],dp[2][N][N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dp,63,sizeof(dp));
	read(n),read(l),read(k);
	for(i=1;i<=n;i++)read(d[i]);
	for(i=1;i<=n;i++)read(a[i]);
	
	dp[1][0][1]=0;d[n+1]=l;
	for(i=1;i<=n;i++)
	{
		memset(dp[(i+1)&1],63,sizeof(dp[(i+1)&1]));
		for(j=0;j<=k&&j<=i-1;j++)
		for(s=i;s>=i-j;s--)
		{
			//remove
			if(j+1<=k)cmin(dp[(i+1)&1][j+1][s],dp[i&1][j][s]+(d[i+1]-d[i])*a[s]); 
			//not remove
			cmin(dp[(i+1)&1][j][i+1],dp[i&1][j][s]+(d[i+1]-d[i])*a[s]); 
		}
	}
	int ans=INF+1;
	for(i=0;i<=k;i++)
	for(j=n+1;j>=n+1-i;j--)
	cmin(ans,dp[(n+1)&1][i][j]);
	cout<<ans<<endl;
	return 0;
}

