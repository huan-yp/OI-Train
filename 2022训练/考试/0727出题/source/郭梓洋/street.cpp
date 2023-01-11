#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<functional>
#include<map>
#include<queue>
#include<bitset>
#include<cmath>
#include<unordered_map>
#include<array>
#include<iomanip>
#include<numeric>
using namespace std;
template<typename T>
inline bool cmax(T& a,const T& b){return a<b?a=b,1:0;}
template<typename T>
inline bool cmin(T& a,const T& b){return b<a?a=b,1:0;}
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
#define X first
#define Y second
const int mod=998244353;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=1e5+10;
vi e[MAXN];
int is[MAXN];
int siz[MAXN];
int lev[MAXN];
double F[MAXN][2];
ll ans;
void dfs(int u)
{
	siz[u]=1;
	if(u!=1&&e[u].empty())lev[u]=1;
	for(const int& v:e[u])dfs(v);
	sort(e[u].begin(),e[u].end(),[&](int x,int y){return is[x]>is[y]||is[x]==is[y]&&siz[x]<siz[y];});
	if(u!=1)ans+=siz[u];
}
int main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;cin>>n;
	int fa;char c;
	for(int i=2;i<=n;i++)cin>>fa>>c,is[i]=(c=='Y'),e[fa].push_back(i);
	dfs(1);
	return 0;
}

