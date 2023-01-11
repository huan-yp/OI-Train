#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*
dis[i][j]
dp[u][i][j]=dp[v][i-1][j+1]+d[min(i,j)]
dp[u][j]=;
*/
const int N=185;
int i,j,k,n,s,t,m;
bitset<N> bst[N][N];
int dp[N][N],dis[N][N],d[N],fa[N],ans[N],dfn[N],size[N];
vector<int> e[N];
int in(int x,int y)
{
	return (dfn[x]>=dfn[y]&&dfn[x]<dfn[y]+size[y]);
}
void dfs(int u,int f)
{
	dfn[u]=++t;
	size[u]++;
	for(int v:e[u])
	{
		if(f==v)continue;
		fa[v]=u;
		dfs(v,u);
		size[u]+=size[v];
	}
}
void dfs(int u)
{
	dp[u][u]=k;bst[u][u][u]=1;
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		dfs(v);
	}
	for(i=1;i<=n;i++)
	{
		dp[u][i]+=d[dis[u][i]];
		for(int v:e[u])
		{
			if(v==fa[u])continue;
			int tmp=dp[v][i],rk=i;
			for(j=1;j<=n;j++)
			{
				if(in(j,v)&&i!=v&&dis[u][i]<=dis[u][j]&&dis[v][j]<=dis[v][i])
				if(dp[v][j]<tmp)
				tmp=dp[v][j],rk=j;
			}
			dp[u][i]+=tmp;bst[u][i]|=bst[v][rk];
		}
	}
}
void getAns(int x)
{
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(bst[1][x][j]==0)continue;
			if(dis[i][j]<dis[i][ans[i]])
			ans[i]=j;
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dis,1,sizeof(dis));
	read(n),read(k);
	for(i=1;i<n;i++)
	read(d[i]),dis[i][i]=0;
	dis[n][n]=0;
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		dis[x][y]=dis[y][x]=1;
		e[x].push_back(y),e[y].push_back(x);
	}
	for(s=1;s<=n;s++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	dis[i][j]=min(dis[i][j],dis[i][s]+dis[s][j]);
	
	dfs(1,0);
	dfs(1);
	int opt=1e9,at;
	for(i=1;i<=n;i++)
	{
		if(dp[1][i]<=opt)
		at=i,opt=dp[1][i];
	}
	cout<<opt<<endl;
	getAns(at);
	for(i=1;i<=n;i++)
	printf("%d ",ans[i]);
	return 0;
}

