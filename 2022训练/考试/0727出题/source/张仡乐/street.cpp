#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int N=1e5+5;
int n,a[N];
ld f[N],g[N],sum[N];
vector<int>v[N];
bool cmp(int x,int y){return (g[x]+2)/sum[x]<(g[y]+2)/sum[y];}
void dfs(int x)
{
	for(int i=0;i<v[x].size();i++)
		dfs(v[x][i]),sum[x]+=sum[v[x][i]];
}
void solve(int x)
{
	for(int i=0;i<v[x].size();i++)
		solve(v[x][i]),g[x]+=g[v[x][i]]+2;
	if(a[x])g[x]=0;
	sort(v[x].begin(),v[x].end(),cmp);
	ld las=0;
	for(int i=0;i<v[x].size();i++)
		f[x]+=(f[v[x][i]]+las+1)*sum[v[x][i]]/sum[x],las+=g[v[x][i]]+2;
}
signed main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		sum[i]=1;
	for(int i=2,x;i<=n;i++)
	{
		char c;
		scanf("%d",&x),cin>>c;
		sum[x]=0,v[x].push_back(i);
		a[i]=(c=='Y');
	}
	dfs(1);
	solve(1);
	printf("%.7Lf",f[1]);
}

