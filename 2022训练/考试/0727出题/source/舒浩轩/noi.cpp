# include <bits/stdc++.h>
//# include <windows.h>
using namespace std;

# define ll long long
# define lf double
# define GO(i,a,b) for(int i = a; i <= b; i ++)
# define RO(i,b,a) for(int i = b; i >= a; i --)
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

int main(){
	freopen("noi.in", "r", stdin);
	freopen("noi.out", "w", stdout); 
	ll n, m;
	cin >> n >> m;
	cout << n * m - 5 - min <ll> (n, m) * 2ll; 
	return 0;
}
