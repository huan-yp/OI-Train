#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
const int N=1e6+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int f[N]={1},inv[N]={1};
int quick(int aa,int ss)
{
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=1ll*ret*aa%mod;
		aa=1ll*aa*aa%mod;
		ss>>=1;
	}
	return ret;
}
int C(int x,int y)
{
	if(y>x||y<0)return 0;
	if(x<0)return 1;
	return 1ll*f[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>n;
	for(i=1;i<=n+2;i++)
	f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	int ans=0;
	for(i=0+n%2;i<=n;i+=2)
	{
		ans+=2ll*f[n-i]%mod*C(n-i-1,i-1)%mod;
		ans%=mod;
		ans+=2ll*f[n-i]%mod*C(n-i,i)%mod;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}


