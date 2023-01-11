#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll N = 1e5 + 5;
ll n = 0, par[N] = {}, op[N] = {}, sz[N] = {}, g[N] = {};
long double dp[N] = {};
char s[10] = {};
vector<vector<ll> > T(N);

inline bool cmp(ll u, ll v){
	return (g[u] + 2) * sz[v] > (g[v] + 2) * sz[u];
}

inline void dfs1(ll u){
	if(!T[u].size()) op[u] = 1, sz[u] = 1;
	g[u] = 0;
	for(ll i = 0 ; i < T[u].size() ; i ++){
		ll v = T[u][i];
		dfs1(v);
		sz[u] += sz[v];
		if(!op[u]) g[u] += g[v] + 2;
	}
}

inline void dfs2(ll u){
	ll s = 0;
	for(ll i = 0 ; i < T[u].size() ; i ++){
		ll v = T[u][i];
		dfs2(v);
		dp[u] += (dp[v] + 1) * sz[v] / sz[u] + 1.0 * (g[v] + 2) * s / sz[u];
		s += sz[v];
	}
}

int main(){
	freopen("street.in", "r", stdin);
	freopen("street.out", "w", stdout);
	scanf("%lld", &n);
	for(ll u = 2 ; u <= n ; u ++){
		scanf("%lld %s", &par[u], s);
		T[par[u]].push_back(u);
		if(s[0] == 'Y') op[u] = 1;
	}
	dfs1(1);
	for(ll u = 1 ; u <= n ; u ++) sort(T[u].begin(), T[u].end(), cmp);
	dfs2(1);
	printf("%.6Lf", dp[1]);
	return 0;
}

