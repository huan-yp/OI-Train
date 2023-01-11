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
const int N=100005;
int i,j,k,n,s,t,m,flag;
int in[N],dp[N],cnt[N],val[N],vis[N];
vector<pair<int,int>> e[N];
queue<int> q;
void spfa()
{
	memset(dp,-1,sizeof(dp));
	q.push(0);dp[0]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		in[u]=0;
		for(auto tmp:e[u])
		{
			int v=tmp.first,val=tmp.second;
			if(dp[v]>=dp[u]+val)continue;
			dp[v]=dp[u]+val;
			if(in[v])continue;
			q.push(v);in[v]=1;
		}
		if(flag)break;
	}
}
void dfs(int u)
{
	in[u]=1;vis[u]=1;
	for(auto tmp:e[u])
	{
		int vl=tmp.second,v=tmp.first;
		if(vis[v])
		{
			if(in[v]==0||val[v]==val[u]+vl)continue;
			flag=1;
		}
		else
		{
			val[v]=val[u]+vl;
			dfs(v);
		}
	}
	in[u]=0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)
	e[0].push_back(make_pair(i,0));
	for(i=1;i<=k;i++)
	{
		int x,y,op;
		read(op),read(x),read(y);
		if(op==2)e[x].push_back(make_pair(y,1));
		if(op==3||op==1)e[y].push_back(make_pair(x,0));
		if(op==4)e[y].push_back(make_pair(x,1));
		if(op==5||op==1)e[x].push_back(make_pair(y,0));
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i])continue;
		dfs(i);
	}
	if(flag)
	{
		puts("-1");
		return 0;
	}
	spfa();
	LL ans=0;
	for(i=1;i<=n;i++)
	ans+=dp[i];
	cout<<ans+n<<endl;
	return 0;
}

