#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=2e5+10,M=505,mod=998244353; 
struct edge{
	int u,v,val;
	bool operator <(const edge b){return val<b.val;}
}a[N];
int i,j,k,n,s,t,m;
int dp[N][M],fa[N],val[N],siz[N];
vector<int> e[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
void dfs(int u)
{
	dp[u][0]=1;siz[u]=1;
	for(int v:e[u])
	{
		dfs(v);siz[u]+=siz[v];
		for(i=min(siz[u],k);i>=0;i--)
		{
			int tmp=0;
			for(j=min(siz[v],i);j+siz[u]-siz[v]>=i&&j>=0;j--)
			Inc(tmp,1ll*dp[u][i-j]*dp[v][j]%mod);
			
			dp[u][i]=tmp;
		}
	}
	if(e[u].size()<=k&&e[u].size())
	dp[u][e[u].size()]--;
	dp[u][1]++;
}
void Kru()
{
	for(i=1;i<=m;i++)
	{
		int u=find(a[i].u),v=find(a[i].v);
		if(u==v)continue;
		if(val[v]==val[u]&&a[i].val==val[v])
		{
			if(e[u].size()<e[v].size())swap(u,v);fa[v]=u;
			for(int x:e[v])fa[x]=u,e[u].push_back(x);	
			continue;
		}
		if(val[v]==a[i].val){e[v].push_back(u),fa[u]=v;continue;}
		if(val[u]==a[i].val){e[u].push_back(v),fa[v]=u;continue;}
		val[++t]=a[i].val,e[t].push_back(u),e[t].push_back(v);
		fa[u]=fa[v]=t;
	}
}
signed main()
{
	read(n),read(m),read(k);
	for(i=1;i<=n<<1;i++)fa[i]=i;
	for(i=1;i<=m;i++)read(a[i].u),read(a[i].v),read(a[i].val);
	t=n;sort(a+1,a+m+1); 
	Kru();
	for(i=1;i<=t;i++)
	if(find(i)==i)e[0].push_back(i);
	dfs(0);int ans=0;
	for(i=0;i<=k;i++)Inc(ans,dp[0][i]);
	printf("%d\n",(ans-(k<e[0].size())+mod)%mod);
	return 0;
}

