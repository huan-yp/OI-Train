#include<bits/stdc++.h>
#define int long long
#define INF 1000000000ll
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=2505;
int i,j,k,m,n,s,t,ans,start,top;
int val[N][N],x[N],dfn[N],st[N],in[N],ls[N],isroot[N],dep[N];
int low[N],col[N],w[N][N],rk[N],vis[N],minu[N],dp[N],siz[N];
vector<int> a[N],e[N];
void predfs(int u,int fa)
{
	dfn[u]=low[u]=++t;
	st[++top]=u,in[u]=1;int flag=1;
	for(int v:a[u])
	{
		if(v==fa&&flag)
		{
			flag=0;
			continue;
		}
		if(dfn[v])
		{
			if(in[v])
			cmin(low[u],dfn[v]);
		}
		else
		{
			predfs(v,u);
			cmin(low[u],low[v]);
		}
	}
	if(dfn[u]==low[u])
	{
		++s;siz[s]++;
		while(st[top]!=u)
		{
			int v=st[top--];
			col[v]=s;siz[s]++;
		}
		col[st[top--]]=s;
	}
}
void redfs(int u)
{
	vis[u]=1;
	for(int v:e[u])
	{
		if(vis[v])continue;
		dep[v]=dep[u]+1;
		redfs(v);
		cmax(rk[u],rk[v]);
	}
}
bool cmp(int a,int b)
{
	if(rk[a]!=rk[b])
	return rk[a]<rk[b];
	return dep[a]>dep[b];
}
signed main()
{
	//freopen("terraria.in","r",stdin);
	//freopen("terraria.out","w",stdout);
	memset(w,1,sizeof(w));x[0]=-1;
	memset(minu,1,sizeof(minu));
	memset(dp,1,sizeof(dp));
	read(n);ls[n+1]=n+1;
	for(i=1;i<=n;i++)
	{
		read(x[i]);ls[i]=i;
		for(j=0;j<=n;j++)read(val[i][j]);int tmp=val[i][x[i]];
		for(j=0;j<=n;j++)val[i][j]-=tmp;
		
		ans+=tmp;
		a[x[i]].push_back(i);
		a[i].push_back(x[i]);
	}
	for(i=0;i<=n;i++)
	{
		if(dfn[i])continue;
		predfs(i,-1);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(j==x[i])continue;
			cmin(w[col[i]][j],val[i][j]);
			cmin(minu[col[i]],val[i][j]);
		}
		for(int v:a[i])
		{
			if(col[v]==col[i])continue;
			e[col[i]].push_back(col[v]);
		}
		cmax(rk[col[i]],i);
	}
	for(i=0;i<=n;i++)
	if(x[i]==-1||x[i]==i)siz[col[i]]=-1;
	for(i=1;i<=s;i++)
	{
		if(vis[i]||(siz[i]==1))continue;
		ans+=minu[i],redfs(i);
		isroot[i]=1;
	}
	dp[0]=0;int opt=1e18;
	sort(ls+1,ls+s+1,cmp);
	for(i=0;i<=s;i++)
	{
		if(isroot[ls[i]])dp[ls[i]]-=minu[ls[i]];
		for(j=i+1;j<=s;j++)
		cmin(dp[ls[j]],dp[ls[i]]+w[ls[j]][rk[ls[i]]]);
	}
	cout<<dp[ls[s]]+ans<<endl;
	return 0;
}

