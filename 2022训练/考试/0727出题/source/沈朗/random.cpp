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
ll f[100005], C[1004][1004];;
bool Pr(int x) {
	if(x <= 1) return false;
	for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
	return true; 
}
int pww(ll a, ll b) {
	ll ans = 1;//dbg(a);dbg(b);
	while(b) {
		if(b&1) ans = (ans * a) % m;
		a = (a*a) % m;
		b >>= 1;
	}//dbg(ans);
	return ans;
}
ll exgcd(ll a,ll b,ll &x,ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll ret = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return ret;
}
ll Getinv(int a,int mod) {
    ll x, y;
    ll d = exgcd(a,mod,x,y);
    return d == 1 ? (x%mod+mod) % mod:-1;
}
void work() {
	
	cin >> n >> m;
	f[0] = 1;
	f1(i, n) f[i] = (f[i-1] * i) % Mod;
	arr ans;
	if(m == 1) {
		cout << n << endl;f1(i, n) cout << i << ' ' ;cout << endl;
	} else if(n == 1) {
		cout << 0 << endl;
	}
	else if(0) {
		C[0][0] = 1;
		f1(i, 1000) f1(j, 1000) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % m;
//		f1(i, 10) f1(j, 10) cout << i << ' ' << j << ':' << C[i][j] << endl;
		f1(i, n) if(!C[n][i]) ans.pb(i);
	} else {
//		cout << Getinv(f[2], 4) << " " << " " << endl;
		f1(i, n) if(Getinv(f[i-1], m) != -1 && Getinv(f[n-i], m) != -1 && (f[n-1] * Getinv(f[i-1], m) % m) * Getinv(f[n-i], m) % m == 0) ans.pb(i);
	}
	cout << ans.size() << endl;f0(i, ans.size()) cout << ans[i] << ' ';
	 
}

signed main() {
  ios::sync_with_stdio(false),cin.tie(NULL);
  freopen("random.in", "r", stdin);
  freopen("random.out", "w", stdout);
  int T = 1;
  //cin >> T;
  while(T--) {
  	work();
  }
  return 0;
}

