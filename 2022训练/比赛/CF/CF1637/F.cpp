#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
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
const int N=3e5+10; 
int i,j,k,n,s,t,m;
int maxn[N],fa[N],dp[N],h[N];
vector<int> e[N];
void dfs(int u)
{
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;dfs(v);dp[u]+=dp[v];
		cmax(maxn[u],maxn[v]);
	}
	if(u!=s)dp[u]+=max(0ll,h[u]-maxn[u]);
	cmax(maxn[u],h[u]);
}
bool cmp(int a,int b)
{
	return maxn[a]>maxn[b];
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for(i=1;i<=n;i++)
	{
		read(h[i]);
		if(h[i]>h[s])s=i;
	}
	for(i=1;i<n;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);	
	}
	dfs(s);
	sort(e[s].begin(),e[s].end(),cmp);
	dp[s]+=h[s]-maxn[e[s][0]];
	if(e[s].size()==1)dp[s]+=h[s];
	else dp[s]+=h[s]-maxn[e[s][1]];
	cout<<dp[s]<<endl;
	return 0;
}

