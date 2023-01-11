#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=605; 
int n,m,rc,cc;
char ch[N][N];
int r[N][N],c[N][N];
struct MaxFlow{
	static const int N=(::N)*(::N);
	int k,s,t;
	struct edge{
		int val,v,next;
	}a[N];
	int head[N],now[N],dis[N];
	MaxFlow(){
		memset(head,-1,sizeof(head));
	}
	void add_edge(int u,int v,int val){
		a[k].next=head[u];a[k].val=val,a[k].v=v;head[u]=k++;
		a[k].next=head[v];a[k].val=0;a[k].v=u;head[v]=k++;
	}
	int bfs(){
		memset(dis,9,sizeof(dis));
		queue<int> q;q.push(s);dis[s]=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=now[u]=head[u];~i;i=a[i].next){
				int v=a[i].v;
				if(dis[v]<=dis[u]+1||a[i].val==0)continue;
				dis[v]=dis[u]+1;q.push(v);
			}
		}		
		return dis[t]<=N;
	}
	int dfs(int u,int maxn=INF){
		if(u==t)return maxn;
		int ret=0;
		for(int i=now[u];~i;i=a[i].next){
			now[u]=i;int v=a[i].v;
			if(maxn==0)break;
			if(a[i].val==0||dis[v]!=dis[u]+1)continue;
			int tmp=dfs(v,min(maxn,a[i].val));
			ret+=tmp,maxn-=tmp;
			a[i].val-=tmp,a[i^1].val+=tmp;
		}
		if(ret==0)now[u]=-1;
		return ret;
	}
	int get_flow(){
		int max_flow=0;
		while(bfs())
		max_flow+=dfs(s);
		return max_flow;
	}
}F;
void ___solve(){
	int i,j;
	read(n),read(m);
	for(i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
		for(j=1;j<=m;j++){
			if(ch[i][j]=='#')continue;
			if(ch[i][j-1]!='.')rc++;
			r[i][j]=rc;
		}
	}
	for(j=1;j<=m;j++)
	for(i=1;i<=n;i++){
		if(ch[i][j]=='#')continue;
		if(ch[i-1][j]!='.')cc++;
		c[i][j]=cc;
	}
	F.s=0,F.t=cc+rc+1;
	for(i=1;i<=rc;i++)F.add_edge(F.s,i,1);
	for(i=1;i<=cc;i++)F.add_edge(rc+i,F.t,1);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(ch[i][j]=='.')
	F.add_edge(r[i][j],rc+c[i][j],1);
	cout<<F.get_flow()<<endl;
}
signed main()
{
	___solve();
	return 0;
}
