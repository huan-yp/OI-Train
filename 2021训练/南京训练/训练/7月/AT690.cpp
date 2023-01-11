#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define size siz
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



*/
int i,j,k,n,s,t,m,ans;
const int N=1005,mod=1e9+7;
int dp[N],size[N],f[N]={1},inv[N]={1},ed[N][2];
vector<int> e[N];
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)
		ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
int C(int n,int m)
{
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
void dfs(int u,int fa)
{
	dp[u]=1;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		size[u]+=size[v];
		dp[u]=1ll*dp[u]*dp[v]%mod*C(size[u],size[v])%mod;
	}
	size[u]++;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		ed[i][0]=x,ed[i][1]=y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(i=1;i<n;i++)
	{
		memset(dp,0,sizeof(dp));
		memset(size,0,sizeof(size));
		int u=ed[i][0],v=ed[i][1];
		dfs(u,v);
		dfs(v,u);
		ans+=1ll*dp[u]*dp[v]%mod*C(n-2,size[u]-1)%mod;
		ans%=mod;
	}
	printf("%d\n",ans);
	return 0;
}

