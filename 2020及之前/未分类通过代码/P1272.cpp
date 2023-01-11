#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int k,n,t,m;
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
const int N=3e2+10;
int size[N],dp[N][N][N],head[N],fa[N],son[N];
int rt;
struct fu{
	int next,v;
}a[N]; 
void dfs(int u)
{
	int js=0;
	dp[u][0][0]=0;
	for(int i=head[u];i;i=a[i].next)
	{
		son[u]++;
		int v=a[i].v;
		dfs(v);
		size[u]+=size[v];
		for(int s=0;s<=n;s++)
		for(int j=0;j<=size[v]&&j<=s;j++)
		dp[u][s][son[u]]=min(dp[u][s][son[u]],dp[u][s-j][son[u]-1]+dp[v][j][son[v]]);
	}
	size[u]++;
	dp[u][size[u]][son[u]]=1;
	dp[u][0][son[u]]=0;
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
	int j,i;
	scanf("%d%d",&n,&m);
	int x,y;
	for(i=0;i<=n;i++)
	for(j=0;j<=n;j++)
	for(k=0;k<=n;k++)
	dp[i][j][k]=1e9;
	k=0;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		fa[y]=x;
		work(x,y);
	}
	for(i=1;i<=n;i++)
	if(fa[i]==0)
	rt=i;
	dfs(rt);
	int ans=1e9;
	for(i=1;i<=n;i++)
	if(size[i]>=m)
	ans=min(ans,dp[i][size[i]-m][son[i]]+1);
	ans=min(ans,dp[rt][size[rt]-m][son[rt]]);
	printf("%d",ans);
	return 0;
}

