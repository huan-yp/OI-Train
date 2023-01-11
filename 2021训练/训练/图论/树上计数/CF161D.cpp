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
const int N=50005,K=505;
int i,j,k,n,s,t,m;
long long ans;
int dp[N][K],fa[N],cnt[K];
vector<int> e[N];
void dfs(int u)
{
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u,dfs(v);
	}
	memset(cnt,0,sizeof(cnt));
	cnt[0]=dp[u][0]=1;
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		for(i=0;i<=k;i++)
		{
			if(k-i-1>=0)ans+=1ll*cnt[k-i-1]*dp[v][i];
			dp[u][i]+=dp[v][i-1];
		}
		for(i=0;i<=k;i++)
		cnt[i]+=dp[v][i-1];
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}

