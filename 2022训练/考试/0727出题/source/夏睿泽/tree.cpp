/*
    Name:
    Author: xiaruize
    Date:
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define ALL(a) (a).begin(), (a).end()
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define pis pair<int, string>
#define sec second
#define fir first
#define sz(a) int((a).size())
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define repp(i, x, y) for (int i = x; i >= y; i--)
#define Yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define No cout << "No" << endl
#define NO cout << "NO" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define double long double
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const int N = 2e5 + 10;

// bool st;
int n;
int a[N], b[N];
int posa[N], posb[N];
int ab[N], ba[N];
int s[N];
// bool en;

signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    // cerr<<(&en-&st)/1024.0/1024.0<<endl;
    // auto t_1=chrono::high_resolution_clock::now();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        posa[a[i]] = i;
        posb[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        ab[i] = posb[a[i]];
        ba[i] = posa[b[i]];
    }
    double res = 2;
    s[1]++;
    s[2]--;
    for (int i = 1; i < n; i++)
    {
        if (ba[i] > ba[i + 1])
        {
            s[i]++;
            s[i + 1]--;
            res++;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (ab[i] + 1 < ab[i + 1])
        {
            s[ab[i]]++;
            s[ab[i + 1]]--;
        }
    }
    int now = 0;
    for (int i = 1; i < n; i++)
    {
        now += s[i];
        if (!now)
            res += 0.5;
    }
    cout << fixed << setprecision(7) << res << endl;
    // auto t_2=chrono::high_resolution_clock::now();
    // cout <<". Elapsed (ms): " << chrono::duration_cast<chrono::milliseconds>(t_2 - t_1).count() << endl;
    return 0;
}
