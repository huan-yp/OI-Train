#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e6+10,mod=1e9+7,M=1e3+10;
int i,j,k,m,n,s,t;
int a[N],c[N],sum[N],dis[N],dp[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
signed main(){
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
//	read(n),read(m),cout<<n<<' '<<m<<endl;
	read(n),read(m);
	for(i=1;i<n;i++)read(a[i]),sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++)read(c[i]);
	int sm=1ll*a[1]*c[1]%mod,sm2=0;dis[1]=0;
	for(i=2;i<=n;i++){
		int pw=quick(sum[i-1],mod-2);
		dis[i]=(1ll*sm*pw+c[i])%mod;
		sm=(sm+1ll*(dis[i]+c[i])*a[i])%mod;
		dp[i]=(1ll*a[i-1]*dis[i-1]%mod*pw+1ll*pw*sm2)%mod;
		sm2=(sm2+1ll*dp[i]*a[i-1]%mod)%mod;
	}
	for(i=1;i<=m;i++){
		int u,v;read(u),read(v);
		if(u==v){puts("0");continue;}
		printf("%lld\n",(dis[u]+dis[v]-2ll*dp[min(u,v)+1]+mod*2)%mod);
	}
}

