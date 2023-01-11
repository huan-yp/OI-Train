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
int T_, case_;
int n, m;
map<int, int>cnt;
vector<int>ans;
void add(int x, int val) {
    for (int y = 2;y * y <= x;y++) {
        while (x % y == 0) {
            cnt[y] += val;
            x /= y;
        }
    }
    if (x != 1)cnt[x] += val;
}
bool check() {
    int M = m;
    for (int i = 2;i * i <= M;i++) {
        int tmp = 0;
        while (M % i == 0) {
            tmp++;
            M /= i;
        }
        if (cnt[i] < tmp)return 0;
    }
    if (M != 1 && cnt[M] < 1)return 0;
    return 1;
}
void solve() {
    cin >> n >> m;
    repp(i, n) {
        if (i != 1) {
            add(n - i + 1, 1);
            add(i - 1, -1);
        }
        if (check())ans.pb(i);
    }
    if (ans.empty()) {
        cout << 0;
        return;
    }
    cout << ans.size() << endl;
    rep(i, ans.size())cout << ans[i] << endl;
}
int main() {
    freopen("random.in", "r", stdin);
    freopen("random.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    T_ = 1;

    for (case_ = 1; case_ <= T_; case_++)solve();
    return 0;
}