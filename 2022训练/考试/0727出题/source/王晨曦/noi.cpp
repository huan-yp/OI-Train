#include <cstdio>
#include <algorithm>
#include <cstring>

#define CLEAR(arr) memset(arr, ~0x3f, sizeof(arr))

const int N = 150 + 5;
const int M = 500 + 5;
const int INF = 0x3f3f3f3f;

int a[N][M];
int n, m;

int sm[N][M];
int f[M][N][N][3], fg[M], g[M][N][N][3], gh[M], h[M][N][N][3], mx[N][N][N];

inline int sum(int x1, int y1, int x2, int y2) { return sm[x2][y2] - sm[x1 - 1][y2] - sm[x2][y1 - 1] + sm[x1 - 1][y1 - 1]; }
inline int sum(int i, int j, int k) { return sum(j, i, k, i); }

inline void chkmax(int &x, int y) { if(x < y) x = y; }

int main() {
#ifndef _DEBUG
	freopen("noi.in", "r", stdin);
	freopen("noi.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	CLEAR(f), CLEAR(fg), CLEAR(g), CLEAR(gh), CLEAR(h), CLEAR(mx);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) sm[i][j] = sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1] + a[i][j];
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			int mxv = -INF;
			for(int k = n; k >= j; k--) {
				chkmax(f[i][j][k][0], sum(i, j, k));
				chkmax(f[i][j][k][0], f[i - 1][j][k][0] + sum(i, j, k));
				chkmax(f[i][j][k][1], mxv + sum(i, j, k));
				chkmax(mxv, f[i - 1][j][k][0]);
			}
		}
		for(int j = 1; j <= n; j++) for(int k = j; k <= n; k++) for(int t = k - 1; t <= n; t++) mx[j][k][t] = -INF;
		for(int j = 1; j <= n; j++) for(int k = j; k <= n; k++) for(int t = k; t <= n; t++) mx[j][k][t] = std::max(mx[j][k][t - 1], f[i - 1][j][t][1]);
		for(int j = 1; j <= n; j++) for(int k = j; k <= n; k++) for(int l = 1; l <= j; l++) chkmax(f[i][j][k][1], mx[l][j - 1][k] + sum(i, j, k));
		for(int k = 1; k <= n; k++) {
			int mxv = -INF;
			for(int j = k; j >= 1; j--) {
				chkmax(f[i][j][k][2], mxv + sum(i, j, k));
				chkmax(mxv, f[i - 1][j][k][1]);
				chkmax(f[i][j][k][2], f[i - 1][j][k][2] + sum(i, j, k));
			}
		}
	}
	for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) for(int k = j; k <= n; k++) chkmax(fg[i], f[i - 1][j][k][2]);
	for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) for(int k = j + 2; k <= n; k++) {
		chkmax(g[i][j][k][0], fg[i - 1] + sum(i, j, k));
		chkmax(g[i][j][k][1], g[i - 1][j][k][0] + a[j][i] + a[k][i]);
		chkmax(g[i][j][k][1], g[i - 1][j][k][1] + a[j][i] + a[k][i]);
		chkmax(g[i][j][k][2], g[i - 1][j][k][1] + sum(i, j, k));
	}
	for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) for(int k = j + 2; k <= n; k++) chkmax(gh[i], g[i - 1][j][k][2]);
	for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) for(int k = j + 2; k <= n; k++) {
		chkmax(h[i][j][k][0], gh[i - 1] + a[j][i] + a[k][i]);
		chkmax(h[i][j][k][0], h[i - 1][j][k][0] + a[j][i] + a[k][i]);
		chkmax(h[i][j][k][1], h[i - 1][j][k][0] + sum(i, j, k));
		chkmax(h[i][j][k][1], h[i - 1][j][k][1] + sum(i, j, k));
		chkmax(h[i][j][k][2], h[i - 1][j][k][1] + a[j][i] + a[k][i]);
		chkmax(h[i][j][k][2], h[i - 1][j][k][2] + a[j][i] + a[k][i]);
	}
	int ans = -INF;
	for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) for(int k = j; k <= n; k++) chkmax(ans, h[i][j][k][2]);
	// for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) for(int k = j; k <= n; k++)
	// 	if(f[i][j][k][0] > -10000 || f[i][j][k][1] > -10000 || f[i][j][k][2] > -10000)
	// 		printf("f[%d][%d][%d] = %d, %d, %d\n", i, j, k, f[i][j][k][0], f[i][j][k][1], f[i][j][k][2]);
	// for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) for(int k = j; k <= n; k++)
	// 	if(g[i][j][k][0] > -10000 || g[i][j][k][1] > -10000 || g[i][j][k][2] > -10000)
	// 		printf("g[%d][%d][%d] = %d, %d, %d\n", i, j, k, g[i][j][k][0], g[i][j][k][1], g[i][j][k][2]);
	// for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) for(int k = j; k <= n; k++)
	// 	if(h[i][j][k][0] > -10000 || h[i][j][k][1] > -10000 || h[i][j][k][2] > -10000)
	// 		printf("h[%d][%d][%d] = %d, %d, %d\n", i, j, k, h[i][j][k][0], h[i][j][k][1], h[i][j][k][2]);
	printf("%d\n", ans);
	return 0;
} /*
3 13
1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1
*/