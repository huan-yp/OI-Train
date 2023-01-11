#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m;
const int N=3e5+10;
int ans[N],col[N],sum[N],fa[N];
vector<int> e[N];
void dfs(int u)
{
	if(col[u]==1)ans[u]=1,sum[u]=1;
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		fa[v]=u;dfs(v);
		if(col[v]==1||(ans[v]&&sum[v]>=2))ans[u]=1;
		sum[u]+=sum[v];
	}	
}
void redfs(int u)
{
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		if(col[u]==1||(ans[u]==1&&sum[1]-sum[v]>=2))ans[v]=1;
		redfs(v);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)read(col[i]);
	for(i=1;i<n;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);		
	}
	dfs(1);
	redfs(1);
	for(i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}

