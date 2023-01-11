#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
using namespace std;
int n;
ll m,M;
vector<ll> pri;
vector<int> ans;
inline ll qpow(ll A,ll B)
{
	ll res=1ll;
	while(B)
	{
		if (B&1)
			res=res*A%M;
		A=A*A%M;
		B>>=1; 
	}
	return res;
}
ll cnt(ll x,ll p)
{
	ll res=0ll;
	while(x)
	{
		res+=x/p;
		x/=p;
	}
	return res;
}
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n>>m;
	M=m;
	for(int i=2;i*i<=m;i++)
		if (m%i==0)
		{
			pri.pb(i);
			while(m%i==0)
				m/=i; 
		}
	if (m>1)
		pri.pb(m);
	for(int i=0;i<n;i++)
	{
		ll res=1ll;
		for(int j=0;j<(int)pri.size();j++)
		{
			ll c=cnt(n-1,pri[j])-cnt(i,pri[j])-cnt(n-1-i,pri[j]);
			res=res*qpow(pri[j],c)%M;
		}
		if (res==0||M==1)
			ans.pb(i);
	}
	cout<<(int)ans.size()<<endl;
	for(auto x:ans)
		cout<<x+1<<endl;
	return 0;
}
