#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long LL;

int n, m;

int f(int x, int y) {
	int ret = 0;
	while(x) ret += x / y, x /= y;
	return ret;
}

LL qpow(LL x, LL y, LL mod) { LL ret = 1; while(true) { if(y & 1) ret = ret * x % mod; if(!(y >>= 1)) return ret; x = x * x % mod; } }
bool miller_rabin(int p) {
	if(p < 3 || p % 2 == 0) return p == 2;
	int a = p - 1, b = 0;
	while(a % 2 == 0) a /= 2, b++;
	for(int i = 1, j; i <= 10; i++) {
		int x = rand() % (p - 2) + 2, v = qpow(x, a, p);
		if(v == 1) continue;
		for(j = 0; j < b; j++) {
			if(v == p - 1) break;
			v = (LL)v * v % p;
		}
		if(j >= b) return false;
	}
	return true;
}

std::vector<std::pair<int, int>> p;
void preprocess() {
	int copy = m;
	for(int i = 1; (LL)i * i <= m; i++) {
		if(m % i == 0 && miller_rabin(i)) {
			int t = 0;
			while(copy % i == 0) copy /= i, t++;
			p.push_back({i, t});
		}
		if(m % i == 0 && i != m / i && miller_rabin(m / i)) {
			int t = 0;
			while(copy % (m / i) == 0) copy /= m / i, t++;
			p.push_back({m / i, t});
		}
	}
	// printf("p: ");
	// for(auto i : p) printf("%d * %d, ", i.first, i.second);
	// puts("");
}

std::vector<int> ans;

int main() {
#ifndef _DEBUG
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	preprocess();
	n--;
	for(int i = 0; i <= n; i++) {
		bool flag = true;
		for(auto j : p) flag &= (f(n, j.first) - f(i, j.first) - f(n - i, j.first) >= j.second);
		if(flag) ans.push_back(i + 1);
	}
	printf("%d\n", (int)ans.size());
	for(auto i : ans) printf("%d ", i);
	puts("");
	return 0;
} /*
1 2 3 4 5
1+2 2+3 3+4 4+5
1+2*2+3 2+2*3+4 3+2*4+5
1+3*2+3*3+4 2+3*3+3*4+5
1+4*2+6*3+4*4+5
*/