#include<bits/stdc++.h>
#define LL long long
#define low(x) ((x)&(-x))
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
int i,j,k,m,n,s,t;
const int N=55;
LL all[1<<24],mp[55];
int clz[1<<24],sum[1<<24],dp[1<<21];
//
int main()
{
	read(t);
	for(i=1;i<1<<24;i++)
	clz[i]=clz[i>>1]+1,sum[i]=sum[i-low(i)]+1;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(mp,0,sizeof(mp));
		read(n),read(m);int lst,ans=0;
		for(i=1;i<=m;i++)
		{
			int x,y;
			read(x),read(y);
			mp[x]|=1ll<<y-1;
			mp[y]|=1ll<<x-1;
		}
		for(i=1;i<=n;i++)
		mp[i]|=1ll<<i-1;
		
		if(n==1)
		{
			puts("1");
			continue;
		}
		all[0]=-1;
		if(n<=40)lst=n/2;
		else lst=24;
		for(int mask=1;mask<1<<lst;mask++)
		{
			all[mask]=all[mask-low(mask)]&mp[clz[low(mask)]];
			if((all[mask]|mask)!=all[mask])continue;
			cmax(dp[all[mask]>>lst],sum[mask]);
		}
		for(int mask=1;mask<1<<n-lst;mask++)
		all[mask]=all[mask-low(mask)]&(mp[clz[low(mask)]+lst]>>lst);
			
		for(int mask=(1<<n-lst)-1;mask>=0;mask--)
		{
			for(i=1;i<=n-lst;i++)
			cmax(dp[mask],dp[mask|(1<<i-1)]);
			if((all[mask]|mask)!=all[mask])continue;
			cmax(ans,dp[mask]+sum[mask]);		
		}
		cout<<ans<<endl;
	}
	return 0;
}

