#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,g[100001],sz[100001],ok[100001];
double f[100001];
std::vector<int> G[100001];
bool cmp(array<int,2> x,array<int,2> y)
{
	return y[1]*x[0]<y[0]*x[1];
}
void dfs(int x)
{
	if(G[x].empty())
	{
		sz[x]=1;
		f[x]=1;
		g[x]=2;
		return ;
	}
	g[x]=2;
	for(int i:G[x])
	{
		dfs(i);
		sz[x]+=sz[i];
		g[x]+=g[i];
	}
	if(ok[x])
		g[x]=2;
	std::vector<array<int,2>> v;
	for(int i:G[x])
		v.push_back({g[i],sz[i]});
	sort(ALL(v),cmp);
	int tot=0;
	for(auto i:v)
	{
		f[x]+=i[1]*tot;
		tot+=i[0];
	}
	for(int i:G[x])
		f[x]+=f[i]*sz[i];
	f[x]=(1.0*f[x])/(1.0*sz[x]);
	f[x]+=1.0;
}
signed main()
{
	fileio("street");
	n=read();
	for(int i=2;i<=n;i++)
	{
		G[read()].push_back(i);
		char c;
		cin>>c;
		if(c=='Y')
			ok[i]=1;
	}
	dfs(1);
	printf("%.10f\n", f[1]-1.0);
	// cout<<f[1]-1.0;
	return 0;
}