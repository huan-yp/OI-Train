#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
const int N=4e5+10;
struct fu{
	int next,v;
}a[N];
int val[N],fa[N],dp[N],head[N],ans[N];
void dfs(int u)
{
	dp[u]=val[u];
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(fa[u]==v)
		continue;
		fa[v]=u;
		dfs(v);
		dp[u]+=max(0,dp[v]);
	}
}
void dfs2(int u)
{
	if(u!=1)
	ans[u]=max(ans[fa[u]]-max(dp[u],0),0)+dp[u];
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(fa[u]==v)
		continue;
		dfs2(v);
	}
} 
void work(int aa,int bb)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].v=bb;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%d",&val[i]),val[i]=(val[i]==0?-1:1);
	for(i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		work(x,y);
		work(y,x);
	}
	dfs(1);
	ans[1]=dp[1];
	dfs2(1);
	for(i=1;i<=n;i++)
	printf("%d ",ans[i]);
	return 0;
}

