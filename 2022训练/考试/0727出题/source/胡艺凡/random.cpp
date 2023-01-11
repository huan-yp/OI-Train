#include <iostream>
#include <cstdio>
using namespace std;
int n, m, t[100010], cnt, p[100010];

int f(int x) {
	int res = 0;
	while(x%m == 0) {
		++res;
		x /= m;
	}
	return res;
}

int main() {
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		int cnt = 0;
		t[i] = t[i-1]+f(i);
	}
	for(int i = 1; i <= n; ++i) {
		if(t[n-1] != t[i-1]+t[n-i]) {
			++cnt;
			p[i] = 1;
		}
	}
	printf("%d\n", cnt);
	for(int i = 1; i <= n; ++i) {
		if(p[i]) {
			printf("%d ", i);
		}
	}
	putchar('\n');
	return 0;
}

