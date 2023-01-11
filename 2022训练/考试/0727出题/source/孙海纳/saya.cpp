#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define STR string
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
ll n,X,m;
ll a[1010];
inline void func1()
{
	for (int i=0;i<n;i++) scanf("%lld",&a[i]);
	ll res=0;
	for (ll Y=1;Y<=m;Y++)
	{
		if (Y<=X)
		{
			res^=(a[0]+Y)*Y;
			continue; 
		}
		ll ans=a[0]+Y;
		vector<PLL> v;
		for (int i=0;i<n;i++)
		{
			PLL p=MP(a[i]+X,a[i]);
			while (!v.empty() && v.back().Snd<p.Fst)
			{
				//cout <<v.back().Fst<<" "<<v.back().Snd<<" $$\n";
				p.Fst+=v.back().Fst-v.back().Snd,v.pop_back();
			}
			v.push_back(p);
			//cout <<ans<<" "<<p.Fst<<" "<<p.Snd<<" "<<v[0].Fst<<" "<<v[0].Snd<<" "<<(i==n-1 ? -1 : a[i+1]+Y)<<" ##\n";
			ans=min(ans,max(v[0].Fst,(i==n-1 ? -1 : a[i+1]+Y)));
		}
		//cout <<Y<<" "<<ans<<" ##################\n";
		res^=ans*Y;
	}
	printf("%lld",res);
}
int main()
{
	freopen("saya.in","r",stdin);
	freopen("saya.out","w",stdout);
	scanf("%lld%lld%lld",&n,&X,&m);
	func1();
	return 0;
} 
