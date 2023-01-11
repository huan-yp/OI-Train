#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=1e6+10;
const int M=3e6+10;
int i,j,k,n,s,t,m,tp1,tp2,max_d;
int head[M],dep[N],vis[M];
LL dis[M];
priority_queue<LL,vector<LL>,greater<LL>> q;
struct edge{
	int next,v,w;
}a[N*6];
void work(int aa,int bb,int w,int d=0){
	a[k].next=head[aa],a[k].v=bb,a[k].w=w,head[aa]=k++;
	if(d==0)a[k].next=head[bb],a[k].v=aa,a[k].w=w,head[bb]=k++;
}
void dfs(int u,int fa=0){
	cmax(max_d,dep[u]);
	for(int i=head[u];~i;i=a[i].next){
		int v=a[i].v;
		if(fa==v)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void dij(int s,int t){
	memset(vis,0,sizeof(vis));
	memset(dis,1,sizeof(dis));
	while(!q.empty())q.pop();
	dis[s]=0;q.push(s);
	while(!q.empty()){
		int u=q.top()%M;q.pop();
		if(vis[u])continue;vis[u]=1;
		if(vis[t])return ;
		for(int i=head[u];~i;i=a[i].next){
			int v=a[i].v,w=a[i].w;
			if(dis[u]+w>=dis[v])continue;
			dis[v]=dis[u]+w;q.push(dis[v]*M+v);
		}
	}
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		int p,d;
		memset(head,-1,sizeof(head));
		read(n);k=0;max_d=0;
		for(i=1;i<n;i++){
			int x,y,w;
			read(x),read(y),read(w);
			work(x,y,w);
		}
		dfs(dep[1]=1);
		read(d),read(p);
		for(i=1;i<=n;i++)
		work(i,n+dep[i],0,1),work(2*n+dep[i],i,0,1);
		for(i=1;i<=max_d-d;i++)
		work(n+i,2*n+i+d,p,1),work(n+i+d,2*n+i,p,1);
		
		read(tp1),read(tp2);
		dij(tp1,tp2);
		cout<<dis[tp2]<<endl;
	}
	return 0;
}


