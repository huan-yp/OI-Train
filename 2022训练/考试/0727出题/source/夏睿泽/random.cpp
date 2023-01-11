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
const int N = 1e5 + 10;

// bool st;
int n, m;
int fac[N];
vector<int> res;
// bool en;

void getFac()
{
    fac[0] = 1;
    for (int i = 1; i <= 100000ll; i++)
    {
        fac[i] = fac[i - 1] * i % m;
    }
}

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int res = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

int inv(int a)
{
    int x, y;
    int d = exgcd(a, m, x, y);
    return d == 1 ? (x % m + m) % m : -1;
}

int getc(int x, int y)
{
    return fac[x] * inv(x - y) % m * inv(y) % m;
}

signed main()
{
    freopen("random.in", "r", stdin);
    freopen("random.out", "w", stdout);
    // cerr<<(&en-&st)/1024.0/1024.0<<endl;
    // auto t_1=chrono::high_resolution_clock::now();
    cin >> n >> m;
    getFac();
    if (m == 1)
        res.pb(1);
    for (int i = 2; i < n; i++)
    {
        if (getc(n - 1, i - 1) % m == 0)
            res.pb(i);
    }
    if (m == 1)
        res.pb(n);
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << ' ';
    // auto t_2=chrono::high_resolution_clock::now();
    // cout <<". Elapsed (ms): " << chrono::duration_cast<chrono::milliseconds>(t_2 - t_1).count() << endl;
    return 0;
}
