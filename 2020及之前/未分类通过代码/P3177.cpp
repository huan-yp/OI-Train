#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
#define int long long
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
const int N=2e3+10;
struct fu{
	int next,v,val;
}a[N<<1]; 
int head[N],dp[N][N][2],size[N],cnt[N],siz[N],fa[N];
void work(int aa,int bb,int cc)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].v=bb;
	a[k].val=cc;
}
void dfs(int u)
{
	int k,j;
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(fa[u]==v)
		continue;
		fa[v]=u;
		dfs(v);
		size[u]+=size[v];
		cnt[u]++;
		for(j=max((long long)0,m-(n-size[u]));j<=size[u]&&j<=m;j++)
		{
			dp[u][j][cnt[u]%2]=0;
			for(k=max((long long)0,j-(size[u]-size[v]));k<=size[v]&&k<=j;k++)
			dp[u][j][cnt[u]%2]=max(dp[u][j][cnt[u]%2],dp[u][j-k][(cnt[u]-1)%2]+dp[v][k][cnt[v]%2]+a[i].val*k*(m-k)+a[i].val*(size[v]-k)*(n-m-size[v]+k));
		}
	}
	size[u]++;
	cnt[u]++;
	for(j=max((long long)0,m-(n-size[u]));j<=size[u]&&j<=m;j++)
	{
		dp[u][j][cnt[u]%2]=0;
		for(k=max((long long)0,j-(size[u]-1));k<=1&&k<=j;k++)
		dp[u][j][cnt[u]%2]=max(dp[u][j][cnt[u]%2],dp[u][j-k][(cnt[u]-1)%2]);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n-1;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		work(x,y,z);
		work(y,x,z);
	}
	dfs(1);
	printf("%lld",dp[1][m][cnt[1]%2]);
	return 0;
}
