#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=2e5+10;
int i,j,k,m,n,s,t;
struct statu{
	int v[2],maxn;
	statu(){v[0]=v[1]=maxn=0;}
	void init(){v[0]=v[1]=maxn=0;}
	friend statu operator +(statu a,statu b){
		cmax(a.maxn,b.maxn);
		if(b.v[0]>a.v[0])swap(b.v[0],a.v[0]);
		if(b.v[0]>a.v[1])swap(b.v[0],a.v[1]);
		if(b.v[1]>a.v[1])a.v[1]=b.v[1];
		return a;
	}
	int final(){
		cmax(maxn,(++v[0])+v[1]);
		return v[1]=0,maxn;
	}
};
int fa[N][20],dep[N];
statu from[N],ans[N];
vector<int> e[N];
vector<statu> pre[N],suf[N];
void dfs(int u){
	for(int i=1;i<=18;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	pre[u].resize(e[u].size());suf[u].resize(e[u].size());
	e[u].erase(find(e[u].begin(),e[u].end(),fa[u][0]));
	for(int i=0;i<(int)e[u].size();i++){
		int v=e[u][i];
		dep[v]=dep[u]+1;fa[v][0]=u;
		dfs(v);
		pre[u][i]=ans[u]=ans[u]+ans[v];
	}
	ans[u].init();
	for(int i=((int)e[u].size())-1;i>=0;i--){
		int v=e[u][i];
		suf[u][i]=ans[u]=ans[u]+ans[v];
	}
	ans[u].final();
}
void redfs(int u){
	if(e[u].size()){
		from[e[u][0]]=suf[u][1]+from[u];
		from[e[u][0]].final();redfs(e[u][0]);
	}
	for(int i=1;i<(int)e[u].size();i++){
		from[e[u][i]]=suf[u][i+1]+pre[u][i-1]+from[u];
		from[e[u][i]].final();redfs(e[u][i]);	
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int p=dep[x]-dep[y];
	for(int i=0;i<=18;i++)if(1<<i&p)x=fa[x][i];
	if(x==y)return x;
	for(int i=18;i>=0;i--)if(fa[x][i]!=fa[y][i])
	x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
	read(n),read(m);e[1].push_back(0);
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(dep[1]=1);
	redfs(1);
	while(m--){
		int x,y,res;
		read(x),read(y);
		if(x!=y&&lca(x,y)==y){
			int p=dep[x]-dep[y]-1;
			for(int i=0;i<=18;i++)if(1<<i&p)x=fa[x][i];
			res=from[x].maxn;
		}	
		else if(x!=y){
			res=ans[y].maxn;
		}
		else res=ans[1].maxn;
		if(res%3==2)puts("Yohane");
		else puts("Riko");
	}
	return 0;
}

