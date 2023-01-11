#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=2e5+10;
int i,j,k,n,s,t,m;
int sz[N],fa[N],col[N],ans[N];
vector<int> e[N];
void dfs(int u){
	sz[u]=1;
	for(auto v:e[u]){
		if(fa[v]||v==1)continue;
		fa[v]=u;dfs(v);
		sz[u]+=sz[v];
	}
}
void make_col(int u,int c){
	col[u]=c;
	for(auto v:e[u]){
		if(fa[v]!=u)continue;
		make_col(v,c);
	}
}
void split(int u,int d=0){
	if(d==sz[u]){make_col(u,0);return;}
	if(d==-sz[u]){make_col(u,1);return ;}
	if(sz[u]==1){ans[++s]=u;return;}
	int s0=0,s1=d+sz[u]-1,ok=0;
	for(auto v:e[u]){
		if(fa[v]!=u)continue;
		if(!ok&&abs(s1-sz[v]-s0)<=sz[v]){
			ok=1;
			ans[++s]=u;
			split(v,s1-s0-sz[v]);
			continue;
		}
		s0+=sz[v],s1-=sz[v];
		make_col(v,ok);
	}
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	memset(col,-1,sizeof(col));
	read(n),read(m);
	for(i=1;i<=m;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1);
	split(1,0);
	printf("%d %d\n",s,(n-s)/2);
	for(i=1;i<=s;i++)printf("%d ",ans[i]);
	puts("");
	for(i=1;i<=n;i++)if(col[i]==0)printf("%d ",i);puts("");
	for(i=1;i<=n;i++)if(col[i]==1)printf("%d ",i);puts("");
	return 0;
}
