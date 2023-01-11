#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>
T read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e5+10;
int i,j,k,m,n,s,t,S;
int dis[N],vis[N],h[N];
vector<pii> e[N],a[N];
priority_queue<pii,vector<pii>,greater<pii>> q;
void dij(){
	memset(vis,0,sizeof(vis)),memset(dis,31,sizeof(dis));
	q.push(make_pair(0,1));dis[1]=0;
	while(!q.empty()){
		auto [d,u]=q.top();q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:e[u]){
			if(dis[v]>d+w&&!vis[v]){
				dis[v]=d+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int check(int x){
	for(i=1;i<=n;i++)e[i].clear();
	for(i=1;i<=n;i++)for(auto [v,w]:a[i])if(h[v]-h[i]<=x){
		e[i].emplace_back(v,w);
	}
	dij();
	return dis[n]<=S;
}
signed main(){
	read(n),read(m),read(S);
	int l=-1e9-10,r=1e9+10,ans=1e9+10;
	for(i=1;i<=n;i++)read(h[i]);
	for(i=1;i<=m;i++){
		int v,u,w;read(u),read(v),read(w);
		a[u].emplace_back(v,w);
		a[v].emplace_back(u,w);
	}
	while(r>=l){
		int mid=(l+r)>>1;
		if(check(mid))
		ans=mid,r=mid-1;
		else 
		l=mid+1;
	}
	if(ans>1e9)puts("NO");
	else printf("%lld\n",ans);
	return 0;
}

