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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=500005;
int i,j,k,n,s,t,m;
int dp[N],from[N],dis[N],fa[N],pd[N],a[N],sheep[N];
vector<int> e[N];
bool cmp(int a,int b)
{
	return dis[a]>dis[b];
}
void predfs(int u)
{
	if(sheep[u])dp[u]=0;	
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		fa[v]=u;dis[v]=dis[u]+1;
		predfs(v);
		cmin(dp[u],dp[v]+1);
	}
}
void redfs(int u)
{
	if(sheep[u])from[u]=0;
	int lst=from[u];
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		cmin(from[v],lst+1);
		cmin(lst,dp[v]+1);
	}
	lst=from[u];if(sheep[u])lst=0;
	for(int i=e[u].size()-1;i>=0;i--)
	{
		int v=e[u][i];
		if(fa[u]==v)continue;
		cmin(from[v],lst+1);
		redfs(v);
		cmin(lst,dp[v]+1);
	}
	cmin(dp[u],from[u]);
}
void clear(int u)
{
	pd[u]=1;
	for(int v:e[u])
	{
		if(pd[v]||dp[v]>=dp[u])continue;
		clear(v);
	}
}
int find(int u)
{
	if(dp[fa[u]]>dp[u]&&u!=1)
	return find(fa[u]);
	else
	return u;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dp,1,sizeof(dp)),memset(from,1,sizeof(from));
	read(n),read(k);
	for(i=1;i<n;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(i=1;i<=k;i++)
	read(a[i]),sheep[a[i]]=1;
	predfs(1);
	redfs(1);
	sort(a+1,a+k+1,cmp);
	for(i=1;i<=k;i++)
	{
		if(pd[a[i]])continue;
		s++;
		int u=find(a[i]);
		clear(u);
	}
	cout<<s<<endl;
	return 0;
}

