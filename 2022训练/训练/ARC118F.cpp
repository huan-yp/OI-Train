#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=1005,mod=998244353;
int i,j,k,n,s,t,lim=1,deg,m;
int a[N],x[2][N],y[2][N],tmp[2][N],f[N],inv[N],pre[N],suf[N];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
	if(x<0)x+=mod;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1,a=1ll*a*a%mod;
	}
	return ret;
}
int interpolation(int val){
	int res=0;pre[0]=(val-x[1][0])%mod,suf[deg+1]=1;
	for(k=1;k<=deg;k++)pre[k]=1ll*pre[k-1]*(val-x[1][k])%mod;
	for(k=deg;k>=0;k--)suf[k]=1ll*suf[k+1]*(val-x[1][k])%mod;
	Inc(res,1ll*suf[1]*inv[deg]%mod*y[1][0]%mod);
	for(k=1;k<=deg;k++)
	Inc(res,1ll*y[1][k]*pre[k-1]%mod*suf[k+1]%mod*inv[k]%mod*inv[deg-k]*(k&1?-1:1)%mod);
	
	return res;
}
signed main()
{
	//submit
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	f[0]=inv[0]=1;
	read(n),read(m);deg=2;
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=n+4;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=0;i<=deg;i++)x[1][i]=(m-i)%mod,y[1][i]=i+1;
	
	for(i=n;i>=1;i--){
		m/=a[i];
		if(a[i]==1){
			x[1][deg+1]=(m-(deg+1)+mod)%mod;
			y[1][deg+1]=interpolation(x[1][deg+1]);
			deg++;
			for(j=1;j<=deg;j++)Inc(y[1][j],y[1][j-1]);
			continue;
		}
		for(j=0;j<=deg+1;j++){
			y[0][j]=interpolation(1ll*(m-j+mod)*a[i]%mod);
			if(j)Inc(y[0][j],y[0][j-1]);
		}
		deg++;
		for(j=0;j<=deg;j++)x[1][j]=(m-j+mod)%mod,y[1][j]=y[0][j];
	}
	printf("%lld\n",interpolation(1));
	return 0;
}

