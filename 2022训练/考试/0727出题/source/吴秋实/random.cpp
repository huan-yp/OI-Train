/* Éú¤±¤ëÊÀ¤Ë¡¢Îá¤¬¤ß¤«¤Ê¤·¤â¡¢
   ‰ô¤ÏÏû¤Ì¡¢Ô¹¤ß¤ÆÉ¢¤ë¡£ */

#include <bits/stdc++.h>
using namespace std;

#define inl inline
constexpr int BUF = 1<<20;
char obuf[BUF], ibuf[BUF], *__pt, *__st, *__ed;
inl void buffer () { __st = ibuf,
	__ed = fread (ibuf, 1, BUF, stdin) + ibuf; }
inl void flush () {
	fwrite (obuf, 1, __pt - obuf, stdout);
	__pt = obuf; }
inl char getc () {
	return __st == __ed && (buffer (),
		__st == __ed) ? EOF : *__st++; }
inl void putc (char c) {
	if (__pt == BUF + obuf) flush ();
	*__pt++ = c; }
struct IO {
	IO () { __st = __ed = ibuf, __pt = obuf; }
	~IO () { flush (); }
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
template <typename T>
inl void print (T x) {
	static int st[36], top = 0;
	if (x < 0) putc ('-'), x = -x;
	do { st[++top] = x % 10, x /= 10; } while (x);
	while (top) putc (48^st[top--]);
}
template <typename T, typename...Targs>
inl void print (const T &x, const Targs&...args) {
	print (x), putc (' '), print (args...); }
template <typename C>
inl void print (C *s) { while (*s) putc (*s++); }
#define putchar putc
#define newl putc('\n')
#define puts(s) (print (s), newl)
#define scanf(...) fprintf (stderr, "use fread!!")
#define printf scanf

#define all(p) (p).begin (), (p).end ()
typedef long long ll;
//typedef unsigned long long ull;
//typedef __int128 lll;
//typedef long double llf;
typedef pair <int, int> pint;
typedef pair <ll, ll> pll;
#define fst first
#define scd second

constexpr int N = 1e5 + 10;
int n, m, facc[N][12], fcnt, p[12], c[12];
int ans[N], cnt;

inl void factor (int x) {
	int _x = x;
	for (int y = 2; y * y <= x; ++y) {
		if (_x % y) continue;
		p[++fcnt] = y;
		while (_x % y == 0)
			++c[fcnt], _x /= y;
	}
	if (_x > 1) p[++fcnt] = _x, c[fcnt] = 1;
}

inl bool check (int n, int m) {
	// n!/(m!(n-m)!)
	for (int i = 1; i <= fcnt; ++i)
		if (facc[n][i] - facc[m][i] - facc[n - m][i] < c[i])
			return 0;
	return 1;
}

int main () {
	/*  */
	freopen ("random.in", "r", stdin);
	freopen ("random.out", "w", stdout);
	
	read (n, m); factor (m);
	for (int x = 1; x <= n; ++x) {
		memcpy (facc[x], facc[x-1], 12<<2);
		int _x = x;
		for (int i = 1; i <= fcnt; ++i)
			while (_x % p[i] == 0)
				++facc[x][i], _x /= p[i];
	}
	for (int k = 1; k <= n; ++k)
		if (check (n - 1, k - 1))
			ans[++cnt] = k;
	print (cnt), newl;
	for (int i = 1; i <= cnt; ++i)
		print (ans[i]), putchar (' ');

	return 0;
}

