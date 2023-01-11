#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t;
const int N=1e6+10;
long long dp[N];
struct fu{
	int next,val,v;
}a[N];
int head[N],vis[N];
void work(int aa,int bb,int cc)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].val=cc;
	a[k].v=bb;
}
priority_queue < pair < int , int > > q; 
void dij()
{
	q.push(make_pair(0,1));
	for(i=2;i<=t;i++)
	dp[i]=1e17;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
		continue;
		vis[u]=1;
		for(i=head[u];i;i=a[i].next)
		{
			int v=a[i].v;
			if(a[i].val+dp[u]<dp[v])
			{
				dp[v]=dp[u]+a[i].val;
				q.push(make_pair(-dp[v],v));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	int x,y,z;
	for(i=1;i<=m;i++)
	{
		if(i==7918)
		t=t;
		scanf("%d%d%d",&x,&y,&z);
		work(x,y,z);
		work(y,x,z);
	}
	t=n;
	for(i=1;i<=s;i++)
	{
		scanf("%d%d",&x,&z);
		t++;
		for(j=1;j<=x;j++)
		{
			scanf("%d",&y);
			work(y,t,z);
			work(t,y,0);
		}
	}
	dij();
	printf("%lld\n",dp[n]);//std by mao_zx 
	return 0; 
}
