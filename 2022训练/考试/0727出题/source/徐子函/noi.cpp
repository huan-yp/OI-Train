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
const int MAXN=155,MAXM=550;
int n,m;
int a[MAXN][MAXM];
int dp[12][MAXN][MAXM];
int sum1[MAXN][MAXM],sum2[MAXN][MAXM];
int summe[MAXM];
int get_sum(int l,int r)
{
	return summe[r]-summe[l-1];
}
int get_tp(int i,int j,int t)
{
	return a[i][t]+a[j][t];
}
void solve()
{
	cin>>n>>m;
	forn(i,1,n)
	{
		forn(j,1,m)
		{
			cin>>a[i][j];
		}
	}
	memset(dp,0xcf,sizeof(dp));
	memset(sum1,0xcf,sizeof(sum1));
	memset(sum2,0xcf,sizeof(sum2));
	int ans=-INF;
	forn(t,1,m)
	{
		forn(i,1,n)
		{
			summe[i]=summe[i-1]+a[i][t];
		}
		forn(i,1,n)
		{
			forn(j,i+2,n)
			{
				dp[1][i][j]=max(dp[1][i][j],dp[2][i][j])+get_tp(i,j,t);
				ans=max(ans,dp[1][i][j]);
			}
		}
		forn(i,1,n)
		{
			forn(j,i+2,n)
			{
				dp[2][i][j]=max(dp[2][i][j],dp[3][i][j])+get_sum(i,j);
			}
		}
		forn(i,1,n)
		{
			forn(j,i+2,n)
			{
				dp[3][i][j]=max(dp[3][i][j],dp[4][0][0])+get_tp(i,j,t);
			}
		}
		forn(i,1,n)
		{
			forn(j,i+2,n)
			{
				dp[4][0][0]=max(dp[4][0][0],dp[5][i][j]);
			}
		}
		forn(i,1,n)
		{
			forn(j,i+2,n)
			{
				dp[5][i][j]=dp[6][i][j]+get_sum(i,j);
			}
		}		
		forn(i,1,n)
		{
			forn(j,i+2,n)
			{
				dp[6][i][j]=max(dp[6][i][j],dp[7][i][j])+get_tp(i,j,t);
			}
		}
		forn(i,1,n)
		{
			forn(j,i+2,n)
			{
				dp[7][i][j]=dp[8][0][0]+get_sum(i,j);
			}
		}
		forn(i,1,n)
		{
			forn(j,i+1,n)
			{
				dp[8][0][0]=max(dp[9][i][j],dp[8][0][0]);
			}
		}
		forn(j,2,n)
		{
			int now=dp[10][j][j];
			ford(i,1,j-1)
			{
				dp[9][i][j]=max(dp[9][i][j],now)+get_sum(i,j);
				now=max(now,dp[10][i][j]);
			}
		}
		forn(i,1,n)
		{
			int now=sum2[i][i-1];
			forn(j,i,n)
			{
				now=max(now,sum2[i][j]);
				dp[10][i][j]=max(sum1[i][j+1],now)+get_sum(i,j);
			}
		}
		forn(i,1,n)
		{
			forn(j,i+1,n)
			{
				dp[11][i][j]=max(dp[11][i][j],0)+get_sum(i,j);
			}
		}
		forn(i,1,n)
		{
			ford(j,i,n)
			{
				sum1[i][j]=max(sum1[i][j+1],dp[11][i][j]);
			}
		}
		forn(j,1,n)
		{
			forn(i,1,n)
			{
				sum2[i][j]=max(sum2[i-1][j],dp[10][i][j]);
			}
		}
	}
	cout<<ans<<endl;
}
/*======================================================================*/
signed main()
{
    cin.tie(0);
    cout.tie(0);
	std::ios::sync_with_stdio(false);
#define Hank2007
#ifdef Hank2007
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
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
