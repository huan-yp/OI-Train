#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 1e5 + 10;
int n, siz[maxn], fa[maxn];
vi son[maxn];
char flg[maxn][2];
db p[maxn], f[maxn], g[maxn];

void dfs(int u) {
    if (son[u].empty()) {
        siz[u] = 1, f[u] = g[u] = 0;
        return;
    }
    for (int v : son[u]) dfs(v), siz[u] += siz[v], f[u] += f[v] + 2;
    if (flg[u][0] == 'Y') f[u] = 0;
    for (int v : son[u]) p[v] = (db) siz[v] / siz[u];
    sort(son[u].begin(), son[u].end(), [&] (int a, int b) {
        return p[b] * (f[a] + 2) <= p[a] * (f[b] + 2);
    });
    db sf = 0;
    for (int i = 0; i < (int) son[u].size(); ++i) {
        int v = son[u][i];
        g[u] += p[v] * (sf + 2 * i + g[v] + 1);
        sf += f[v];
    }
}

int main() {
	freopen("street.in", "r", stdin), freopen("street.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i)
        scanf("%d%s", &fa[i], flg[i]), son[fa[i]].push_back(i);
    dfs(1);
    printf("%.7lf\n", g[1]);
	return 0;
}

// sto cjx orz
