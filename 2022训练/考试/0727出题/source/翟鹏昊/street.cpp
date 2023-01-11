#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<long long,long long>
#define mp make_pair
#define pb push_back
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18;
int fpow(int x,int b){
	if(x==0) return 0;
	if(b==0) return 1;
	int res=1;
	while(b>0){
		if(b&1)	res=res*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res;
}
int fac[300005];
int C(int x,int y)
{
	return fac[y]*fpow(fac[y-x],mod-2)%mod*fpow(fac[x],mod-2)%mod;
}
int n;
vector <int> g[100005];
int tag[100005];
int sz[100005];
double dp1[100005];
int dp2[100005];
void dfs1(int u,int fa)
{
	int flg=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
	//	cout<<u<<" "<<v<<endl;
		flg=0;
		dfs1(v,u);
		dp2[u]+=dp2[v]+2;
		sz[u]+=sz[v];
	}
	if(flg) sz[u]++;
	if(tag[u]) dp2[u]=0;
}

bool cmp(int x,int y)
{
	return (dp2[x]+2)*sz[y]<(dp2[y]+2)*sz[x];
}
/*
bool cmp(int x,int y)
{
	if(dp2[x]*sz[y]!=dp2[y]*sz[x]) return dp2[x]*sz[y]<dp2[y]*sz[x];
	else if(sz[x]!=sz[y]) return sz[x]>sz[y];
	else return dp2[x]<dp2[y];
}
*/
void dfs2(int u,int fa)
{
	vector <int> ss;
	ss.clear();
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(v==fa) continue;
		dfs2(v,u);
		ss.pb(v);
	}
	sort(ss.begin(),ss.end(),cmp);
	int prv=0;
	for(int i=0;i<ss.size();i++)
	{
		dp1[u]+=(double)((double)(sz[ss[i]])/(double)(sz[u])*((double)(prv)+(double)(2*i+1)+dp1[ss[i]]));
		prv+=dp2[ss[i]];
	}
}
void solve()
{
	scanf("%lld",&n);
	for(int i=2;i<=n;i++)
	{
		int fa;
		scanf("%lld",&fa);
		char x;
		cin>>x;
		g[fa].pb(i),g[i].pb(fa);
		if(x=='Y') tag[i]=1;
	}
	dfs1(1,-1);
//	for(int i=1;i<=n;i++) cout<<sz[i]<<" "<<dp2[i]<<endl;
	dfs2(1,-1);
	printf("%.10lf",dp1[1]);
}
signed main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--) solve();
	return 0;
}
