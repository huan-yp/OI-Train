#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
double f[100100];
double g[100100];
int cnt[100100];
vector<int> G[100100];
bool flag[100100];
bool cmp(pair<double,double> a,pair<double,double> b)
{
	return a.first*b.second<a.second*b.first;
}
void dfs(int u)
{
	if(!sz(G[u]))
	{
		cnt[u]=1;
		return ;
	}
	for(auto v:G[u])
	{
		dfs(v);
		cnt[u]+=cnt[v];
		g[u]+=g[v]+2;
	}
	if(flag[u])
		g[u]=0;
	vector<pair<double,double>> vec;
	for(auto v:G[u])
	{
		f[u]+=(f[v]+1)*cnt[v]/cnt[u];
		vec.pb(mp(2+g[v],1.0*cnt[v]/cnt[u]));
	}
	sort(ALL(vec),cmp);
	double sum=0.0;
	for(auto p:vec)
	{
		f[u]+=p.second*sum;
		sum+=p.first;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	int n;
	cin>>n;
	flag[1]=1;
	for(int i=2;i<=n;i++)
	{
		int x;
		char ch;
		cin>>x>>ch;
		G[x].pb(i);
		if(ch=='Y')
			flag[i]=1;
	}
	dfs(1);
	cout<<fixed<<setprecision(10)<<f[1]<<endl;
	return 0;
}
