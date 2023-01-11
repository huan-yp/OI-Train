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
const int MAXN=2e5+10;
int n;
int dd[MAXN],db[MAXN];
int c[MAXN];
int dfn[MAXN],bfn[MAXN];
void solve()
{
	cin>>n;
	forn(i,1,n)
	{
		cin>>dfn[i];
		dd[dfn[i]]=i;
	}
	forn(i,1,n)
	{
		cin>>bfn[i];
		db[bfn[i]]=i;
	}
	c[1]++;
	c[2]--;
	double ans=2;
	forn(i,1,n-1)
	{
		int x=bfn[i],y=bfn[i+1];
		if(dd[x]>dd[y])
		{
			c[i]++;
			c[i+1]--;
			ans++;
		}
		x=dfn[i],y=dfn[i+1];
		if(db[x]+1<db[y])
		{
			c[db[x]]++;
			c[db[y]]--;
		}
	}
	int all=0;
	forn(i,1,n-1)
	{
		all+=c[i];
		if(!all)
		{
			ans+=0.5;
		}
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
}
/*======================================================================*/
signed main()
{
    cin.tie(0);
    cout.tie(0);
	std::ios::sync_with_stdio(false);
#define Hank2007
#ifdef Hank2007
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
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
