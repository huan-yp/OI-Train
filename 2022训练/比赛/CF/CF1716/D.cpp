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
const int N=2e5+10,mod=998244353;
const int T=670;
int i,j,k,n,s,t,m,tp1,tp2;
int dp[N],sum[N],ans[N];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(k);
	dp[0]=1;sum[0]=1;
	for(i=1;i<=n;i++){
		if(i-k>=0)sum[i]+=sum[i-k];
	}
	for(j=0;j<T;j++){
		int p=j+k+1;
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			if(i-p+1>=0)Inc(dp[i],sum[i-p+1]);
			Inc(ans[i],dp[i]);
		}	
		sum[0]=0;
		for(i=1;i<=n;i++){
			sum[i]=dp[i];
			if(i-p>=0)Inc(sum[i],sum[i-p]);
		}
	}
	for(i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}


