#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=2e5+10;
int i,j,k,m,n,s,t;
int dfn[N],dep[N],fa[N][20],rak[N],p[N];
vector<int> e[N];
void dfs(int u){
	dfn[u]=++t;rak[t]=u;
	for(int i=1;i<=18;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:e[u]){
		if(fa[u][0]==v)continue;
		dep[v]=dep[u]+1;
		fa[v][0]=u;dfs(v);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int p=dep[x]-dep[y];
	for(int i=0;i<18;i++)if(1<<i&p)x=fa[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
struct VTree{
	set<int> st;
	int dis;
	VTree(){
		st.insert(1);
	}
	void add(int x){
		if(x==1)return ;
		auto bg=st.lower_bound(dfn[x]+1);
		int p1=0,p2=0;
		if(bg!=st.end())p1=lca(rak[*bg],x);
		p2=lca(rak[*prev(bg)],x);
		if(dep[p1]<dep[p2])swap(p1,p2);
		dis+=(dep[x]-dep[p1])*2;
		st.insert(dfn[x]);
	}
}T[N];
namespace solve1{
	int pre[N],suf[N];
	void solve(){
		for(i=1;i<=n;i++){
			T[0].add(p[i]);
			pre[i]=T[0].dis;
		}
		for(i=n;i>=1;i--){
			T[1].add(p[i]);
			suf[i]=T[1].dis;
		}
		int ans=0;
		if(k==1){
			printf("%d\n",pre[n]);
			return ;
		}
		for(i=1;i<n;i++)cmax(ans,pre[i]+suf[i+1]);
		cout<<ans<<endl;
	}
}
namespace solve2{
	const int M=1e3+10;
	int dp[M][M],trans[M][M];
	void solve(){
		for(i=1;i<=n;i++){
			for(j=i;j<=n;j++){
				T[i].add(p[j]);
				trans[i][j]=T[i].dis;
			}
		}
		for(i=1;i<=n;i++)
		for(j=0;j<i;j++)
		for(s=1;s<=k;s++)
		cmax(dp[i][s],dp[j][s-1]+trans[j+1][i]);
		
		cout<<dp[n][k]<<endl;
	}
}
int main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	read(n),read(k);
	for(i=1;i<=n;i++)read(p[i]);
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(dep[1]=1);
	if(k<=2)
	solve1::solve();
	else
	solve2::solve();
	return 0;
}

