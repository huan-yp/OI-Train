#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=2e5+10; 
int i,j,k,n,s,t,m,l;
int a[N],dis[N][2],nation[N][2],vis[N][2];
vector<pii> e[N];
priority_queue<tuple<int,int,int>> q;
void dij(){
	while(!q.empty()){
		int u=get<1>(q.top()),op=get<2>(q.top());q.pop();
		if(vis[u][op])continue;vis[u][op]=1;
		for(auto [v,val]:e[u]){
			if(val+dis[u][op]<dis[v][0]){
				if(nation[u][op]!=nation[v][0]){
					nation[v][1]=nation[v][0],dis[v][1]=dis[v][0];
					q.push(make_tuple(-dis[v][1],v,1));
				}
				nation[v][0]=nation[u][op];
				dis[v][0]=val+dis[u][op];
				q.push(make_tuple(-dis[v][0],v,0));
			}
			if(val+dis[u][op]<dis[v][1]&&nation[u][op]!=nation[v][0]){
				nation[v][1]=nation[u][op];
				dis[v][1]=val+dis[u][op];
				q.push(make_tuple(-dis[v][1],v,1));
			}
		}
	}
}
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(n),read(m),read(k),read(l);
	for(i=1;i<=n;i++)read(a[i]);
	memset(dis,1,sizeof(dis));
	for(i=1;i<=l;i++){
		int x;read(x);
		dis[x][0]=0,nation[x][0]=a[x];
		q.push(make_tuple(0,x,0));
	}
	for(i=1;i<=m;i++){
		int x,y,z;read(x),read(y),read(z);
		e[x].emplace_back(y,z),e[y].emplace_back(x,z);
	}
	dij();
	for(i=1;i<=n;i++){
		int ans=dis[i][0];
		if(nation[i][0]==a[i])ans=dis[i][1];
		if(ans>=1e16)printf("-1 ");
		else printf("%lld ",ans);
	}
	return 0;
}


