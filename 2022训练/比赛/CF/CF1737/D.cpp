#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
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
const int N=505;
int i,j,k,n,s,t,m,tp1,tp2,df,minu=INF;
int a[N],b[N],dfn[N],fa[N],dis[N][N];
vector<pii> e[N];
void bfs(int x){
	memset(dis[x],1,sizeof(dis[x]));
	queue<int> q;q.push(x);dis[x][x]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto [v,w]:e[u]){
			if(dis[x][v]<=dis[x][u]+1)continue;
			dis[x][v]=dis[x][u]+1;q.push(v);
		}
	}
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	t=1;
	read(t);
	while(t--){
		read(n),read(m);
		for(i=1;i<=n;i++)e[i].clear();
		for(i=1;i<=m;i++){
			int x,y,w;read(x),read(y),read(w);
			e[x].emplace_back(y,w);
			e[y].emplace_back(x,w);
		}
		for(i=1;i<=n;i++)bfs(i);
		int ans=1e18;
		for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
		for(auto [v,w]:e[i]){
			cmin(ans,(dis[1][k]+dis[n][k]+dis[i][k]+2)*w);
			cmin(ans,(dis[1][v]+dis[n][i]+1)*w);
		}
		cout<<ans<<endl;
	}
	return 0;
}


