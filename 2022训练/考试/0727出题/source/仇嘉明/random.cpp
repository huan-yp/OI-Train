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
int n,m,cnt;
vector<pair<int,int> > pf;
bool tag[100005];
int val[100005];
void factorize()
{
	for(int i=2;i*i<=m;++i)
	{
		if(m%i==0)
		{
			int cnt=0;
			while(m%i==0)
			{
				m/=i;++cnt;
			}
			pf.pb(mp(i,cnt));
		}
	}
	if(m>1) pf.pb(mp(m,1));
}
int main()
{
	#ifndef DEBUG
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	factorize();
	--n;
	for(int i=0;i<=n;++i) tag[i]=1;
	rep(_,pf.size())
	{
		val[0]=0;
		for(int i=1;i<=n;++i)
		{
			val[i]=i/pf[_].fi+val[i/pf[_].fi];
		}
		for(int i=0;i<=n;++i)
		{
			if(val[n]-val[n-i]-val[i]<pf[_].se)
			{
				tag[i]=0;
			}
		}
	}
	for(int i=0;i<=n;++i) if(tag[i]) ++cnt;
	printf("%d\n",cnt);
	for(int i=0;i<=n;++i) if(tag[i]) printf("%d\n",i+1);
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




