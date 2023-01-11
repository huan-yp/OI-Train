#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int __int128
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
const int N=4005,mod=998244353;
int i,j,k,n,m,q,V;
int dp[N],f[N],inv[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;a=1ll*a*a%mod;
	}
	return ret;
}
int C(int n,int m){
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int IC(int n,int m){
	return 1ll*inv[n]*f[m]%mod*f[n-m]%mod;
}
int solve(int q,int k){
	q+=k;
	if(q==0&&k==0)return 1;
	return C(q-k-1,k-1);
}
signed main()
{
 	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
//	freopen(".in","w",stdout);
//	cout<<quick(16,mod-2)*39%mod<<endl;
	inv[0]=f[0]=1;
	for(i=1;i<N;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	read(n),read(q),read(k),read(V);
	V=1ll*(V+1)*quick(2,mod-2)%mod;
	int ans=0;
	for(j=1;j<=k;j++){
		int p;read(p);
		int r=quick(2ll*n*n%mod,mod-2);
		int e=(2ll*p*(n-p+1)%mod-1)*r%mod;
		
		for(i=1;i<=q-k;i++)
		dp[i]=(dp[i-1]*(1-e)+2*e*V)%mod;
		
		r=quick(solve(q-k,k),mod-2);
		int sum=0,as=0;
		for(i=0;i<=q-2*k;i++){
//			if(j==k&&i+j!=q-k)continue;
			sum+=1ll*solve(i+j,j)%mod*solve(q-k-i-j,k-j)%mod;
			as+=dp[j+i]%mod*solve(i+j,j)%mod*solve(q-k-i-j,k-j)%mod;
		}
		as%=mod;
		ans+=1ll*as*r%mod;
	//	cout<<(1ll*as*r%mod+mod)%mod<<endl;
	}
	cout<<(signed((ans%mod+mod)%mod));
//	printf("%lld\n",(ans%mod+mod)%mod);
	return 0;
}


