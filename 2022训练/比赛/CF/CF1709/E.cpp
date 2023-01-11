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
int i,j,k,n,s,t,m,tp1,tp2,ans;
int fa[N],sz[N],son[N],a[N],sum[N];
vector<int> e[N];
set<int> st[N];
void pre_dfs(int u){
	sz[u]=1;
	for(auto v:e[u]){
		if(fa[u]==v)continue;
		fa[v]=u;sum[v]=sum[u]^a[v];
		pre_dfs(v),sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void redfs(int u,int flag=0){
	if(son[u]){
		redfs(son[u]);
		swap(st[son[u]],st[u]);
	//	cout<<*st[u].begin()<<endl;
	}
	if(st[u].find(sum[u]^a[u])!=st[u].end())flag=1;
	st[u].insert(sum[u]);
	for(auto v:e[u]){
		if(v==son[u]||v==fa[u])continue;
		redfs(v);
		for(auto val:st[v]){
			if(st[u].find(val^a[u])!=st[u].end())
			flag=1;
		}
		for(auto val:st[v])
		st[u].insert(val);
	}
	if(flag)ans++,st[u].clear();
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	sum[1]=a[1];
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	pre_dfs(1);
	redfs(1);

	cout<<ans<<endl;
	return 0;
}


