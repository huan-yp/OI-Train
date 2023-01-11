#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e6+10,mod=1e9+7; 
int i,j,k,n,s,t,m,prod=1,ans=0;
int f[N],a[N],b[N],fun[N],inv[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	fun[0]=inv[0]=1;
	read(n),read(k);prod=n;
	if(k+1>=n){
		int ans=0;
		for(i=1;i<=n;i++)ans+=quick(i,k),ans%=mod;
		cout<<ans<<endl;
		return 0;
	}
	for(i=1;i<=k+1;i++)fun[i]=1ll*fun[i-1]*i%mod,inv[i]=quick(fun[i],mod-2);
	for(i=1;i<=k+1;i++)
	f[i]=(f[i-1]+quick(i,k))%mod,prod=1ll*prod*(n-i)%mod;
	for(i=1;i<=k+1;i++){
		int fz=1ll*prod*quick(n-i,mod-2)%mod,fm=1ll*fun[i]*fun[k+1-i]*((k+1-i)%2?-1:1)%mod;
		ans+=1ll*f[i]*fz%mod*quick(fm,mod-2)%mod;
		ans%=mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}

