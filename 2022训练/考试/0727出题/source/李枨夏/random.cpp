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

const int maxn = 1e5 + 10;
int n, m, cnt[maxn], ans[maxn];
void test(int p, int c) {
    for (int i = 1; i < n; ++i) {
        cnt[i] = cnt[i - 1];
        for (int t = i; t % p == 0; t /= p) ++cnt[i];
    }
    for (int i = 0; i < n; ++i)
        ans[i] &= (cnt[n - 1] - cnt[i] - cnt[n - 1 - i] >= c);
}

int main() {
	freopen("random.in", "r", stdin), freopen("random.out", "w", stdout);
    read(n, m);
    fill(ans, ans + n, 1);
    for (int i = 2; (ll) i * i <= m; ++i)
        if (m % i == 0) {
            int c = 0;
            while (m % i == 0) m /= i, c++;
            test(i, c);
        }
    if (m > 1) test(m, 1);
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += ans[i];
    write(sum, '\n');
    for (int i = 0; i < n; ++i)
        if (ans[i]) write(i + 1, ' ');
	;
    return 0;
}
// sto cjx orz
