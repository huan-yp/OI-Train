#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
/*



*/
const int N=2e5+10;
int i,j,k,n,s,t,m,ans;
int c[N],a[N],h[N],dp[N];
void updata(int x,int cc)
{
	for(int i=x;i<=n;i+=low(i))
	c[i]=max(c[i],cc);
}
int quert(int x,int ret=0)
{
	for(int i=x;i;i-=low(i))
	ret=max(ret,c[i]);
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(h[i]);
	for(i=1;i<=n;i++)
	read(a[i]);
	for(i=1;i<=n;i++)
	{
		dp[i]=quert(h[i])+a[i];
		updata(h[i],dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%lld",ans);
	return 0;
}

