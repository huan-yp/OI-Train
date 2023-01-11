#include<bits/stdc++.h>
using namespace std;
int j,k,m,n,s,t,mod=80112002;
const int N=1e6+10;
struct node 
{
	int q,z,w,next;					
}; 
node a[N<<1];
int qd[N],dp[N],zd[N];
int head[N];
void add(int aa,int bb)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].q=aa;
	a[k].z=bb;
}
void dfs(int u)
{
	int i;
	for(i=head[u];i;i=a[i].next)
	{
		int v=a[i].z;
		dp[v]=(dp[v]+dp[u])%mod;
		dfs(v);
	}
}
queue <int> q;
int main()
{
	int i;
	cin>>n>>m;
	int u,v;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		qd[u]++;
		zd[v]++;
	}
	for(i=1;i<=n;i++)
	{
		if(zd[i]==0)
		{
		q.push(i);
		dp[i]++;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(i=head[u];i;i=a[i].next)
		{
			int v=a[i].z;
			dp[v]=(dp[u]+dp[v])%mod;
			zd[v]--;
			if(zd[v]==0)
			q.push(v);
		}
	}
	long long ans=0;
	for(i=1;i<=n;i++)
	{
		if(qd[i]==0)
		ans=(ans+dp[i])%mod;
	}
	cout<<ans;
	return 0;
 } 
