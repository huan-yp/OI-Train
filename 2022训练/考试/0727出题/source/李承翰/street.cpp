#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define double long double
using namespace std;
int n;
bool vis[100001];
vector<int> g[100001];
double f[100001][2];
int p[100001];
void dfs(int u){
	if(g[u].empty()){
		f[u][0]=f[u][1]=0;p[u]=1;return;
	}
	for(int v:g[u])dfs(v),p[u]+=p[v],f[u][0]+=f[v][0]+2;
	if(vis[u]) f[u][0]=0;
	sort(g[u].begin(),g[u].end(),[&](int x,int y){return (f[x][0]+2)*p[y]>(f[y][0]+2)*p[x];});
	double tmp=0;
	for(int v:g[u]){
		tmp+=f[v][0]+2;
		f[u][1]+=f[v][0]+2;
		f[u][1]-=tmp*p[v]/p[u];
		f[u][1]+=p[v]*f[v][1]/p[u];
	}
	f[u][1]+=1;
}
int main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	scanf("%d",&n);
	int fa;char op;
	for(int i=2;i<=n;i++){
		scanf("%d %c",&fa,&op);
		g[fa].push_back(i);
		vis[i]=(op=='Y');
	}
	dfs(1);
	printf("%.10Lf",f[1][1]);
}
