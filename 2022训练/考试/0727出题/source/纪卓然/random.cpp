#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int cnt[N + 5][20];
vector<pair<int, int> > v;
vector<int> ans;
int main() {
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 2; i * i <= m; i++) {
		if(m % i == 0) {
			v.push_back({i, 0});
			while(m % i == 0) {
				m /= i;
				v[(int)v.size() - 1].second++;
			}
		}
	}
	if(m > 1) v.push_back({m, 1});
	for(int i = 1; i < n; i++) {
		int x = i;
		for(int j = 0; j < (int)v.size(); j++) {
			cnt[i][j] = cnt[i - 1][j];
			while(x % v[j].first == 0) {
				x /= v[j].first;
				cnt[i][j]++;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < (int)v.size(); j++) {
			if(cnt[n - 1][j] - cnt[n - 1 - i][j] - cnt[i][j] < v[j].second) goto nxt;
		}
		ans.push_back(i);
		nxt:;
	}
	printf("%d\n", (int)ans.size());
	for(auto it : ans) {
		printf("%d\n", it + 1);
	}
	return 0;
}
