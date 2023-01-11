#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<functional>
#include<map>
#include<queue>
#include<bitset>
#include<cmath>
#include<unordered_map>
#include<array>
#include<iomanip>
#include<numeric>
using namespace std;
template<typename T>
inline bool cmax(T& a,const T& b){return a<b?a=b,1:0;}
template<typename T>
inline bool cmin(T& a,const T& b){return b<a?a=b,1:0;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
#define X first
#define Y second
ll mod;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=1e5+10;
bool is[MAXN];
int cnt[MAXN];
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;vi p;
	for(ll i=2;i<MAXN;i++)
	{
		if(is[i])continue;
		p.push_back(i);
		for(ll j=(ll)i*i;j<MAXN;j+=i)is[j]=1;
	} 
	//cerr<<cnt;
	cin>>n>>m;n--;
	mod=m;
	int x=mod;
	vector<pii>v;
	
	for(const int& a:p)
	{
		if(x%a==0)v.push_back({a,0});
		while(x%a==0)x/=a,v.back().Y++;
	}
	if(x>1) v.push_back({x,1});
	auto div=[&](int x,int k)
	{
		if(x==1)return;
		for(const int& a:p)
		{
			while(x%a==0)cnt[a]+=k,x/=a;
			if(!is[x])
			{
				cnt[x]+=k;
				break;
			}
		}
	};
	//for(int i=2;i<=n;i++)div(i,1);
	vi ans;
	if(mod==1) ans.push_back(1);
	for(int i=1;i<=n;i++)
	{
		div(n-i+1,1),div(i,-1);
		bool flag=1;
		for(const pii& x:v)if(x.X>n||cnt[x.X]<x.Y){flag=0;break;}
		if(flag) ans.push_back(i+1);
	}
	cout<<ans.size()<<'\n';
	for(const int& x:ans)cout<<x<<' ';
	return 0;
}

