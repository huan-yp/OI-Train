#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=2e5+10,mod=998244353;
int i,j,k,n,s,t,m,ans;
int p[N],dep[N],f[N],inv[N],pre[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
int C(int n,int m){
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int solve(int x){
	int res=0;
	for(int i=x+1;i<=n;i++){
		res=(res+1ll*f[i-1]%mod*quick(n-i+1,mod-2)%mod*inv[i-1-x])%mod;
	}
	return 1ll*res*f[n-x]%mod;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);dep[1]=1;f[0]=inv[0]=1;ans=1;pre[1]=1;
	for(i=1;i<=n+1;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=2;i<=n;i++){
		read(p[i]),dep[i]=dep[p[i]]+1;
		ans=(0ll+ans+(pre[i]=(pre[p[i]]+quick(dep[i],mod-2))%mod))%mod;
	}
//	for(i=1;i<=n;i++){
//		ans=(ans+1ll*n*quick(i,mod-2)%mod*f[n])%mod;
//		ans=(ans-solve(dep[i])%mod)%mod;
//	}
//	cout<<1ll*(ans+mod)*inv[n]%mod<<endl;
	cout<<ans<<endl;
	return 0;
}


