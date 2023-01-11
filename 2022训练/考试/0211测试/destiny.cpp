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
const int N=65;
int i,j,k,n,s,t,m,ans=1,cnt;
int mp[N][N],ok[N][N],vis[N],deg[N],acc[N],a[N],fa[N];
int dp[N][2],fb[N],fbe[N][N],vs[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int x)
{
	if(acc[x])return;acc[x]=1;
	for(int i=1;i<=n;i++)
	if(mp[x][i])dfs(i);
}
int check()
{
	for(int i=1;i<=n;i++)fa[i]=i;
	
	for(int i=1;i<=n;i++)
	{
		if(acc[i]==0)continue;
		for(int j=1;j<i;j++)
		{
			if(mp[i][j]!=1)continue;
			int u=find(i),v=find(j);
			if(u==v)return 1;
			fa[u]=v;
		}
	}
	return 0;
}
void redfs(int u,int fa=0)
{
	if(vs[u])return ;vs[u]=1;
	dp[u][0]=dp[u][1]=1;
	for(int i=1;i<=n;i++)
	{
		if(mp[u][i]!=1||i==fa)continue;
		redfs(i,u);
		dp[u][1]*=(dp[i][0]+dp[i][1]*(fbe[u][i]==0));
		dp[u][0]*=(dp[i][0]+dp[i][1]);
	}
	if(fb[u])dp[u][1]=0;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		mp[x][y]=mp[y][x]=1;
	}
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(k=1;k<=n;k++)
	if(mp[i][j]&&mp[i][k]&&mp[j][k])ok[i][j]=ok[j][k]=ok[i][k]=1;	
	
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)
	mp[i][j]&=ok[i][j],deg[i]+=mp[i][j];
	
	for(i=1;i<=n;i++)
	{
		if(vis[i])continue;
		memset(acc,0,sizeof(acc));
		dfs(i);cnt=0;
		while(check())
		{
			int rk=0;
			for(j=1;j<=n;j++)
			if(deg[j]>deg[rk]&&acc[j])rk=j;
			
			for(deg[rk]=0,j=1;j<=n;j++)
			if(mp[rk][j])mp[rk][j]=mp[j][rk]=2,deg[j]--;
			a[++cnt]=rk;
		}
		int all=0;
		for(int mask=0;mask<1<<cnt;mask++)
		{
			memset(fb,0,sizeof(fb));
			memset(fbe,0,sizeof(fbe));
			memset(dp,0,sizeof(dp));
			memset(vs,0,sizeof(vs));
			int flag=0;
			for(int i=1;i<=cnt;vs[a[i]]=1,i++)
			if((1<<i-1)&mask)vis[a[i]]=1;
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n&&acc[i];j++)
			for(int k=1;k<=n&&acc[j];k++)
			{
				if(acc[k]==0||mp[i][j]==0||mp[j][k]==0||mp[k][i]==0)continue;
				if(vis[i]&&vis[j]&&vis[k])flag=1;
				if(vis[i]&&!vis[j]&&!vis[k])fbe[j][k]=fbe[k][j]=1;
				if(!vis[i]&&vis[j]&&vis[k])fb[i]=1;
			}
			int tmp=1;
			for(int i=1;i<=cnt;i++)
			if(1<<i-1&mask)vis[a[i]]=0;
			if(flag)continue;
			
			for(int i=1;i<=n;i++)
			{
				if(acc[i]==0||vs[i])continue;
				redfs(i);tmp*=(dp[i][1]+dp[i][0]);
			}
			all+=tmp;
		}
		ans=ans*all;
		for(j=1;j<=n;j++)vis[j]|=acc[j];
	}
	cout<<ans<<endl;
	return 0;
}

