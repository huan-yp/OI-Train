/* Code by Reflective-FG */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forr(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, n) forr(i, 0, n-1)
#define repp(i, n) forr(i, 1, n)
#define pb push_back
#define mp make_pair
#define init(a, i) memset(a, i, sizeof(a))
#define fi first
#define se second
#define MAXN 0x3f3f3f3f
const int N = 100005;
int T_, case_;
int n, fa[N];
bool in[N], imp[N];
char c;
vector<int>g[N];
int dp1[N], siz[N];
double dp2[N];
void dfs1(int x) {
    dp1[x] = 0;
    for (int y : g[x]) {
        dfs1(y);
        dp1[x] += dp1[y] + 1;
        siz[x] += siz[y];
    }
    if (imp[x])dp1[x] = 0;
    if (g[x].empty())siz[x] = 1;
}
bool cmp(int x, int y) {
    double val1, val2;
    val1 = (1 - (double)siz[x] * 1.0 / n) * (2 + dp1[x]);
    val2 = (1 - (double)siz[y] * 1.0 / n) * (2 + dp1[y]);
    return val1 < val2;
}
void dfs2(int x) {
    vector<int>son;
    for (int y : g[x]) {
        dfs2(y);
        son.pb(y);
    }
    sort(son.begin(), son.end(), cmp);
    double p = 1;
    for (int y : son) {
        dp2[x] += (double)siz[y] * 1.0 / siz[x] * (dp2[y] + 1);
        p -= (double)siz[y] * 1.0 / siz[x];
        dp2[x] += p * (dp1[y] + 2);
    }
}
void solve() {
    cin >> n;
    repp(i, n - 1) {
        cin >> fa[i] >> c;
        fa[i]--;
        g[fa[i]].pb(i);
        if (c == 'Y')imp[i] = 1;
        in[fa[i]] = 1;
    }
    rep(i, n)if (!in[i])imp[i] = 1;
    dfs1(0);
    dfs2(0);
    cout << fixed << setprecision(10) << dp2[0];
}
int main() {
    freopen("street.in", "r", stdin);
    freopen("street.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    T_ = 1;

    for (case_ = 1; case_ <= T_; case_++)solve();
    return 0;
}