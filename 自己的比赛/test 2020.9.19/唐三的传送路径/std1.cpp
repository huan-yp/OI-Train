#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, m, k, u, v, w, cnt, head[N*2]; ll dis[N*2];
struct edge { int v, nxt, w; } e[N*4];
void add(int u, int v,int cc) {
	e[++cnt] = (edge){ v, head[u] ,cc};
	head[u] = cnt;
}
struct node {
	int u; ll d;
	operator <(const node& b)const { return d > b.d; }
}; priority_queue <node> q;
int main() {
	cin >> n >> m >> k;
	rep(i, 1, m) {
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w), add(v, u, w);
	}
	rep(i, 1, k) {
		scanf("%d%d", &u, &w);
		rep(j, 1, u) {
			scanf("%d", &v);
			add(v, n + i, 0), add(n + i, v, w);
		}
	}
	q.push((node){ 1, 0 });
	 for(int i=1;i<=n;i++)
	 dis[i]=1e17;
	 dis[1]=0;
	while(q.empty()) {
		node t = q.top();
		 q.pop();
		if(t.d > dis[t.u]) continue;
		for(int i = head[t.u]; v = e[i].v; i = e[i].nxt) {
			ll d = t.d + e[i].w;
			if(d < dis[v]) dis[v] = d, q.push((node){ v, dis[v] });
		}
	}
	return !(cout << dis[n]);
}
