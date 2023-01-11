#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
template <typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
const int N=1e5+10;
int i,j,k,m,n,s,t,top;
int in[N],dfn[N],dp[N],st[N],low[N],rk[N],siz[N];
vector<int> e[N],a[N];
void dfs(int u)
{
	low[u]=dfn[u]=++t;in[u]=1;st[++top]=u;
	for(int v:e[u])
	{
		if(dfn[v])
		{
			if(in[v])
			cmin(low[u],dfn[v]);
		}
		else
		{
			dfs(v);
			cmin(low[u],low[v]);
		}
	}
	if(dfn[u]==low[u])
	{
		siz[++s]=1;
		while(st[top]!=u)
		{
			int v=st[top--];siz[s]++;
			rk[v]=s;in[v]=0;
		}
		rk[st[top--]]=s;in[u]=0;
	}
}
int calc(int x)
{
	if(dp[x])return dp[x];
	for(int v:a[x])
	cmax(dp[x],calc(v));
		
	return dp[x]=dp[x]+siz[x];
}
int main()
{
//	freopen("flower.in","r",stdin);
//	freopen("flower.out","w",stdout);
	int T;read(T);
	while(T--)
	{
		s=t=0;memset(dfn,0,sizeof(dfn));memset(dp,0,sizeof(dp));
		read(n);memset(siz,0,sizeof(siz));
		for(i=1;i<=n;i++)
		{
			e[i].clear(),a[i].clear();
			int x;read(x);x++;
			e[i].push_back(x);
		}
		for(i=1;i<=n;i++)
		{
			int x;read(x);x++;
			e[i].push_back(x);
		}
		dfs(1);
		if(t<n)
		{
			printf("No\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(int v:e[i])
			if(rk[v]!=rk[i])
			a[rk[i]].push_back(rk[v]);
		}
		if(calc(rk[1])==n)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}

