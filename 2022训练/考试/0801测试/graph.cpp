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
const int N=1005,mod=1e9+7;
int i,j,k,n,s,t,m,tp1,tp2;
int dp[2][N][N],f[N];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
}
signed main()
{
 	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);f[0]=1;
	if(m<n){
		puts("0");
		return 0;
	}
	for(i=1;i<=n;i++)f[i]=1ll*f[i-1]*i%mod;
	dp[0][1][1]=1;
	for(i=0;i<m;i++){
		memset(dp[i+1&1][1],0,sizeof(dp[i+1&1][1]));
		for(j=1;j<=n&&j<=i+1;j++){
			memcpy(dp[i+1&1][j+1],dp[i&1][j],sizeof(dp[i&1][j]));
			unsigned long long sum=0;
			for(k=1;k<=j;k+=4){
				dp[i+1&1][j][k]=(dp[i+1&1][j][k]+1ll*dp[i&1][j][k]*(j-k))%mod;
				sum+=1ll*k*dp[i&1][j][k];
				dp[i+1&1][j][k+1]=(dp[i+1&1][j][k+1]+1ll*dp[i&1][j][k+1]*(j-k-1))%mod;
				sum+=1ll*(k+1)*dp[i&1][j][k+1];
				dp[i+1&1][j][k+2]=(dp[i+1&1][j][k+2]+1ll*dp[i&1][j][k+2]*(j-k-2))%mod;
				sum+=1ll*(k+2)*dp[i&1][j][k+2];
				dp[i+1&1][j][k+3]=(dp[i+1&1][j][k+3]+1ll*dp[i&1][j][k+3]*(j-k-3))%mod;
				sum+=1ll*(k+3)*dp[i&1][j][k+3];
			}
			Inc(dp[i+1&1][j][j],sum%mod);
		}
	}
	cout<<1ll*dp[m&1][n][n]*f[n-1]%mod;
	return 0;
}


