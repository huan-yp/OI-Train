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
const int N=1e6+10,mod=1e9+7;
int i,j,k,n,s,t,m,tp1,tp2;
int p[N],ip[N],ans[N],sum[N<<1];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);p[0]=ip[0]=1;p[1]=2;ip[1]=quick(2,mod-2);
	for(i=1;i<N;i++)p[i]=1ll*p[i-1]*p[1]%mod,ip[i]=1ll*ip[i-1]*ip[1]%mod;
	while(t--){
		read(n);
		int all=0;
		if(n==1){
			puts("1");
			continue;
		}
		ans[n]=ip[n-1>>1];sum[n]=ans[n];
		for(i=n-1;i>=2;i--){
			ans[i]=(ip[(i+1)/2]*(1ll-sum[2*i]))%mod;
			sum[i]=(sum[i+1]+ans[i])%mod;
	//		all+=ans[i];all%=mod;
		}
		for(i=1;i<=n;i++)printf("%d\n",(ans[i]+mod)%mod);
		for(i=1;i<=n;i++)sum[i]=0,ans[i]=0;
	}
	return 0;
}


