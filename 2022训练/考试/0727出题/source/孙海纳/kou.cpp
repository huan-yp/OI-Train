#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define STR string
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
int n;
int a[100010];
ll res=0;
vector<int> v[100010];
int cnt[100010][2];
void dfs(int x,int par)
{
	cnt[x][a[x]]++;
	for (int i=0;i<v[x].size();i++)
	{
		int xi=v[x][i];
		if (xi==par) continue;
		dfs(xi,x),cnt[x][0]+=cnt[xi][0],cnt[x][1]+=cnt[xi][1];
	}
	int t=min(cnt[x][0],cnt[x][1]);
	cnt[x][0]-=t,cnt[x][1]-=t;
	res+=cnt[x][0]+cnt[x][1];
}
int main()
{
	freopen("kou.in","r",stdin);
	freopen("kou.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]),a[i]%=2;
	for (int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),x--,y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(0,-1);
	printf("%lld",res);
	return 0;
}
