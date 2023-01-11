## Topcoder8404

### 题意：

给定一张有边权的有向图 $n\leq 100,m\leq 500$ ，有一条边被摧毁了，但不知道具体是哪条，走到某条边的起点时才知道它是否被摧毁，问在最坏情况下最少需要走多远才能从 $1$ 到 $2$。

###  思路：

$n$ 很小，考虑对于删掉每一条边的情况处理出 $1,2$ 到所有点的最短路，注意处理 $2$ 的时候反向建图。这样我们就可以二分一下答案，考虑一条边是否可以使用，如果在删掉了它的情况下 $2$ 到它起点的距离加上 $1$ 到它起点的距离比二分的这个答案还大的话，显然就不能用了，因为如果尝试使用它，如果它被删了，我们就没了。。。

判断出这个之后再跑一遍最短路，再看答案是否满足要求。

看上去好像没什么问题，但是我们得到了 $\text{WA27}$ 的好成绩。

深(shou)入(wan)分(shu)析(ju) 一下，我们发现选一条边的条件比我们提到的要更加苛刻一些，因为我们第一遍对 $1$ 跑的最短路是没有考虑除了枚举的那一条边之外的边的，有可能我们在走到这条边这里的过程中，由于 $mid$ 的限制，走过的并不是预处理出来的最短路，而是其它的东西。

不过这个问题也不难解决，在跑第二遍最短路时更新的过程中判断是否满足条件即可。

具体见代码实现 (代码较丑，毕竟它被摧残过)。

### 参考代码：

```cpp
#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
const int N=1005;
int i,j,n,s,t,m,k;
int head[2][N],dis[2][N][N],vis[N],dis2[N];
struct fu{
	int v,val,next;
}a[2][N],b[N];
string road="";
priority_queue<pair<int,int> > q;
void read(int &x)
{
	x=0;
	char ch=road[i++];
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-48;
		ch=road[i++];
	}
}
void work(int aa,int bb,int cc)
{
	a[0][++k].next=head[0][aa];
	head[0][aa]=k;a[0][k].val=cc;
	a[0][k].v=bb;
	swap(aa,bb);
	a[1][k].next=head[1][aa];
	head[1][aa]=k;a[1][k].val=cc;
	a[1][k].v=bb;
}
//d[v]=min(d[u]);
void dij(int s,int op)
{
	int *dp=dis[op&1][op>>1];
	memset(vis,0,sizeof(vis));
	memset(dp,1,sizeof(dis[op&1][op>>1]));
	dp[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[op&1][u];i;i=a[op&1][i].next)
		{
			int v=a[op&1][i].v;
			if(dp[v]<=dp[u]+a[op&1][i].val)continue;
			dp[v]=a[op&1][i].val+dp[u];
			q.push(make_pair(-dp[v],v));
		}
	}
}
void dij2(int x)
{
	memset(dis2,1,sizeof(dis2));
	memset(vis,0,sizeof(vis));
	dis2[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[0][u];i;i=b[i].next)
		{
			int v=b[i].v;
			if(dis2[u]+dis[1][i][u]>x)continue;
			if(dis2[v]<=dis2[u]+b[i].val)continue;
			dis2[v]=dis2[u]+b[i].val;
			q.push(make_pair(-dis2[v],v));	
		}
	}
}
//bug:

int check(int x)
{
	for(i=1;i<=k;i++)
	{
		b[i]=a[0][i];
//		if(dis[1][i][a[1][i].v]+dis[0][i][a[1][i].v]>x)
//		b[i].val=INF;
	}
	dij2(x);
	return dis2[2]<=x;
}
class WarTransportation{
	public:
	int messenger(int N,vector<string> highways)
	{
		n=N;
		for(string tmp:highways)
		road+=tmp;
		int len=road.length();
		for(i=0;i<len;)
		{
			int x,y,z;
			read(x),read(y),read(z);
			work(x,y,z);
		}
		for(i=1;i<=k;i++)
		{
			int tmp=a[0][i].val;
			a[1][i].val=a[0][i].val=INF;
			dij(1,i*2),dij(2,i*2+1);
			a[1][i].val=a[0][i].val=tmp;
		}
		int l=0,r=1e6,ans=-1;
		while(r>=l)
		{
			int mid=(l+r)/2;
			if(check(mid))
			r=mid-1,ans=mid;
			else
			l=mid+1;
		}
		return ans;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	WarTransportation solve;
//	cout<<solve.messenger(10,
//{"1 4 1,4 6 1,9 2 1,7 9 2,6 1 1,5 9 885,10 5 975,6 10 930,6 7 3,3 2 889,8 1 970,1 7 1,9 8 967,4 1 1,5 3 719,10 4 156,10 6 168,5 1 118"});
//		return 0;
//}

```



