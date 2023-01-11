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
const int N=2505;
int i,j,k,n,s,t,m;
struct edge{
	int u,v,val;
	friend bool operator <(edge aa,edge bb)
	{
		return aa.val<bb.val;
	}
	friend bool operator >(edge aa,edge bb)
	{
		return aa.val>bb.val;
	}
}e[N*N];
int val[N][N],dis[N][N];
int fa[N];
vector<edge> a[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void kru()
{
	sort(e+1,e+n*n+1);
	for(i=1;i<=n*n;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		fa[u]=v;
		a[e[i].u].push_back(e[i]);
		a[e[i].v].push_back(edge{e[i].v,e[i].u,e[i].val});
	}
}
void dfs(int u,int fa=0)
{
	for(edge v:a[u])
	{
		if(fa==v.v)continue;
		dis[i][v.v]=max(dis[i][u],v.val);
		dfs(v.v,u);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	fa[i]=i;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	read(val[i][j]),e[++t]=(edge){i,j,val[i][j]};
	kru();
	for(i=1;i<=n;i++)
	dfs(i);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(val[i][j]>dis[i][j])
		{
			printf("NOT MAGIC\n");
			return 0;
		}
	}
	printf("MAGIC\n");
	return 0;
}


