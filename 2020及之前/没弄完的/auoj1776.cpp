#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
const int N=1e2+10;
int i,j,k,n,s,t,m;
int ans[N],dis[N],lca[N][N],w[N],fa[N];
vector<int>a[N];
void dfs(int u)
{
	for(int v:a[u])
	{
		if(fa[u]==v)continue;
		fa[v]=u,dis[v]=dis[u]+1;
		dfs(v);
	}
}
int Lca(int x,int y)
{
	if(dis[y]>dis[x])swap(y,x);
	while(dis[y]!=dis[x])
	x=fa[x];
	if(x==y)return x;
	while(fa[y]!=fa[x])
	x=fa[x],y=fa[y];
	return fa[x];
}
signed main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(ans,1,sizeof(ans));
	read(n);
	for(i=1;i<=n;i++)
	read(w[i]);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	lca[i][j]=Lca(i,j);
	for(i=0;i<1<<n;i++)
	{
		int sum=0;
		for(j=1;j<=n;j++)
		if(((1<<j-1)&i)==0))
		sum+=dis[j];
		for(j=1;j<=n;j++)
		for(k=1;k<=n;k++)
		{
			if(((1<<j-1)&i)==0&&((1<<k-1)&i)==0&&((j>k&&lca[j][k]!=j&&lca[j][k]!=k)||(w[j]>w[k]&&lca[j][k]==j)))
			sum++;
			if(((1<<j-1)&i)&&((1<<k-1)&i)&&(lca[j][k]==j&&w[j]<w[k]))//不一定是1 
			sum++;
		}
		ans[__builtin_popcount(i)]=min(ans[__builtin_popcount(i)],sum);
	}
	for(i=0;i<=n;i++)
	printf("%d\n",ans[i]);
	return 0;
}