### 另一种思路：

再仔细想一想，二分的过程似乎好像大概有一点多余，于是我们以另一种角度来思考一下这个问题，把这个问题看作两个人的博弈，一个要走最短路，另一个需要在**合适的时机**选择当前点的一条边断掉，使第一个人走的距离最长。

沿用上面的思路，我们考虑预处理出每一条边断掉后的距离，但我们发现决策已经和边本身没有什么关系了，在第二个人决策时，她必须选择断掉一条当前点的边，使得在没有这条边的情况下现在到终点的距离最大。

所以我们预处理一个 $d$ 数组，$d_u$ 表示在 $u$ 点决策，第一个人需要走的最长距离。

这个时候我们再考虑博弈 $dp$ ，转移式也不难写出了。

设 $dp[u]$ 表示现在在 $u$ 点，第二个人还没决策，需要走的最长距离。

答案是 $dp[1]$ ，至于为什么是从后往前转移，只能说是题做多了就知道了。
$$
dp[u]=max(dp[v]+val,d[u])
$$
转移好像是有环的，但这种图上的转移不应该直接用图论算法吗？

$\text{Dijstra}$ 搞定！

完结撒花。。。

### 参考代码：

```
#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
const int N=1005;
int i,j,n,s,t,m,k;
int head[2][N],dis[2][N][N],vis[N],dis2[N],d[N];
struct fu{
	int v,val,next;
}a[2][N];
string road="";
priority_queue<pair<int,int> > q;
void read(int &x)
{
	x=0;
	char ch=road[i++];
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-48;
		ch=road[i++];
	}
}
void work(int aa,int bb,int cc)
{
	a[0][++k].next=head[0][aa];
	head[0][aa]=k;a[0][k].val=cc;
	a[0][k].v=bb;
	swap(aa,bb);
	a[1][k].next=head[1][aa];
	head[1][aa]=k;a[1][k].val=cc;
	a[1][k].v=bb;
}
//d[v]=min(d[u]);
void dij(int s,int op)
{
	int *dp=dis[op&1][op>>1];
	memset(vis,0,sizeof(vis));
	memset(dp,1,sizeof(dis[op&1][op>>1]));
	dp[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[op&1][u];i;i=a[op&1][i].next)
		{
			int v=a[op&1][i].v;
			if(dp[v]<=dp[u]+a[op&1][i].val)continue;
			dp[v]=a[op&1][i].val+dp[u];
			q.push(make_pair(-dp[v],v));
		}
	}
}
void dij2()
{
	memset(dis2,1,sizeof(dis2));
	memset(vis,0,sizeof(vis));
	dis2[2]=0;
	q.push(make_pair(0,2));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[1][u];i;i=a[1][i].next)
		{
			int v=a[1][i].v;
			if(dis2[v]<=max(d[v],dis2[u]+a[1][i].val))continue;
			dis2[v]=max(d[v],dis2[u]+a[1][i].val);
			q.push(make_pair(-dis2[v],v));	
		}
	}
}
//bug:
class WarTransportation{
	public:
	int messenger(int N,vector<string> highways)
	{
		n=N;
		for(string tmp:highways)
		road+=tmp;
		int len=road.length();
		for(i=0;i<len;)
		{
			int x,y,z;
			read(x),read(y),read(z);
			work(x,y,z);
		}
		for(i=1;i<=k;i++)
		{
			int tmp=a[0][i].val;
			a[1][i].val=a[0][i].val=INF;
			dij(1,i*2),dij(2,i*2+1);
			d[a[1][i].v]=max(d[a[1][i].v],dis[1][i][a[1][i].v]);
			a[1][i].val=a[0][i].val=tmp;
		}
		int l=0,r=1e6,ans=-1;
		dij2();
		if(dis2[1]<=1e6)
		ans=dis2[1];
		return ans;
	}
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	WarTransportation solve;
//	cout<<solve.messenger(10,
//{"1 4 1,4 6 1,9 2 1,7 9 2,6 1 1,5 9 885,10 5 975,6 10 930,6 7 3,3 2 889,8 1 970,1 7 1,9 8 967,4 1 1,5 3 719,10 4 156,10 6 168,5 1 118"});
//		return 0;
//}

```



~~我不会告诉你第二份代码压根没交过~~

