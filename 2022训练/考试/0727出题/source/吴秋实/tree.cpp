/* Éú¤±¤ëÊÀ¤Ë¡¢Îá¤¬¤ß¤«¤Ê¤·¤â¡¢
   ‰ô¤ÏÏû¤Ì¡¢Ô¹¤ß¤ÆÉ¢¤ë¡£ */

#include <bits/stdc++.h>
using namespace std;

#define inl inline
constexpr int BUF = 1<<20;
char ibuf[BUF], *__st, *__ed;
inl void buffer () { __st = ibuf,
	__ed = fread (ibuf, 1, BUF, stdin) + ibuf; }
inl char getc () {
	return __st == __ed && (buffer (),
		__st == __ed) ? EOF : *__st++; }
struct IO {
	IO () { __st = __ed = ibuf; }
} __io;

template <typename T>
inl bool read (T &x) {
	x = 0; int f = 1; char c = getc ();
	for (; ~c && !isdigit (c); c = getc ())
		if (c == '-') f = -1;
	if (c == EOF) return 0;
	for (; ~c && isdigit (c); c = getc ())
		x = (x<<1) + (x<<3) + (c^48);
	return x *= f, 1; 
}
template <typename T, typename...Targs>
inl bool read (T &x, Targs&...args) {
	return read (x) && read (args...); }
inl int read (char *s) {
	char c = getc (); int len = 0;
	while (~c && isspace (c)) c = getc ();
	if (c == EOF) return 0;
	for (; ~c && !isspace (c); c = getc ())
		*s++ = c, ++len; return *s = 0, len;
}
#define scanf(...) fprintf (stderr, "use fread!!")

#define all(p) (p).begin (), (p).end ()
typedef long long ll;
//typedef unsigned long long ull;
//typedef __int128 lll;
//typedef long double llf;
typedef pair <int, int> pint;
typedef pair <ll, ll> pll;
#define fst first
#define scd second

constexpr int N = 2e5 + 10;
int n, d[N], b[N], bpos[N], mxp, unce, cert;

struct BIT {
	int c[N];
	#define lowbit(x) ((x) & -(x))
	inl void add (int x) {
		for (; x <= n; x += lowbit (x)) ++c[x]; }
	inl int ask (int x) {
		int res = 0;
		for (; x > 0; x -= lowbit (x)) res += c[x];
		return res;
	}
} bit;

int main () {
	/* ¼Ù£¡ */
	freopen ("tree.in", "r", stdin);
	freopen ("tree.out", "w", stdout);

	read (n);
	for (int i = 1; i <= n; ++i)
		read (d[i]);
	for (int i = 1; i <= n; ++i)
		read (b[i]), bpos[b[i]] = i;
	int pos; cert = 1; bit.add (1);
	for (int i = 2; i <= n; ++i) {
		if ((pos = bpos[d[i]]) > mxp) {
			if (mxp == pos - 1)
				unce += mxp > 1 && bit.ask (mxp) == i - 1
					&& d[i-1] == b[mxp];
			else ++cert;
			mxp = pos;
		}
		bit.add (pos);
	}
	printf ("%.8lf", 0.5 * unce + cert);

	return 0;
}

