#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=405;
int i,j,k,n,s,t,m,flag=0;
int mp[N][N],way[N][N],d[N],dis[N*N],head[N*N],now[N*N];
struct edge{
	int next,v,val;
}a[N*N<<2];
void addedge(int u,int v,int val=1){
	a[k].next=head[u],head[u]=k,a[k].v=v,a[k++].val=val;
	a[k].next=head[v],head[v]=k,a[k].v=u,a[k++].val=0;
}
queue<int> q;
int bfs(){
	q.push(0);memset(dis,16,sizeof(dis));dis[0]=0;
	for(i=0;i<=t;i++)now[i]=head[i];
	while(!q.empty()){
		int u=q.front();q.pop();
		if(u==t)return 1;
		for(int i=head[u];i!=-1;i=a[i].next){
			int v=a[i].v;
			if(a[i].val<=0||dis[v]<=dis[u]+1)continue;
			dis[v]=dis[u]+1;q.push(v);
		}
	}
	return 0;
}
int dfs(int u,int maxn=INF){
	if(u==t)return maxn;
	int res=0;
	for(int i=now[u];i!=-1;i=a[i].next){
		now[u]=i;
		int v=a[i].v;if(dis[u]+1!=dis[v]||a[i].val==0)continue;
		int tmp=dfs(v,min(maxn,a[i].val));
		maxn-=tmp,a[i].val-=tmp,a[i^1].val+=tmp,res+=tmp;
		if(maxn==0)break;
	}
	return res;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);	
	read(n),read(m);
	memset(mp,-1,sizeof(mp));
	for(i=1;i<=m;i++){
		int x,y;read(x),read(y);
		mp[x][y]=1;mp[y][x]=0;
	}
	for(s=1;s<=n;s++){
		memset(head,-1,sizeof(head));
		memset(way,-1,sizeof(way));
		memset(d,0,sizeof(d));
		t=n;k=0;int cnt=0,flag=1;
		for(i=1;i<=n;i++){
			if(i==s||mp[s][i]!=-1)continue;
			way[s][i]=1,way[i][s]=0;
		}
		for(i=1;i<=n;i++)
		for(j=1;j<i;j++){
			if(mp[i][j]!=-1)way[i][j]=mp[i][j],way[j][i]=mp[j][i];
			if(way[i][j]==-1)continue;
			d[i]+=way[i][j],d[j]+=way[j][i];
		}
		for(i=1;i<=n;i++)
		for(j=1;j<i;j++){
			if(way[i][j]!=-1)continue;
			cnt++;
			addedge(0,++t);
			addedge(t,i);
			addedge(t,j);
		}
		++t;
		for(i=1;i<=n;i++)
		{
			if(d[i]>=d[s]&&i!=s)flag=0;
			addedge(i,t,d[s]-d[i]-1);
		}
		if(flag==0)continue;		
	
		int maxflow=0,flowcnt=0;
		while(bfs()){
			int tmp=dfs(0,INF);
			maxflow+=tmp;
		}
		if(maxflow==cnt)printf("%d ",s);
	}
	return 0;
}
