#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int mod=998244353;
int n,m;
int quick(int a,int s,int ret=1){
	a%=mod;
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
	int ans=0,i;
	int pd[100];
	memset(pd,0,sizeof(pd));
	for(auto v:{2,3,5,7,11,13,17,19,23,29,31,37,41,43})pd[v]=1;
	read(n),read(m);
	int prod=1,p=1;
	for(i=1;i<=43&&i<=n;i++){
		if(pd[i])p=p*i;
		prod=1ll*prod*((m/p)%mod)%mod;
		ans-=prod;
	}
	for(i=1;i<=n;i++){
		ans+=quick(m,i);
	}
	cout<<ans%mod<<endl;
	return 0;
}


