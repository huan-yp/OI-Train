#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,tot,h[N];
bool w[N];
struct edge
{
	int v,nxt;
}e[N<<1];
void add(int u,int v)
{
	e[++tot]=(edge){v,h[u]};
	h[u]=tot;
}
int dep[N],cnt;
ll sumd;
void dfs(int u)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		dep[v]=dep[u]+1;
		dfs(v);
	}
	if(!e[h[u]].nxt)sumd+=dep[u],cnt++;
}
vector<int>lf;
int dfn[N],ed[N],idx;
void dfs1(int u)
{
	dfn[u]=++idx;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		dep[v]=dep[u]+1;
		dfs1(v);
	}
	if(!e[h[u]].nxt)lf.push_back(u);
	ed[u]=idx;
}
int pos;
void dfs2(int u)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!w[v])dfs2(v);
		else
		{
			if(dfn[u]<=dfn[pos]&&ed[pos]<=ed[u])dfs2(v);
			else sumd+=dep[u];
		}
	}
	if(!e[h[u]].nxt)sumd+=dep[u];
}
int main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	scanf("%d",&n);char str[3];
	for(int i=2,x;i<=n;i++)scanf("%d%s",&x,str),add(x,i),w[i]=(str[0]=='Y'?1:0);
	bool flg=0;
	for(int i=1;i<=n;i++)flg|=w[i];
	if(!flg)
	{
		dfs(1);
		printf("%.8lf",1.0*sumd);
		return 0;
	}
	dfs1(1),cnt=lf.size();
	for(int x:lf)pos=x,dfs2(1);
	printf("%.8lf",1.0*sumd/cnt);
	return 0;
}

