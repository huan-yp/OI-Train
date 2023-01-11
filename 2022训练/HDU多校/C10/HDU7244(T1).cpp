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
const int N=8005;
int i,j,k,n,s,t,m,tp1,tp2;
int head[N],cnt[N],dep[N],now[N],vis[N];
struct edge{
	int next,v,val;
}a[N];
void work(int aa,int bb,int val=1){
	a[k].next=head[aa],a[k].v=bb,a[k].val=val,head[aa]=k++;
	a[k].next=head[bb],a[k].v=aa,a[k].val=0,head[bb]=k++;
}
int bfs(){
	queue<int> q;q.push(s);
	memset(dep,1,sizeof(dep));dep[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=now[u]=head[u];~i;i=a[i].next){
			if(a[i].val==0)continue;
			int v=a[i].v;
			if(dep[v]<=dep[u]+1)continue;
			dep[v]=dep[u]+1;q.push(v);
		}		
	}
	return dep[t]<=t;
}
int dfs(int u,int maxn){
	if(u==t)return maxn;
	int res=0;
	for(int i=now[u];~i;i=now[u]=a[i].next){
		int v=a[i].v,val=a[i].val;
		if(dep[v]!=dep[u]+1||val==0)continue;
		int ans=dfs(v,min(val,maxn));
		res+=ans,maxn-=ans;
		a[i].val-=ans,a[i^1].val+=ans;
		if(maxn==0)break;
	}
	return res;
}
signed main()
{
	int tot,m1,m2,max_flow;
	read(tot);
	while(tot--){
		read(n),read(m1),read(m2);t=n+m2+1;max_flow=0;
		memset(head,-1,sizeof(head));k=0;s=0;int p=0;
		memset(cnt,0,sizeof(cnt));
		for(i=1;i<=m1;i++){
			int x,y,op;
			read(x),read(y),read(op);
			if(op)cnt[x]++;
			else cnt[y]++;
		}
		for(i=1;i<=m2;i++){
			int x,y;read(x),read(y);
			if(x==1||y==1){cnt[1]++,p++;continue;}
			work(s,i,1);
			work(i,y+m2,1);
			work(i,x+m2,1);
		}
		for(i=2;i<=n;i++){
			if(cnt[i]>cnt[1])break;
			work(i+m2,t,cnt[1]-cnt[i]);
		}
		if(i!=n+1){puts("NO");continue;}
		while(bfs())
		max_flow+=dfs(s,INF);

		if(max_flow==m2-p)puts("YES");
		else puts("NO");
	}
	return 0;
}
