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
const int N=5e5+10; 
int i,j,k,n,s,t,m,tp1,tp2;
vector<int> e[N];
int dp[N],sz[N];
void dfs(int u,int fa=0){
	sz[u]=1,dp[u]=0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(fa==v)continue;
		dfs(v,u);
		sz[u]+=sz[v],cmax(dp[u],dp[v]);
	}
	dp[u]+=sz[u];
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(i=1;i<=n;i++)e[i].clear();
		for(i=1;i<n;i++){
			int x,y;read(x),read(y);
			e[x].push_back(y),e[y].push_back(x);
		}
		dfs(1);
		cout<<dp[1]<<endl;
	}



	return 0;
}


