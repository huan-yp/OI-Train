#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
struct edge{
	int v,val;
};
const int N=2e5+10;
int i,j,k,n,s,t,m;
int dis[N],vis[N];
vector<edge> e[N];
priority_queue<pair<int,int> > q;
void dij()
{
	memset(dis,11,sizeof(dis));
	dis[0]=0;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(edge tmp:e[u])
		{
			int v=tmp.v,val=tmp.val;
			if(dis[v]<=dis[u]+val)continue;
			dis[v]=dis[u]+val;
			q.push(make_pair(-dis[v],v));
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		int x;read(x);
		e[i].push_back((edge){i%n+1,x});
	}
	for(i=1;i<=n;i++)
	{
		int x;read(x);
		e[0].push_back((edge){i,x});
	}
	dij();
	for(i=1;i<=n;i++)
	printf("%lld\n",dis[i]);
	return 0;
}

