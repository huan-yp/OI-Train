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
const int N=5005,mod=998244353;
int i,j,k,n,s,t,m;
int C[N][N],dp[N][N],f[N],g[N],col[N],sz[N],cnt[N],tmp[N];
char ch[N];
vector<int> e[N];
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;if(x<0)x+=mod;}
void dfs(int u,int fa=0)
{
	sz[u]=1;cnt[u]=col[u]==1;dp[u][0]=1;
	for(int v:e[u])
	{
		if(fa==v)continue;
		dfs(v,u);
		for(int i=0;i<=n/2;i++)tmp[i]=0;
		for(int i=0;i<=sz[u]/2;i++)
		for(int j=0;j<=sz[v]/2;j++)
		Inc(tmp[i+j],1ll*dp[u][i]*dp[v][j]%mod);
		
		for(int i=0;i<=n/2;i++)dp[u][i]=tmp[i];
		sz[u]+=sz[v],cnt[u]+=cnt[v];
	}
	int all=col[u]==0?cnt[u]:sz[u]-cnt[u];
	for(int i=n;i>=1;i--)	
	Inc(dp[u][i],1ll*dp[u][i-1]*(all-i+1)%mod);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);scanf("%s",ch+1);C[0][0]=1;f[0]=1;
	for(i=1;i<=n;i++)col[i]=ch[i]-'0';
	for(i=1;i<=n;i++)
	for(f[i]=1ll*f[i-1]*i%mod,C[i][0]=1,j=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	
	
	for(i=1;i<n;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1);
	for(i=0;i<=n/2;i++)
	for(j=i;j<=n/2;j++)
	Inc(g[i],((j-i)%2?-1ll:1ll)*dp[1][j]*f[n/2-j]%mod*C[j][i]%mod);
	
	for(i=0;i<=n/2;i++)printf("%d\n",(g[i]+mod)%mod);
	return 0;
}

