#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
const int N=3e3+10;
int dp[N][N][2];
struct fu{
	int val,next,v;
}a[N<<1];
int head[N],fa[N],w[N],son[N],cnt[N];
void work(int aa,int bb,int cc)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].val=cc;
	a[k].v=bb;
}
void dfs(int u)
{
	dp[u][0][0]=0;
	for(int j=1;j<=n;j++)
	dp[u][j][0]=dp[u][j][1]=-1e9;
	for(int i=head[u];i;i=a[i].next)
	{
		cnt[u]++;
		int v=a[i].v;
		dfs(v);
		son[u]+=son[v];
		for(int j=0;j<=son[u];j++)
		{
			dp[u][j][cnt[u]%2]=dp[u][j][(cnt[u]-1)%2]; 
			for(int s=1;s<=son[v]&&s<=j;s++)
			dp[u][j][cnt[u]%2]=max(dp[u][j][cnt[u]%2],dp[u][j-s][(cnt[u]-1)%2]+dp[v][s][cnt[v]%2]-a[i].val);
		}
	}
	if(u>n-m)
	{
		son[u]++;
		cnt[u]=1;
		dp[u][1][cnt[u]]=w[u];
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n-m;i++)
	{
		scanf("%d",&s);
		for(j=1;j<=s;j++)
		{
			int y,z;
			scanf("%d%d",&y,&z);
			work(i,y,z); 
		}	
	}
	for(i=n-m+1;i<=n;i++)
	scanf("%d",&w[i]);
	dfs(1);
	int ans=0;
	for(i=1;i<=n;i++)
	if(dp[1][i][cnt[1]%2]>=0)
	ans=i;
	printf("%d",ans);
	return 0;
}

