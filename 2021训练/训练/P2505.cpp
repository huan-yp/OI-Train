#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=1505,mod=1e9+7;
struct edge{
	int v,val,rk;
};
int i,j,k,n,s,t,m;
int ans[N*4],dis[N],dp[N],vis[N],f[N],cnt[N];
vector<edge> e[N];
vector<int> a[N];
priority_queue<pair<int,int>> q; 
void Inc(int &a,const int &b){a+=b;if(a>mod)a-=mod;}
void topsort()
{
	queue<int> q;while(!q.empty())q.pop();
	for(i=1;i<=n;i++)if(cnt[i]==0)q.push(i);
	while(!q.empty())
	{
		int u=q.front();q.pop();f[u]++;
		for(int v:a[u])
		{
			Inc(f[v],f[u]);cnt[v]--;
			if(cnt[v]==0)q.push(v);
		}
	}
}
void dij(int x)
{
	memset(dis,63,sizeof(dis)),memset(f,0,sizeof(f));
	dis[x]=0;q.push(make_pair(0,x));
	memset(vis,0,sizeof(vis)),memset(dp,0,sizeof(dp));
	memset(cnt,0,sizeof(cnt));
	dp[x]=1;
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(auto tmp:e[u])
		{
			int v=tmp.v,val=tmp.val;
			if(dis[u]+val<dis[v])
			{
				dis[v]=dis[u]+val,dp[v]=0;
				q.push(make_pair(-dis[v],v));
			}
			if(dis[u]+val==dis[v])
			Inc(dp[v],dp[u]);
		}
	}
	for(i=1;i<=n;i++)a[i].clear();
	for(i=1;i<=n;i++)
	for(auto tmp:e[i])
	{
		int v=tmp.v,val=tmp.val,u=i;
		if(dis[u]+val==dis[v])
		a[v].push_back(u),cnt[u]++;
	}
	topsort();
	for(i=1;i<=n;i++)
	for(auto tmp:e[i])
	{
		int v=tmp.v,val=tmp.val,u=i;
		if(dis[u]+val==dis[v])
		Inc(ans[tmp.rk],1ll*dp[u]*f[v]%mod);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		int x,y,z;read(x),read(y),read(z);
		e[x].push_back((edge){y,z,i});
	}
	for(int i=1;i<=n;i++)
	dij(i);
	
	for(i=1;i<=m;i++)
	printf("%d\n",ans[i]);
	return 0;
}

