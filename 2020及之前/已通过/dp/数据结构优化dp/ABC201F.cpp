#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#define y1 y3647
#define next nxt
#define int long long
#define low(x) (x)&(-x)
#define min(a,b) a<b?a:b
using namespace std;
//dp[i]=min(dp[j]+pre[i]-pre[j])
//ans=min(dp[i]+suf[i+1])
const int N=2e5+10;
int i,j,k,n,s,t,m,ans=1e16;
int pre[N],suf[N],a[N],b[N],C[N],c[N],pos[N],val[N],sum[N],dp[N];
void updata(int x,int cc)
{
	for(int i=x;i<=n;i+=low(i))
	c[i]=min(c[i],cc);
}
int quert(int x,int ret=2e16)
{
	for(int i=x;i>=1;i-=low(i))
	ret=min(ret,c[i]);
	return ret;
}
signed main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&val[i]);
		pos[val[i]]=i;
		c[i]=2e16;
	}
	for(i=1;i<=n;i++)
	scanf("%lld%lld%lld",&a[i],&b[i],&C[i]);
	
	for(i=1;i<=n;i++)
	b[i]=min(b[i],a[i]),C[i]=min(C[i],a[i]);
	for(i=1;i<=n;i++)
	pre[i]=pre[i-1]+a[i],sum[i]=sum[i-1]+b[i];
	for(i=n;i>=1;i--)
	suf[i]=suf[i+1]+C[i];
	for(i=1;i<=n;i++)
	{
		dp[i]=pre[i-1]+quert(pos[i]);
		dp[i]=min(dp[i],sum[i-1]);
		updata(pos[i],dp[i]-pre[i]);
	}
	for(i=1;i<=n;i++)
	ans=min(ans,dp[i]+suf[i+1]);
	cout<<ans;
	return 0;
}

