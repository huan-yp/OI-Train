#include<bits/stdc++.h>
using namespace std;

int n , dfs[200010], bfs[200010], tre[200010], v[200010];
int main() {
	freopen ("tree.in","r",stdin);
	freopen ("tree.out","w",stdout);
	cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> dfs[i];
        tre[dfs[i]]=i;
    }
    for(int i = 1; i <= n ; i++) {
        cin >> bfs[i];
        dfs[tre[bfs[i]]]=i;
        bfs[i]=i;
    }
    for(int i = 1; i <= n ; i++) {
        tre[dfs[i]] = i;
    }
    double ans = 2.0;
    int l = 2, r = n + 1;
    v[1] = v[2] = 1;
    for(int i = 3; i <= n ; i++) {
        if(tre[i - 1] > tre[i]) {
            ans += 1;
        } else if(tre[i - 1] + 1 == tre[i] && l + n + 1 - r == i - 1) {
            ans += 0.5;
        }
        v[tre[i]] = 1;
        while(l < r && v[l + 1]) {
            l++;
        }
        while(l < r && v[r - 1]) {
            r--;
        }
    }
    printf("%.6f\n", ans);
    return 0;
}
