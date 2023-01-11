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
const int N=100005,M=105,mod=1e9+7;
int i,j,k,n,s,t,m,tp1,tp2;
int dp[N][M][2][2],sz[N];
vector<int> e[N];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
}
void dfs(int u,int fa=0){
	sz[u]=1;
	dp[u][1][0][1]=1,dp[u][0][0][0]=1;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);sz[u]+=sz[v];
		for(i=min(k,sz[u]);i>=0;i--){
			int p00=0,p01=0,p10=0,p11=0;
			for(j=max(0,i-(sz[u]-sz[v]));j<=i&&j<=sz[v];j++){
				Inc(p00,1ll*dp[u][i-j][0][0]*dp[v][j][1][0]%mod);
				Inc(p01,1ll*dp[u][i-j][0][1]*(dp[v][j][0][0]+dp[v][j][1][0])%mod);
				Inc(p10,(1ll*dp[u][i-j][1][0]*(dp[v][j][1][0]+dp[v][j][1][1])+1ll*dp[u][i-j][0][0]*dp[v][j][1][1])%mod);
				Inc(p11,(1ll*dp[u][i-j][0][1]*(dp[v][j][0][1]+dp[v][j][1][1])+1ll*dp[u][i-j][1][1]*(0ll+dp[v][j][1][0]+dp[v][j][1][1]+dp[v][j][0][1]+dp[v][j][0][0]))%mod);
			}
			dp[u][i][0][0]=p00,dp[u][i][0][1]=p01;
			dp[u][i][1][0]=p10,dp[u][i][1][1]=p11;
		}
	}
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(k);
	for(i=1;i<n;i++){
		read(tp1),read(tp2);
		e[tp1].push_back(tp2),e[tp2].push_back(tp1);
	}
	dfs(1);
	int ans=0;
	for(i=k;i<=k;i++)
	Inc(ans,dp[1][i][1][0]),Inc(ans,dp[1][i][1][1]);
	cout<<ans;
	return 0;
}


