#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define pii pair<int,int>
#define INF 1000000000
using namespace std;
template<typename T>int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=2005,W=N*N/3;
int i,j,k,m,n,s,t;
int l[N],start[N],ans[N],ar[N];
int ok[W],vis[W],lim[W],dep[W];
LL _dis[N],dis[W];
vector<pii> _e[N],e[W];
void dij1(){
	LL dis[N];
	priority_queue<tuple<LL,int,int>,vector<tuple<LL,int,int>>,greater<tuple<LL,int,int>>> q;
	memset(dis,1,sizeof(dis));
	dep[1]=dis[1]=0;q.push(make_tuple(0,0,1));
	while(!q.empty()){
		int u=get<2>(q.top());q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:_e[u]){
			if(w+dis[u]>dis[v]||(w+dis[u]==dis[v]&&dep[u]+1>=dep[v]))continue;
			dis[v]=dis[u]+w;dep[v]=dep[u]+1;
			q.push(make_tuple(dis[v],dep[v],v));
		}
	}
	memcpy(_dis,dis,sizeof(dis));
}
void dij(){
//	priority_queue<int,vector<int>,greater<int>> q;
	priority_queue<pair<LL,int>,vector<pair<LL,int>>,greater<pair<LL,int>>> q;
	memset(dis,1,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[0]=0;q.push(make_pair(0,0));
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:e[u]){
			if(w+dis[u]>=dis[v])continue;
			dis[v]=dis[u]+w;
			q.push(make_pair(dis[v],v));
		}
	}
}
void bfs(){
	queue<int> q;
	memset(dep,0,sizeof(dep));
	q.push(1);dep[1]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto [v,w]:_e[u]){
			if(dep[v])continue;
			dep[v]=dep[u]+1,q.push(v);
		}
	}
	for(i=1;i<=n;i++)dep[i]--;
}
int det(int u){
	if(ok[u]!=-1)return ok[u];
	ok[u]=0;
	for(auto [v,w]:e[u]){
		if(dis[v]!=dis[u]+w)continue;
		ok[u]|=det(v);
	}
	return ok[u];
}
int _det(int u){
	if(u==n)return ar[u]=1; 
	if(ar[u]!=-1)return ar[u];
	ar[u]=0;
	for(auto [v,w]:_e[u]){
		if(_dis[v]!=_dis[u]+w)continue;
		ar[u]|=_det(v);
	}
	return ar[u];
}
pair<int,int> _get(int rk){
	int f=upper_bound(l+1,l+n+1,rk)-l-1;
	return make_pair(f,rk-l[f]+start[f]);
}
void add(int u,int v,int w,int d){
	if(d+1<start[v]||d+1>lim[v])return ;
	e[l[u]+d-start[u]].emplace_back(l[v]+d-start[v]+1,w);
}
double calc(int i,int j){
	return 1.0*(dis[i]-dis[j])/(-(i-l[n]+start[n])+(j-l[n]+start[n]));
}
signed main(){
//	freopen("backhome.in","r",stdin);
//	freopen("backhome.out","w",stdout);
	//freopen(".in","w",stdout);
	memset(ar,-1,sizeof(ar));memset(ok,-1,sizeof(ok));
	read(n),read(m);
	for(i=1;i<=m;i++){
		int x,y,d;read(x),read(y),read(d);
		_e[x].emplace_back(y,d);
		_e[y].emplace_back(x,d);
	}
	dij1();
	for(i=1;i<=n;i++){
		lim[i]=min(dep[i],dep[n]);
	}
	bfs();start[0]=1;
	for(i=1;i<=n+1;i++){
		start[i]=dep[i];
		l[i]=l[i-1]+max(lim[i-1]-start[i-1]+1,0);
	}
	for(i=1;i<=n;i++)
	for(auto [v,w]:_e[i]){
		for(int d=start[i];d<=lim[i];d++)
		add(i,v,w,d);
	}
	dij();
	LL minu=1ll*INF*INF;
	int st[N],top=0;
	for(j=l[n];j<l[n+1];j++){
		while(top>=2&&calc(st[top-1],st[top])<calc(st[top],j))top--;
		st[++top]=j;
	}
	for(i=l[n];i<l[n+1];i++)ok[i]=0;
	for(i=1;i<=top;i++)ok[st[i]]=1;
	for(i=0;i<l[n+1];i++)if(det(i))
	ans[_get(i).first]=1;
	
	for(i=1;i<=n;i++)s+=!(ans[i]|=_det(i));
	cout<<s<<endl;
	for(i=1;i<=n;i++)if(!ans[i])
	printf("%lld ",i);

	return 0;
}
