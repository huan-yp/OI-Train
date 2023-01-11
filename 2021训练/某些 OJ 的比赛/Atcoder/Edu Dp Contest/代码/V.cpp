#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=1e5+10;
int i,j,k,n,s,t,mod;
int dp[N],ans[N];
vector<int> pre[N],suf[N],a[N];
void dfs(int u,int fa)
{
	pre[u].reserve(a[u].size()+1),suf[u].reserve(a[u].size()+1);
	pre[u][0]=suf[u][a[u].size()]=dp[u]=1;
	for(int i=1;i<a[u].size();i++)
	{
		if(a[u][i]==fa)continue;
		dfs(a[u][i],u);
		dp[u]=1ll*dp[u]*(dp[a[u][i]]+1)%mod;
	}
	
	for(int i=1;i<a[u].size();i++)
	{
		if(a[u][i]==fa)
		pre[u][i]=pre[u][i-1];
		else
		pre[u][i]=1ll*(dp[a[u][i]]+1)*pre[u][i-1]%mod;
	}
	for(int i=a[u].size()-1;i>=1;i--)
	{
		if(a[u][i]==fa)
		suf[u][i]=suf[u][i+1];
		else
		suf[u][i]=1ll*(dp[a[u][i]]+1)*suf[u][i+1]%mod;
	}
}
void rdfs(int u,int fa)
{
	for(int i=1;i<a[u].size();i++)
	{
		if(a[u][i]==fa)continue;
		ans[a[u][i]]=(1ll*ans[u]*(1ll*pre[u][i-1]*suf[u][i+1]%mod)+1)%mod;
		rdfs(a[u][i],u);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(mod);
	for(i=1;i<=n;i++)
	a[i].push_back(0);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	ans[1]=1;
	rdfs(1,0);
	for(i=1;i<=n;i++)
	printf("%d\n",1ll*ans[i]*dp[i]%mod);
	return 0;
}


