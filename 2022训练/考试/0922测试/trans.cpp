#include<bits/stdc++.h>
#define INF 1000000000
#define y1 y3647
#define LL long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(b>a)a=b;}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(b<a)a=b;}
const int N=25;
int i,j,k,m,n,s,t;
int dp[N][N],a[N],b[N],from[N],vis[N],fa[N];
struct edge{
	int u,v,w;
	bool operator <(const edge &a){
		return w<a.w;
	}
}e[N*N];
void solve(int now);
void dfs(int dep);
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int check(int rt){
	int sum=0,need=0,with=0,all=0,p[16];
	for(i=1;i<=n;i++)if(vis[i]==rt)
	sum+=a[i],need+=b[i],p[++with]=i,fa[i]=i;
	if(need>sum)return 0;
	for(i=1;i<=with;i++)for(j=1;j<=with;j++)if(dp[p[i]][p[j]]<=1e4)
	e[++all]={p[i],p[j],dp[p[i]][p[j]]};
	sort(e+1,e+all+1);
	int cnt=0;
	for(i=1;i<=all;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		fa[u]=v;cnt++;need+=e[i].w;
		if(need>sum)return 0;
	}
	if(cnt!=with-1)return 0;
	int minu=INF;
	for(i=1;i<=with;i++){
		for(j=1;j<=n;j++){
			if(vis[j]==rt)continue;
			cmin(minu,dp[p[i]][j]);
		}
	}
	if(sum>=need+minu)return 0;
	return 1;
}
void solve(int now,int rt){
	if(s)return ;
	vis[now]=rt;int i;
	for(i=now+1;i<=n;i++)if(!vis[i])
	solve(i,rt);
	for(i=1;i<=n;i++)
	if(vis[i]==0)break;
	if(!check(rt)){
		vis[now]=0;return ;
	}
	dfs(i);
	vis[now]=0;
}
void dfs(int dep){
	if(dep==n+1){
		s++;
		return ;
	}
	solve(dep,dep);
}
int main(){
	read(t);
	while(t--){
		s=0;
		memset(dp,31,sizeof(dp));
		read(n),read(m);
		for(i=1;i<=m;i++){
			int v,u,w;
			read(u),read(v),read(w);
			cmin(dp[u][v],w),cmin(dp[v][u],w);
		}
		int sum=0,need=0;
		for(i=1;i<=n;i++)read(a[i]),read(b[i]),sum+=a[i],need+=b[i];
		if(need<=sum)
		solve(1,1);
		if(s)puts("Yes");
		else puts("No");
	}
	return 0;
}

