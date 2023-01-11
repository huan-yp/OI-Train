#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int mod=998244353,N=2005;
int i,j,k,n,s,t,m;
int x[N],y[N],a[N],b[N],c[N];
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod,s>>=1;
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)
	read(x[i]),read(y[i]);
	a[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=i;j>=1;j--)
		a[j]=(a[j-1]-a[j]*x[i])%mod;
		a[0]=-a[0]*x[i]%mod;
	}
	for(i=1;i<=n;i++)
	{
		int pi=1;b[0]=a[0]*quick(-x[i],mod-2)%mod;
		for(j=1;j<=n;j++)
		if(i!=j)pi=pi*(x[i]-x[j])%mod;
		pi=quick(pi,mod-2);
		for(j=1;j<n;j++)
		b[j]=(a[j]-b[j-1])%mod*quick(-x[i],mod-2)%mod;
		for(j=0;j<n;j++)
		c[j]+=y[i]*pi%mod*b[j]%mod,c[j]%=mod;
	}
	int ans=0,now=1;
	for(i=0;i<n;i++)
	{
		ans+=now*c[i]%mod,ans%=mod;
		now=now*k%mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}

