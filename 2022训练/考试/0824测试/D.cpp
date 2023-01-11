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
const int N=2e5+10;
int i,j,k,n,s,t,m,df,top,ans=INF;
int col[N],fa[N],cnt[N],vis[N],ok[N];
int dfn[N],scc[N],st[N],sz[N],from[N];
vector<int> eo[N],e[N],e2[N];
map<int,int> mp[N];
void dfs(int u){
	for(auto v:eo[u]){
		if(v==fa[u])continue;
		fa[v]=u;dfs(v);
		if(mp[v].find(col[u])!=mp[v].end())e[col[u]].push_back(col[v]);
		if(mp[v].size()>mp[u].size())swap(mp[u],mp[v]);
		for(auto [key,val]:mp[v])mp[u][key]+=val;
	}
	mp[u][col[u]]++;
	if(mp[u][col[u]]!=cnt[col[u]])e[col[u]].push_back(col[fa[u]]);
}
int tarjan(int u){
	int low=dfn[u]=++df;st[++top]=u;
	for(auto v:e[u]){
		if(dfn[v]){
			if(!scc[v])cmin(low,dfn[v]);
		}
		else cmin(low,tarjan(v));	
	}
	if(low==dfn[u]){
		int v=u;s++;
		do scc[v=st[top--]]=s; while(v!=u);
	}
	return low;
}
signed main()
{
// 	freopen("city.in","r",stdin);
//	freopen("city.out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(k);
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		eo[x].push_back(y),eo[y].push_back(x);
	}
	for(i=1;i<=n;i++)read(col[i]),cnt[col[i]]++;
	dfs(1);
	for(i=1;i<=k;i++){
		if(scc[i])continue;
		tarjan(i);
	}
	for(i=1;i<=k;i++){
		sz[scc[i]]++;
		for(auto v:e[i]){
			if(scc[v]==scc[i])continue;
			ok[scc[i]]=1;
		}
	}
	
	for(i=1;i<=s;i++){
		if(ok[i])continue;
		cmin(ans,sz[i]);
	}
	cout<<ans-1<<endl;
	return 0;
}
