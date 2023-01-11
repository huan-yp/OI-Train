#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
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
const int mod=998244353,N=4e5+10;
int i,j,k,n,s,t,m,tp1,tp2;
int f[N],inv[N];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
}
int quick(int a,int s){
	int ret=1;
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
	read(n);f[0]=inv[0]=1;
	for(i=1;i<N;i++)
	f[i]=1ll*i*f[i-1]%mod,inv[i]=quick(f[i],mod-2);
	cout<<1ll*quick(2,n)*f[2*n]%mod*inv[n+1]%mod;
//	dp[0][0]=1;
//	for(i=0;i<n;i++){
//		for(j=2*i;j<=2*n;j++){
//			if(dp[i][j]==0)continue;
//			for(k=j+1;k<=2*n;k++)
//			Inc(dp[i+1][k],2ll*dp[i][j]*(n-i)%mod);
//		}
//	}
//	cout<<dp[n][2*n]<<endl;
	return 0;
}


