#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,fz=1;
	char ch;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')fz=-1;
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*fz;
}
const int N=1e5;
vector<int> e[N+2];
int siz[N+2],g[N+2];
bool f[N+2];
ll ans;
int tot;
int q[N+2],cnt;
bool cmp(int x,int y){
	return 1ll*siz[y]*(g[x]+2)<1ll*siz[x]*(g[y]+2);
}
void dfs(int u){
	if(!e[u].size()){
		tot++;siz[u]=1;return;
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		dfs(v);
		siz[u]+=siz[v];
	}
	if(f[u]) g[u]=0;
	int pre=cnt;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		q[++cnt]=v;
	}
	sort(q+pre+1,q+cnt+1,cmp);
	for(int i=pre+1;i<=cnt;i++){
		g[u]+=1;
		ans+=1ll*g[u]*siz[q[i]];
		g[u]+=g[q[i]]+1;
	}
	if(f[u]) g[u]=0;
}
int main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	int n=read();
	for(int i=2;i<=n;i++){
		int fa=read();
		char ch=getchar();
		e[fa].push_back(i);
		if(ch=='Y') f[i]=1; 
	}
	dfs(1);
	printf("%.7lf",(double)ans*1.00/(tot*1.00));
	return 0;
}
