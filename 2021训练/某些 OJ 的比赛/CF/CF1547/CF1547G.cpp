#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	cin>>x;
}
const int N=8e5+10;
int i,j,k,m,n,s,t,top,js;
int dfn[N],low[N],vis[N],in[N],st[N],dp[N],siz[N],cnt[N],rk[N];
vector<int> a[N];
queue<int> q;
void dfs(int u)
{
	dfn[u]=low[u]=++s;
	vis[u]=1,in[u]=1,st[++top]=u;
	for(int v:a[u])
	{
		if(vis[v])
		{
			if(in[v]==0)continue;
			low[u]=min(low[u],dfn[v]);
		}
		else
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
	}
	if(dfn[u]==low[u])
	{
		++js;
		while(st[top]!=u)
		{
			in[st[top]]=0;
			rk[st[top--]]=js;
			siz[js]++;
		}
		siz[js]++,rk[st[top]]=js,in[st[top--]]=0;
	}
}
void topsort()
{
	if(siz[rk[1]]>1)
	dp[rk[1]]=-1;
	else
	dp[rk[1]]=1;
	for(i=n+1;i<=js;i++)
	{
		if(cnt[i]==0)
		q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:a[u])
		{
			if(dp[u]==-1)
			dp[v]=-1;
			if(dp[v]!=-1)
			dp[v]=min(2,dp[u]+dp[v]);
			
			if(siz[v]>1&&dp[v])
			dp[v]=-1;
			
			if(--cnt[v]==0)
			q.push(v);
		}
	}
	
}
int main()
{
	read(t);
	while(t--)
	{
		read(n),read(m);
		s=0,js=n;	
		for(i=1;i<=2*n;i++)
		a[i].clear(),vis[i]=0,dp[i]=0,cnt[i]=0,siz[i]=0;
		for(i=1;i<=m;i++)
		{
			int x,y;
			read(x),read(y);
			a[x].push_back(y);
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i])continue;
			dfs(i);
		}
		for(i=1;i<=n;i++)
		{
			for(int v:a[i])
			{
				if(rk[v]==rk[i])
				{
					siz[rk[v]]++;
					continue;
				}
				cnt[rk[v]]++;
				a[rk[i]].push_back(rk[v]);
			}
		}
		topsort();
		for(i=1;i<=n;i++)
		printf("%d ",dp[rk[i]]);
		printf("\n");
	}
	return 0;
}
