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
const int N=55,mod=112901989;
int i,j,k,n,s,t,m;
vector<int> e[N];
int f[N][N],g[N][N],h[N][N][N];
void dfs(int u,int fa=0)
{
	for(int i=0;i<n;i++)h[u][i][0]=f[u][i]=g[u][i]=1;

	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		for(int i=n-1;i>=1;i--)
		{
			f[u][i]=(1ll*f[u][i]*g[v][i]%mod+1ll*(f[u][i]-h[u][i][i])*(f[v][i]-h[v][i][i])%mod)%mod;
			for(int j=n-1;j>=1;j--)
			h[u][i][j]=(1ll*h[u][i][j]*g[v][i]+1ll*h[u][i][j-1]*(f[v][i]-h[v][i][i]))%mod;
			h[u][i][0]=1ll*h[u][i][0]*g[v][i]%mod;
			
			g[u][i]=1ll*g[u][i]*(f[v][i]+g[v][i])%mod;
		}
		f[u][0]=1ll*f[u][0]*g[v][0]%mod,g[u][0]=1ll*g[u][0]*(g[v][0]+f[v][0])%mod;
	}
}
class TreeCount{
	public:
	vector<int> count(vector<string>graph)
	{
		n=graph.size();
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		if(graph[i-1][j-1]=='Y')
		e[i].push_back(j);
		dfs(1);
		vector<int> ans;ans.clear();
		for(i=0;i<n;i++)
		ans.push_back(((f[1][i]+g[1][i])%mod+mod)%mod);
		
		return ans;
	}	
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	TreeCount solve;
//	auto ans=solve.count(	
//
//	
//	);
//	for(int v:ans)
//	printf("%d ",v);
//
//	return 0;
//}

