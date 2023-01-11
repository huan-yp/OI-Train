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
const int N=55;
struct edge{
	int v,next,col;
};
int i,j,k,n,s,t,m,ans,top;
int col[N],head[N],dfn[N],st[N],low[N],in[N],no[N],vis[N],pd[N];
vector<int> e[N];
edge a[N*N*2];
void addedge(int u,int v)
{
	a[k].next=head[u];a[k].v=v,head[u]=k++;
	a[k].next=head[v];a[k].v=u,head[v]=k++;
}
void dfs(int u)
{
	dfn[u]=low[u]=++t;st[++top]=u;in[u]=1;
	for(int v:e[u])
	{
		if(dfn[v])
		{
			if(in[v])
			cmin(low[u],dfn[v]);
		}
		else
		dfs(v),cmin(low[u],low[v]);
	}
	if(low[u]==dfn[u])
	{
		col[u]=++s;in[u]=0;
		while(st[top]!=u)
		col[st[top]]=s,in[st[top--]]=0;
		top--;
	}
}
int find(int u,int tp)
{
	if(vis[u]||no[u])return 0;
	if(tp==1&&in[u]==0)return in[u]=1;
	vis[u]=1;
	for(int i=head[u];i!=-1;i=a[i].next)
	{
		if(tp!=a[i].col)continue;
		if(find(a[i].v,tp^1))
		{
			a[i].col^=1,a[i^1].col^=1,vis[u]=0;
			return in[u]=1;
		}	
	} 
	no[u]=1;
	return vis[u]=0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);ans=n;
	for(i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y);
	}
	for(i=1;i<=n;i++)
	{
		if(dfn[i])continue;
		dfs(i);
	}
	for(i=1;i<=n;i++)
	{
		if(pd[col[i]])continue;
		k=0;pd[col[i]]=1;memset(in,0,sizeof(in));
		memset(head,-1,sizeof(head));memset(a,0,sizeof(a));
		for(j=1;j<=n;j++)
		{
			if(col[j]==col[i])continue;
			for(int v:e[j])
			{
				if(col[i]==col[v])
				addedge(j,v);
			}
		}
		while(1)
		{
			int flag=0;
			for(int i=1;i<=n;i++)no[i]=0;
			for(int i=1;i<=n;i++)
			{
				if(in[i]||find(i,0)==0)continue;
				flag=1;break;
			}
			if(flag==0)break;
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

