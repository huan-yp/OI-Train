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

