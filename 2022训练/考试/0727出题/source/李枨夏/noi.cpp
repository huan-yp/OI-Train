#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 160, maxm = 510, inf = 1e9;
int n, m, a[maxn][maxm], s[maxn], f[2][11][maxn][maxn], b[maxn][maxn];
void trans(int i1, int i) {
    auto S = [&] (int l, int r) {
        if (l > r) return 0;
        return s[r] - s[l - 1];
    };
    memset(f[i], 0xaf, sizeof f[i]);

    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            f[i][0][l][r] = max(f[i1][1][l][r], 0) + S(l, r);
    // / -> 0 && 0 -> 0

    memset(b, 0xaf, sizeof b);
    for (int l = 1; l <= n; ++l) {
        int mx = -inf;
        for (int r = n; r >= l; --r)
            f[i][1][l][r] = max(f[i][1][l][r], mx + S(l, r)),
            mx = max(mx, f[i1][0][l][r]);
    }
    // 0 -> 1

    memset(b, 0xaf, sizeof b);
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            b[l][r] = max(b[l - 1][r], f[i1][1][l][r]);
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            b[l][r] = max(b[l][r], b[l][r - 1]);
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            f[i][1][l][r] = max(f[i][1][l][r], b[l][r] + S(l, r));
    // l <= b <= r
    for (int l = 1; l <= n; ++l) {
        int mx = -inf;
        for (int a = 1; a <= l - 1; ++a) mx = max(mx, f[i1][1][a][l - 1]);
        for (int r = l; r <= n; ++r)
            f[i][1][l][r] = max(f[i][1][l][r], mx + S(l, r));
    }
    // b == l - 1
    // 1 -> 1

    for (int r = 1; r <= n; ++r) {
        int mx = -inf;
        for (int l = r; l >= 1; --l)
            f[i][2][l][r] = max(f[i][2][l][r], mx + S(l, r)),
            mx = max(mx, f[i1][1][l][r]);
    }
    // 1 -> 2

    for (int l = 1; l <= n; ++l)
        for (int r = 1; r <= n; ++r)
            f[i][2][l][r] = max(f[i][2][l][r], f[i1][2][l][r] + S(l, r));
    // 2 -> 2

    f[i][3][0][0] = f[i1][3][0][0];
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            f[i][3][0][0] = max(f[i][3][0][0], f[i1][2][l][r]);
    // 2 -> 3 && 3 -> 3

    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r)
            f[i][4][l][r] = f[i1][3][0][0] + S(l, r);
    // 3 -> 4

    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r)
            f[i][5][l][r] = max(f[i1][4][l][r], f[i1][5][l][r]) + S(l, l) + S(r, r);
    // 4 -> 5 && 5 -> 5

    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r)
            f[i][6][l][r] = f[i1][5][l][r] + S(l, r);
    // 5 -> 6

    f[i][7][0][0] = f[i1][7][0][0];
    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r)
            f[i][7][0][0] = max(f[i][7][0][0], f[i1][6][l][r]);
    // 6 -> 7 && 7 -> 7

    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r)
            f[i][8][l][r] = max(f[i1][7][0][0], f[i1][8][l][r]) + S(l, l) + S(r, r);
    // 7 -> 8 && 8 -> 8

    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r)
            f[i][9][l][r] = max(f[i1][8][l][r], f[i1][9][l][r]) + S(l, r);
    // 8 -> 9 && 9 -> 9

    for (int l = 1; l <= n; ++l)
        for (int r = l + 2; r <= n; ++r)
            f[i][10][l][r] = max(f[i1][9][l][r], f[i1][10][l][r]) + S(l, l) + S(r, r);
    // 9 -> 10 && 10 -> 10
}

int get(int i) {
    int res = -inf;
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            res = max(res, f[i][10][l][r]);
    return res;
}

int main() {
	freopen("noi.in", "r", stdin), freopen("noi.out", "w", stdout);
    read(n, m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            read(a[i][j]);

    memset(f, 0xaf, sizeof f);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i][1];
    for (int l = 1; l <= n; ++l)
        for (int r = l; r <= n; ++r)
            f[1][0][l][r] = s[r] - s[l - 1];
    int ans = get(1);
    for (int j = 2; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i][j];
        trans((j ^ 1) & 1, j & 1);
        ans = max(ans, get(j & 1));
    }
    write(ans, '\n');
	return 0;
}
// sto cjx orz
