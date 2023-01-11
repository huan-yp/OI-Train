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
const int N=3e5+10,mod=998244353;
int i,j,k,n,s,t,m,tp1,tp2;
int dp[N],f[N];
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
	
	read(n);f[0]=1;
	dp[0]=1;dp[1]=quick(2,n);
	int ans=dp[0]+dp[1];
	for(i=2;i<=n+1;i++){
		dp[i]=1ll*dp[i-1]*(quick(2,n)-quick(2,i-2)+mod)%mod;
		dp[i]=1ll*dp[i]*quick(i,mod-2)%mod;
		ans+=dp[i],ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}


