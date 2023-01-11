#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n = 0, m = 0, k = 0, a[N] = {};
int s = 0, ans[N] = {};

inline void Add(int x){
	for(int i = 2 ; i * i <= x ; i ++) while(!(x % i)){
		x /= i;
		a[i] ++;
		if(!a[i]) k ++;
	}
	if(x > 1){
		a[x] ++;
		if(!a[x]) k ++;
	}
}

inline void Del(int x){
	for(int i = 2 ; i * i <= x ; i ++) while(!(x % i)){
		x /= i;
		if(!a[i]) k --;
		a[i] --;
	}
	if(x > 1){
		if(x > n) k --;
		else{
			if(!a[x]) k --;
			a[x] --;
		} 
	}
}

int main(){
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
	scanf("%d %d", &n, &m);
	Del(m);
	if(k >= 0) ans[s ++] = 1;
	for(int i = 1 ; i < n ; i ++){
		Add(n - i); Del(i);
		if(k >= 0) ans[s ++] = i + 1;
	}
	printf("%d\n", s);
	for(int i = 0 ; i < s ; i ++) printf("%d\n", ans[i]);
	return 0;
}

