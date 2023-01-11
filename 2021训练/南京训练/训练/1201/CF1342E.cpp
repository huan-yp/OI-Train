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
const int N=2e5+10,mod=998244353;
int i,j,k,n,s,t,m;
int f[N],inv[N];
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;a=1ll*a*a%mod;
	}
	return ret;
}
int C(int n,int m)
{
	return 1ll*inv[n-m]*inv[m]%mod*f[n]%mod;
}
int S(int n,int k)
{
	int ret=0;
	for(i=0;i<=k;i++)
	ret+=1ll*C(k,i)*((k-i)%2?-1:1)*quick(i,n)%mod,ret%=mod;
	
	return (ret+mod)%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);f[0]=inv[0]=1;
	for(i=1;i<=n;i++)f[i]=1ll*i*f[i-1]%mod,inv[i]=quick(f[i],mod-2);
	if(k==0){printf("%lld\n",f[n]);return 0;}
	if(k>=n){printf("%lld\n",0);return 0;}
	
	printf("%lld",2ll*C(n,n-k)*S(n,n-k)%mod);

	return 0;
}

