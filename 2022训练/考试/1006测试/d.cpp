#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e6+2e5;
int i,j,k,m,n,s,t,ans;
int to[N],cycle[N],vis[N],dis[N],ok[N],nxt[N],a[N],from[N];
vector<int> e[N/2];
int dfs(int u){
	if(vis[u]==1){
		cycle[u]=++s;
		vis[u]=0;return u;
	}	
	if(ok[u])return 0;
	ok[u]=vis[u]=1;
	int res=dfs(to[u]);
	vis[u]=0;
	if(res)cycle[u]=s;
	if(res==u)return 0;
	return res;
}
void lit(int u){
	if(vis[u])return ;
	a[++m]=dis[u]<=k;vis[u]=1;
	lit(to[u]);
}
void solve(){
	int lst=0;
	for(int i=m+1;i<=2*m;i++)a[i]=a[i-m];
	for(int i=2*m;i>=0;i--){
		nxt[i]=lst;
		if(a[i]==0)lst=i;
	}
	if(nxt[0]==0)return ;
	int pos=nxt[0],sum=INF;
	while(pos){
		int all=0;
		for(int i=pos;i&&i<m+pos;i=nxt[i+k-1])all++;
		cmin(sum,all);if(pos-nxt[0]>k)break;
		pos=nxt[pos];
	}
	ans+=sum;
}
void get_dis(){
	queue<int> q;
	for(i=1;i<=n;i++)if(dis[i]<=1)q.push(i);else dis[i]=INF;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(dis[to[u]]>dis[u]+1){
			dis[to[u]]=dis[u]+1;
			q.push(to[u]);
		}
	}
}
void top_sort(){
	queue<int> q;
	q.push(1);dis[1]=0;
	for(i=2;i<=n;i++)if(from[i]==0)q.push(i),dis[i]=1,ans++;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(cycle[u])continue;
		if(dis[u]>k){dis[u]=1;ans++;}
		int v=to[u];from[v]--;cmin(dis[v],dis[u]+1);
		if(from[v]==0)q.push(v);
	}
}
int main(){
	memset(dis,1,sizeof(dis));
	read(n),read(k);
	for(i=1;i<=n;i++){
		int x,y;read(x),read(y);
		to[x]=y;from[y]++;
	}
	for(i=1;i<=n;i++)dfs(i);
	top_sort();
	get_dis();
	for(i=1;i<=n;i++)e[cycle[i]].push_back(i);
	for(i=1;i<=s;i++){
		m=0;lit(e[i][0]);solve();
	}
	cout<<ans<<endl;
	return 0;
}

