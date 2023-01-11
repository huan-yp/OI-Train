 #pragma GCC optimize(3)
 #pragma GCC target("avx")
 #pragma GCC optimize("Ofast")
 #pragma GCC optimize("inline")
 #pragma GCC optimize("-fgcse")
 #pragma GCC optimize("-fgcse-lm")
 #pragma GCC optimize("-fipa-sra")
 #pragma GCC optimize("-ftree-pre")
 #pragma GCC optimize("-ftree-vrp")
 #pragma GCC optimize("-fpeephole2")
 #pragma GCC optimize("-ffast-math")
 #pragma GCC optimize("-fsched-spec")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("-falign-jumps")
 #pragma GCC optimize("-falign-loops")
 #pragma GCC optimize("-falign-labels")
 #pragma GCC optimize("-fdevirtualize")
 #pragma GCC optimize("-fcaller-saves")
 #pragma GCC optimize("-fcrossjumping")
 #pragma GCC optimize("-fthread-jumps")
 #pragma GCC optimize("-funroll-loops")
 #pragma GCC optimize("-fwhole-program")
 #pragma GCC optimize("-freorder-blocks")
 #pragma GCC optimize("-fschedule-insns")
 #pragma GCC optimize("inline-functions")
 #pragma GCC optimize("-ftree-tail-merge")
 #pragma GCC optimize("-fschedule-insns2")
 #pragma GCC optimize("-fstrict-aliasing")
 #pragma GCC optimize("-fstrict-overflow")
 #pragma GCC optimize("-falign-functions")
 #pragma GCC optimize("-fcse-skip-blocks")
 #pragma GCC optimize("-fcse-follow-jumps")
 #pragma GCC optimize("-fsched-interblock")
 #pragma GCC optimize("-fpartial-inlining")
 #pragma GCC optimize("no-stack-protector")
 #pragma GCC optimize("-freorder-functions")
 #pragma GCC optimize("-findirect-inlining")
 #pragma GCC optimize("-fhoist-adjacent-loads")
 #pragma GCC optimize("-frerun-cse-after-loop")
 #pragma GCC optimize("inline-small-functions")
 #pragma GCC optimize("-finline-small-functions")
 #pragma GCC optimize("-ftree-switch-conversion")
 #pragma GCC optimize("-foptimize-sibling-calls")
 #pragma GCC optimize("-fexpensive-optimizations")
 #pragma GCC optimize("-funsafe-loop-optimizations")
 #pragma GCC optimize("inline-functions-called-once")
 #pragma GCC optimize("-fdelete-null-pointer-checks")
 #pragma GCC optimize(2)
#include<bits/stdc++.h>
//#include<iostream>
//#include<string>
//#include<cmath>
//#include<cstdio>
//#include<cctype>
//#include<cstring>
//#include<iomanip>
//#include<cstdlib>
//#include<ctime>
//#include<set>
//#include<map>
//#include<utility>
//#include<queue>
//#include<vector>
//#include<stack>
//#include<sstream>
//#include<algorithm>
using namespace std;
/*=====================================================================*/
#define ll long long
//#define int ll
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(s) (s).begin(),(s).end()
#define repd(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define forr(i,a,b,c) for(int i=(int)(a);i<=(int)(b);i+=(int)(c))
#define forn(i,p,n) for(int i=(int)(p);i<=(int)(n);++i)
#define ford(i,p,n) for(int i=(int)(n);i>=(int)(p);--i)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();++i)
#define INF 0x3f3f3f3f
#define PI acos(-1)
#define Endl(x) cout<<x<<endl;
#define Blank(x) cout<<x<<" ";
#define modcg(x) if(x>=mod)x-=mod;
#define modcl(x) if(x<0)x+=mod;
/*=====================================================================*/
string int_to_string(ll n)
{
	string s="";
	while(n)
	{
		ll now=n%10;
		s+=now+'0';
		n/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
ll string_to_int(string s)
{
	ll n=0;
	rep(i,s.size())
	{
		n*=10;
		n+=s[i]-'0';
	}
	return n;
}
/*======================================================================*/
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
const int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
//think twice,code once
//think once,debug forever
const int MAXN=1e5+10;
int prime[MAXN];
int head;
bool use[MAXN];
int down[MAXN];
void init()
{
	forn(i,2,100000)
	{
		if(!use[i])
		{
			down[i]=head;
			prime[head++]=i;
		}
		rep(j,head)
		{
			int now=prime[j];
			if(now*i>MAXN)
			{
				break;	
			}
			use[now*i]=1;
			if(i%now==0)
			{
				break;
			}
		}
	}
}
int cnt[MAXN];
int cmt[MAXN];
vii v[MAXN];
void solve()
{
	init();
	int n,m;
	cin>>n>>m;
	rep(i,head)
	{
		while(m%prime[i]==0)
		{
			cmt[i]++;
			m/=prime[i];
		}
	}
	if(m!=1)
	{
		cout<<0<<endl;
		return;
	}
	n--;
	forn(i,1,n)
	{
		int x=i;
		rep(j,head)
		{
			if(prime[j]*prime[j]>x)
			{
				break;
			}
			int now=0;
			while(x%prime[j]==0)
			{
				now++;
				x/=prime[j];
			}
			if(now)
			{
				v[i].emplace_back(j,now);
			}
			if(x==1)
			{
				break;
			}
		}
		if(x!=1)
		{
			v[i].emplace_back(down[x],1);
		}
	}
	// forn(i,1,n)
	// {
		// cout<<i<<":"<<endl;
		// for(auto [x,y]:v[i])
		// {
			// cout<<x<<" "<<y<<endl;
		// }
		// cout<<endl;
	// }
	vi ans;
	int yesok=0;
	rep(i,head)
	{
		if(cnt[i]>=cmt[i])
		{
			yesok++;
		}
	}
	if(yesok==head)
	{
		ans.emplace_back(1);
	}
	// cout<<yesok<<" "<<head<<endl;
	forn(i,1,n)
	{
		for(auto [x,y]:v[n-i+1])
		{
			cnt[x]+=y;
			// cout<<cnt[x]<<" "<<cmt[x]<<endl;
			if(cnt[x]-y<cmt[x]&&cnt[x]>=cmt[x])
			{
				// cout<<prime[x]<<" "<<cnt[x]<<" "<<cmt[x]<<endl;
				yesok++;
			}
		}
		for(auto [x,y]:v[i])
		{
			cnt[x]-=y;
			// cout<<cnt[x]<<" "<<cmt[x]<<endl;
			if(cnt[x]+y>=cmt[x]&&cnt[x]<cmt[x])
			{
				// cout<<prime[x]<<" "<<cnt[x]<<" "<<cmt[x]<<endl;
				yesok--;
			}
		}
		// cout<<yesok<<endl;
		if(yesok==head)
		{
			ans.emplace_back(i+1);
		}
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}
/*======================================================================*/
signed main()
{
    cin.tie(0);
    cout.tie(0);
	std::ios::sync_with_stdio(false);
#define Hank2007
#ifdef Hank2007
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
#endif
  	/*====================================================================*/
  	int TEST_CASE=1;
//	cin>>TEST_CASE;
  	while(TEST_CASE--)
  	{
  		solve();
  	}
  	return 0;
}
