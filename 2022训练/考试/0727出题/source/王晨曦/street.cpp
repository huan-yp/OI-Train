#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;

const double eps = 1e-8;
const int N = 1e5 + 5;

int a[N];
int n;
int sz[N];
struct Edge { int to, nxt; } edge[N << 1];
int head[N];
void add_edge(int u, int v) { static int k = 1; edge[k] = (Edge){v, head[u]}, head[u] = k++; }

void get_sz(int u, int fa) {
	for(int i = head[u]; i; i = edge[i].nxt) if(edge[i].to != fa) {
		int v = edge[i].to;
		get_sz(v, u);
		sz[u] += sz[v];
	}
	if(!sz[u]) sz[u] = 1;
}

double f[N];
void dfs(int u, int fa, int total) {
	int o = total;
	if(a[u]) total = sz[u];
	std::vector<int> vct;
	for(int i = head[u]; i; i = edge[i].nxt) if(edge[i].to != fa) {
		int v = edge[i].to;
		dfs(v, u, total);
		vct.push_back(v);
	}
	if(vct.empty()) return;
	std::sort(vct.begin(), vct.end(), [&](int x, int y) { return sz[x] * (f[y] + 2) > sz[y] * (f[x] + 2); });
	int sum = 0;
	for(int v : vct) f[u] += (total - sum) * (f[v] + 2), sum += sz[v];
	f[u] /= (double)total;
	f[u] -= 1;
	f[u] *= (double)total / o;
}

int main() {
#ifndef _DEBUG
	freopen("street.in", "r", stdin);
	freopen("street.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) { int x; char c[2]; scanf("%d%s", &x, c); add_edge(x, i), add_edge(i, x); a[i] = (c[0] == 'Y'); }
	get_sz(1, 0);
	dfs(1, 0, sz[1]);
	// for(int i = 1; i <= n; i++) printf("f[%d] = %.9lf\n", i, f[i]);
	printf("%.7f\n", f[1]);
	return 0;
} /*
10
1 Y
1 N
2 N
2 N
2 N
3 N
3 Y
8 N
8 N
*/