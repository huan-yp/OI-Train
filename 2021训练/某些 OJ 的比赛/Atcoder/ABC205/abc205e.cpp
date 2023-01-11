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
int i,j,k,n,s,t,m;
const int N=2e6+10,mod=1e9+7;
int f[N],inv[N];
int C(int n,int m)
{
	if(m>n)return 0;
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int quick(int aa,int ss)
{
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=1ll*aa*ret%mod;
		aa=1ll*aa*aa%mod;
		ss>>=1;
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(k);
	f[0]=inv[0]=1;
	for(i=1;i<N;i++)
	{
		f[i]=1ll*f[i-1]*i%mod;
		inv[i]=quick(f[i],mod-2);
	}
	if(m+k<n)
	printf("0");
	else
	printf("%d\n",(C(n+m,n)-C(n+m,n-k-1)+mod)%mod);
	return 0;
}


