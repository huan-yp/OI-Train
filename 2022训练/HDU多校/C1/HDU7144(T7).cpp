#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
#define mem(a) memset((a),0,sizeof(a))
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
int i,j,k,n,s,t,m,tp1,tp2,q;
int b[N],dfn[N],rak[N];
LL a[N];
void update(int x,int c){
	for(;x<=s;x+=x&-x)
	a[x]+=c;
}
LL query(int x,LL ret=0){
	for(;x;x-=x&-x)ret+=a[x];
	return ret;
}
void updata(int l,int r,int rt,int x,int c){
	update(x,c);
}
LL quert(int l,int r,int rt,int x,int y){
	return query(y)-query(x-1);
}
void build(int l,int r,int rt){
	memset(a,0,sizeof(a));
	for(i=1;i<=s;i++)
	updata(1,s,1,dfn[i],b[i]);
}
namespace Solve{
	int tot;
	int w[N],son[N][2],fa[19][N],dep[N],sz[N];
	int type[N],val[N],tre[N][11];
	bool cmp(int x,int y){
		return dfn[x]<dfn[y];
	}
	int lca(int x,int y){
		if(dep[y]>dep[x])swap(x,y);
		int p=dep[x]-dep[y];
		for(int i=18;i>=0;i--)if(1<<i&p){
			x=fa[i][x];
		}	
		if(x==y)return x;
		for(int i=18;i>=0;i--)if(fa[i][x]!=fa[i][y])
		x=fa[i][x],y=fa[i][y];
		
		return fa[0][x];
	}
	void dfs(int u){
		if(u==0)return ;
		sz[u]=1;dfn[u]=++tot,rak[tot]=u;
		for(i=1;i<=18;i++)
		fa[i][u]=fa[i-1][fa[i-1][u]];
		
		dep[son[u][0]]=dep[son[u][1]]=dep[u]+1;
		dfs(son[u][0]);dfs(son[u][1]);
		sz[u]+=sz[son[u][0]],sz[u]+=sz[son[u][1]]; 
	}
	int find(int u,int maxn){
		for(int i=18;i>=0;i--){
			if(fa[i][u]!=0&&w[fa[i][u]]<=maxn)
			u=fa[i][u];
		}
		return u;
	}
	struct Tree{
		signed rk[22],inc[22],st[22];
		int rt,top,tot;
		vector<int> e[22];
		int dfs(int u,int min_v=INF,int max_v=0){	
			for(int i=0;i<e[u].size();i++){
				int v=e[u][i];
				int vl=dfs(v);
				cmin(min_v,vl);cmax(max_v,vl);
			}
			int incu=e[u].size()?-min_v:max_v=val[rk[u]];
			if(incu!=inc[u]){
				updata(1,s,1,dfn[rk[u]],-inc[u]);b[rk[u]]-=inc[u];
				updata(1,s,1,dfn[rk[u]],inc[u]=incu),b[rk[u]]+=inc[u];
			}
			return max_v;
		}
		int init_dfs(int u,int min_v=INF,int max_v=0){
			for(int i=0;i<e[u].size();i++){
				int v=e[u][i];
				int vl=init_dfs(v);
				cmin(min_v,vl);cmax(max_v,vl);
			}
			int incu=e[u].size()?-min_v:max_v=val[rk[u]];
			b[rk[u]]+=inc[u]=incu;
			return max_v;
		}
		void build(){
			for(int i=0;i<=21;i++)e[i].clear();
			auto a=tre[i];sort(a+1,a+a[0]+1,cmp);
			st[++top]=tot=1;rk[1]=a[1];
			for(int i=2;i<=a[0];i++){
				int lc=lca(rk[st[top]],a[i]);
				while(top>1&&dfn[lc]<=dfn[rk[st[top-1]]]){
					e[st[top-1]].push_back(st[top]);
					top--;
				}
				if(lc!=rk[st[top]]){
					rk[++tot]=lc;e[tot].push_back(st[top]);
					st[top]=tot;
				}
				rk[++tot]=a[i],st[++top]=tot;
			}
			while(top>1){
				e[st[top-1]].push_back(st[top]);
				top--;
			}
			rt=st[top--];
			init_dfs(rt);
		}
	}T[N];
	void solve(int test){
		mem(T);
		tot=0;dep[s]=1;dfs(s);		
		
		for(i=1;i<=n;i++)
		T[i].build();
	
		build(1,s,1);
		for(i=1;i<=q;i++){
			int op,x,y;
			read(op),read(x),read(y);
			if(op==0){
				val[x]+=y;
				T[type[x]].dfs(T[type[x]].rt);
			}
			else{
				int pos=find(x,y);
				printf("%lld\n",quert(1,s,1,dfn[pos],dfn[pos]+sz[pos]-1));
			}
		}
	}
}
namespace Kruscal{
	int fa[N];
	int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	struct edge{
		int val,u,v;
		friend bool operator <(edge a,edge b){
			return a.val<b.val;
		}
		void init(){
			read(u),read(v),read(val);
		}
		void add(){
			u=find(u),v=find(v);
			if(u==v)return ;
			fa[u]=fa[v]=++s;fa[s]=s;
			using Solve::son;
			using Solve::fa;
			fa[0][u]=fa[0][v]=s;son[s][0]=u,son[s][1]=v;
			Solve::w[s]=val;
		}
	}e[N];
	void kru(){
		using Solve::son;
		mem(son);
		for(i=1;i<=n+1;i++)fa[i]=i;
		for(i=1;i<=m;i++)e[i].init();
		sort(e+1,e+m+1);s=n;
		for(i=1;i<=m;i++)e[i].add();
		Solve::fa[0][find(1)]=0;
	}
}
signed main()
{
	read(t);
	while(t--){
		read(n),read(m),read(q);
		using Solve::val;
		using Solve::tre;
		using Solve::type;
		mem(tre),mem(b);
		for(i=1;i<=n;i++){
			read(type[i]);
			tre[type[i]][++tre[type[i]][0]]=i;
		}
		for(i=1;i<=n;i++)read(val[i]);
		Kruscal::kru();
		Solve::solve(t);
	}
	return 0;
}


