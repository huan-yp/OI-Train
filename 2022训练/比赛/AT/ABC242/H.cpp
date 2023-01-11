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
const int N=404,mod=998244353;
int i,j,k,n,s,t,m,ans;
int dp[N][N][N],sum[N][N],l[N],r[N],f[N];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
	if(x<0)x+=mod;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1,a=1ll*a*a%mod;
	}
	return ret;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//dp[i][j][k]:考虑到前 i 个位置，上一个位置为 j，已经包含了 k 个区间的方案数
	//对于任意一个集合，求出包含它任意一个元素的区间的个数
	read(n),read(m);
	for(i=1;i<=m;i++)read(l[i]),read(r[i]);
	
	for(i=1;i<=m;i++)
	for(j=0;j<=n;j++)
	for(k=j;k<=n;k++)
	sum[j][k]+=l[i]>=j&&l[i]<=k&&r[i]>=k;
	

	dp[0][0][0]=-1;
	for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
	for(k=0;k<=m;k++){
		if(dp[i][j][k]==0)continue;
		Inc(dp[i+1][j][k],dp[i][j][k]);
		Inc(dp[i+1][i+1][k+sum[j+1][i+1]],-dp[i][j][k]);
	}
	//12,13,123
	for(i=1;i<=m;i++){
		int sum=0;
		for(j=1;j<=n;j++)Inc(sum,dp[n][j][i]);
		Inc(ans,1ll*sum*m%mod*quick(i,mod-2)%mod);
	}
	printf("%d\n",ans);
	return 0;
}

