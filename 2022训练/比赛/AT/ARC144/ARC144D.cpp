#include<bits/stdc++.h>
#define y1 y3647
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=3e5+10,mod=998244353;
int i,j,k,n,s,t,m,tp1,tp2;
int f[N],inv[N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=a*ret%mod;
		a=a*a%mod,s>>=1;
	}
	return ret;
}
int C(int n,int m){
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(k);f[0]=inv[0]=1;
	for(i=1;i<=n+1;i++)f[i]=f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	int ans=0,now=inv[n+1],flag=0;
	for(i=0;i<=n;i++){
		if(k+i+1<n+1)continue;
		if(flag==0){
			for(j=k+i+1;j>=1&&k+i+1-j<=n;j--)now=now*(j%mod)%mod;
			flag=1;
		}
		else{
			now*=(k+i+1)%mod;now%=mod;
			if(now==0)break;
			now*=quick((k+i+1-n-1)%mod,mod-2);now%=mod;
		}
		ans+=C(n,i)*now%mod;
	}
	cout<<ans%mod<<endl;
	return 0;
}


