#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);加快cin
int n;
int par[100005];
vector<int> c[100005];
bool q[100005];
long long dp1[100005];
long long dp2[100005];
int leaf[100005];
bool flag;
char C;
void dfs1(int ver)
{
	if(c[ver].empty())
	{
		dp1[ver]=dp2[ver]=0;
		leaf[ver]=1;
		return;
	}
	int cnt=c[ver].size();
	vector<int> son;son.clear();
	rep(i,cnt)
	{
		son.pb(c[ver][i]);
		dfs1(son[i]);
		leaf[ver]+=leaf[son[i]];
	}
	sort(son.begin(),son.end());
	dp1[ver]=dp2[ver]=0x3f3f3f3f3f3f3f3fll;
	ll cur,ans;
	do
	{
		cur=0;ans=0;
		rep(i,cnt)
		{
			++cur;
			ans+=cur*leaf[son[i]]+dp1[son[i]];
			cur+=dp2[son[i]];
			++cur;
		}
		dp1[ver]=min(dp1[ver],ans);
		dp2[ver]=min(dp2[ver],ans);
	}
	while(next_permutation(son.begin(),son.end()));
	if(q[ver]) dp2[ver]=0; 
}
bool cmp(int a,int b)
{
	return leaf[a]*dp2[b]>leaf[b]*dp2[a];
}
void dfs2(int ver)
{
	if(c[ver].empty())
	{
		dp1[ver]=dp2[ver]=0;
		leaf[ver]=1;
		return;
	}
	int cnt=c[ver].size();
	vector<int> son;son.clear();
	rep(i,cnt)
	{
		son.pb(c[ver][i]);
		dfs1(son[i]);
		leaf[ver]+=leaf[son[i]];
	}
	sort(son.begin(),son.end(),cmp);
	dp1[ver]=dp2[ver]=0;
	rep(i,cnt)
	{
		++dp2[ver];
		dp1[ver]+=dp2[ver]*leaf[son[i]]+dp1[son[i]];
		dp2[ver]+=dp2[son[i]];
		++dp2[ver];
	}
	if(q[ver]) dp2[ver]=0; 
}
int mx;
int main()
{
	#ifndef DEBUG
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i<=n;++i)
	{
		cin>>par[i]>>C;
		c[par[i]].pb(i);
		if(C=='Y') q[i]=1;
	}
	for(int i=1;i<=n;++i)
	{
		mx=max(mx,int(c[i].size()));
	}
	if(n<=10||mx<=5)
	dfs1(1);
	else
	dfs2(1);
	cout<<dp1[1]/leaf[1]<<'.';dp1[1]%=leaf[1];
	for(int i=0;i<9;++i)
	{
		dp1[1]*=10;cout<<dp1[1]/leaf[1];dp1[1]%=leaf[1];
	}
	cout<<endl;
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not 正难则反 or few affect?
*/




