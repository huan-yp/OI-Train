# include <bits/stdc++.h>
//# include <windows.h>
using namespace std;

# define ll long long
# define lf double
# define GO(i,a,b) for(ll i = a; i <= b; i ++)
# define RO(i,b,a) for(ll i = b; i >= a; i --)
# define FO(i,u,head,e) for(int i = head[u]; i; i = e[i].next)
# define CI const int
# define pii pair<int,int>
# define MP(a,b) make_pair(a, b)
# define PB(x) push_back(x)
# define mem(a,x) memset(a, x, sizeof a)
# define F first
# define S second
# define Debug {printf("\033[31m=============================Debug======================\n");}
# define QwQ printf("~~~~~~~~~~~~~~~QwQ~~~~~~~~~~~~~~~~~~\n\n\033[0m")

CI maxn = 2e5 + 7;

ll n, mod;

ll p[maxn][66];
ll a[maxn][66];
ll tot[maxn];

void getMax(ll k, ll x){
	ll tmp = x;
	GO (i, 2, (ll) sqrt(x)){
		if (x % i)
			continue;
		tot[k] ++;
		while (x % i == 0){
			x /= i;
			a[k][tot[k]] ++;
		}
		p[k][tot[k]] = i;
		if (x - 1)
			break;
	}
	if (x > 1){
		tot[k] ++;
		a[k][tot[k]] = 1;
		p[k][tot[k]] = x;
	}
}

ll getNum(ll x, ll y){
	ll res = 0;
	while (x){
		res += x / y;
		x /= y; 
	}
	return res;
}

bool C(ll x, ll y){
	ll upG = 2e18;
	GO (i, 1, tot[0]){
		upG = min <ll> (getNum(x, p[0][i]) / a[0][i], upG);
	}
	ll downG = 2e18;
	map <ll, ll> mp;
	GO (i, 1, tot[0]) mp[p[0][i]] += getNum(y, p[0][i]) / a[0][i];
	GO (i, 1, tot[0]) mp[p[0][i]] += getNum(x - y, p[0][i]) / a[0][i];
	for (pair <ll, ll> i : mp)
		downG = min <ll> (i.S, downG);
	return upG > downG;
}

int main(){
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
	cin >> n >> mod;
	getMax(0, mod);
	vector <ll> ans;
	GO (i, 1, n){
		if (C(n - 1, i - 1)){
			ans.PB(i);
		}
	} 
	printf("%d\n", (int) ans.size());
	for (ll i : ans)
		printf("%lld\n", i);
	return 0;
}
