#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<stack>
#define next nxt
#define itn int
#define y1 y3647
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int i,j,k,m,n,s,t,ans,tot;
const int N=2e6+10,M=600+10;
struct fu{
	int v,next,val;
}a[N<<1];
int now[M],head[M],dep[M];
queue <int> q;
void work(int aa,int bb,int cc)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].v=bb;
	a[k].val=cc;
}
int bfs()
{
	q.push(s);
	memset(dep,0,sizeof(dep));
	dep[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		now[u]=head[u];
		q.pop();
		for(int i=head[u];i;i=a[i].next)
		{
			int v=a[i].v;
			if(dep[v]==0&&a[i].val!=0)
			{
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[t];
}
int dfs(int u,int maxn)
{
	if(u==t)
	return maxn;
	int tmp=0;
	for(int i=now[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(dep[v]!=dep[u]+1||a[i].val==0)
		continue;
		int tc=min(dfs(v,min(maxn,a[i].val)),maxn);
		tmp+=tc;
		maxn-=tc;
		a[i].val-=tc;
		a[i+(i%2?1:-1)].val+=tc;
		if(tc==0)
		dep[v]=0;
		if(maxn==0)
		{
			now[u]=i;
			break;
		}
	}
	return tmp;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",stdout);
	int tot;
	cin>>n>>m>>tot;
	for(i=1;i<=tot;i++)
	{
		int l1,r1,l2,r2;
		cin>>l1>>l2>>r1>>r2;
		for(j=l1;j<=r1;j++)
		work(j,i+n+m,1),work(i+n+m,j,0);
		for(j=l2;j<=r2;j++)
		work(i+n+m+tot,j+n,1),work(j+n,i+n+m+tot,0);
		work(n+m+i,n+m+i+tot,1),work(n+m+i+tot,n+m+i,0);
	}
	s=0;
	t=tot*2+n+m+1;
	for(i=1;i<=n;i++)
	work(s,i,1),work(i,s,0);
	for(i=1;i<=m;i++)
	work(i+n,t,1),work(t,i+n,0);
	while(bfs())
	ans+=dfs(s,200);
	printf("%d",ans);
	return 0;
}
