#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
using namespace std;
vector<int> G[100005];
bool b[100005];
int n;
ll cur;
struct node
{
	int sz,lf,id;
	node(){sz=lf=id=0;}
	node(int A,int B,int C){sz=A,lf=B,id=C;}
	bool operator<(node B){
		return sz*B.lf<B.sz*lf;
	} 
}a[100005];
void dfs0(int u)
{
	a[u]=node(1,0,u);
	if (G[u].empty())
	{
		a[u].lf=1;
		return;
	}
	vector<node> v;
	for(auto to:G[u])
	{
		dfs0(to);
		a[u].sz+=a[to].sz,a[u].lf+=a[to].lf;
		v.pb(a[to]);
	}
	sort(v.begin(),v.end());
	G[u].clear();
	for(auto x:v)
		G[u].pb(x.id);
	if (b[u])
		a[u].sz=1;
}
ll dfs(int u)
{
	if (G[u].empty())
		return cur;
	ll res=0ll;
	for(auto to:G[u])
	{
		ll o=cur;
		cur++;
		res+=dfs(to);
		cur++;
		if (b[to])
			cur=o+2;
	}
	return res;
}
int main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cout<<fixed<<setprecision(9);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int p;char c;cin>>p>>c;--p;
		G[p].pb(i);
		b[i]=(c=='Y'?1:0);
	}
	dfs0(0);
	double ans=dfs(0);
	ans/=(double)a[0].lf*1.0;
	cout<<ans<<endl;
	return 0;
}
