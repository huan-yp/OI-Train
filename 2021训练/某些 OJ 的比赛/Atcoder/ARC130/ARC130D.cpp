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
const int N=3005,mod=998244353;
int i,j,k,n,s,t,m,ans;
int dp[N][N],C[N][N],sum[N][N],tmp[N],fa[N],sz[N];
vector<int> e[N];
void dfs(int u,int op)
{
	//op=1 Îª¸ù´ó 
	dp[u][0]=1;sz[u]=1;
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		fa[v]=u;dfs(v,op^1);
		if(op==1)
		{
			for(int i=0;i<sz[u]+sz[v];i++)
			{
				tmp[i]=0;
				for(int j=max(0,i-sz[v]);j<sz[u]&&j<i;j++)
				tmp[i]+=1ll*dp[u][j]*C[sz[u]+sz[v]-i-1][sz[u]-j-1]%mod*C[i][j]%mod*sum[v][i-j-1]%mod,tmp[i]%=mod;
			}
		}
		else
		{
			for(int i=0;i<sz[u]+sz[v];i++)
			{
				tmp[i]=0;
				for(int j=max(0,i-sz[v]+1);j<sz[u]&&j<=i;j++)
				tmp[i]+=1ll*dp[u][j]*C[sz[u]+sz[v]-i-1][sz[u]-j-1]%mod*C[i][j]%mod*(sum[v][sz[v]]-(i-j-1<0?0:sum[v][i-j-1]))%mod,tmp[i]%=mod;
			}
		}
		sz[u]+=sz[v];for(int i=0;i<sz[u];i++)dp[u][i]=tmp[i];
	}
	sum[u][0]=dp[u][0];
	for(int i=1;i<=sz[u];i++)sum[u][i]=(sum[u][i-1]+dp[u][i])%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);C[0][0]=C[1][0]=1;
	for(i=1;i<=n;i++)
	for(C[i][0]=1,j=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	
	for(i=1;i<n;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1,1);
	for(i=0;i<=n;i++)ans=(ans+dp[1][i])%mod;
	memset(dp,0,sizeof(dp)),memset(sum,0,sizeof(sum));
	dfs(1,0);
	for(i=0;i<=n;i++)ans=(ans+dp[1][i])%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}

