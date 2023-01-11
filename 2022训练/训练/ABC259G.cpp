#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000000000ll
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
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=205;
struct edge{
	int next,u,v,val;
};
int i,j,k,n,s,t,m,ans,tot;
int A[N][N],dep[N],head[N],now[N],r[N],c[N];
queue<int> q;
edge a[N*N*2];
void add_edge(int u,int v,int val){
	a[k].next=head[u],head[u]=k,a[k].u=u,a[k].v=v,a[k++].val=val;
	a[k].next=head[v],head[v]=k,a[k].u=v,a[k].v=u,a[k++].val=0;
}
int bfs(){
	memset(dep,1,sizeof(dep));dep[s]=0;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(i=now[u]=head[u];~i;i=a[i].next){
			if(a[i].val==0||dep[a[i].v]<=dep[u]+1)continue;
			dep[a[i].v]=dep[a[i].u]+1;
			q.push(a[i].v);
		}
	}
	return dep[t]<=n+m+1;
}
int dfs(int u,int maxn=INF){
	if(u==t)return maxn;
	int res=0;
	for(int i=now[u];~i;i=a[i].next){
		now[u]=i;int v=a[i].v;
		if(a[i].val==0||dep[v]!=dep[u]+1)continue;
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
	//freopen(".in","w",stdout);
	memset(head,-1,sizeof(head));
	read(n),read(m);t=n+m+1;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		read(A[i][j]);
		if(A[i][j]>=0)ans+=A[i][j],add_edge(i,n+j,A[i][j]);
		else r[i]-=A[i][j],c[j]-=A[i][j],add_edge(n+j,i,INF);
	}
	for(i=1;i<=n;i++)add_edge(s,i,r[i]);
	for(i=1;i<=m;i++)add_edge(i+n,t,c[i]);
	
	while(bfs())
	ans-=dfs(s);

	cout<<ans<<endl;
	return 0;
}


