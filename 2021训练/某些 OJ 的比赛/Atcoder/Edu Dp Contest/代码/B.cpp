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



*/
const int N=1e5+10; 
int i,j,k,n,s,t,m;
int dp[N],h[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)
	read(h[i]),dp[i]=INF;
	dp[1]=0;
	for(i=1;i<=n;i++)
	for(j=1;j+i<=n&&j<=k;j++)
	dp[i+j]=min(dp[i+j],dp[i]+abs(h[i+j]-h[i]));
	cout<<dp[n];
	return 0;
}

