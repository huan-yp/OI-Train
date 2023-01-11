#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define N 2000005
#define lowbit(x) x & (-x)
#define f1(i, n) for(int i = 1; i <= n; i++)
#define f(i, a, n) for(int i = a; i <= n; i++)
#define f0(i, n) for(int i = 0; i < n; i++)
#define dbg(x) cout << #x << ":" << x << endl;
#define sc second
#define fr first
#define y1 juruo
#define mp make_pair
#define pb push_back
#define arr vector<int>
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define sz(x) x.size()
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef pair <int, int> pii;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int Inf = 0x3f3f3f3f;
const int Mod = 1e9+7;
int n, m;
int nd[200005], pre[200005], dfn[200005], dfn2[200005], goup[200005];
void work() {
	cin >>  n;
	double ans = 2;nd[1] = 1;
	f1(i, n) {
		int x;cin >> x;
		dfn[x] = i;
	}
	f1(i, n) {
		int x;cin >> x;
		dfn2[x] = dfn[i];
	}
	f1(i, n) dfn[i] = dfn2[i];
	f1(i, n) {
		goup[dfn[i]] = i;
	}
//	f1(i, n) cout << dfn[i] << ' ';
	f1(i, n-1) {
		if(dfn[i] > dfn[i+1]) ++ ans, nd[i] = 1;
	} 
	f1(i, n-1) {
		if(goup[i] < goup[i+1]-1) pre[goup[i]]++, pre[goup[i+1]]--;  
	}
	
	f1(i, n-1) {
		pre[i] += pre[i-1];
		if(pre[i] == 0 && nd[i] == 0) ans += 0.5;
//		if(pre[i] != 0 || nd[i]) cout << i << endl;
 	}
	cout << setprecision(10) << fixed << ans << endl;
}

signed main() {
  ios::sync_with_stdio(false),cin.tie(NULL);
  freopen("tree.in", "r", stdin);
  freopen("tree.out", "w", stdout);
  int T = 1;
  //cin >> T;
  while(T--) {
  	work();
  }
  return 0;
}

