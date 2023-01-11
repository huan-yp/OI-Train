#include<bits/stdc++.h>
using namespace std;
int n,op[200010],dp2[201000],sz[201000];
vector<int>g[201000];
double dp[201000];
char c[2];
struct qq{
	int a,b;
}p[200100];
bool cmp(qq x,qq y){return 1ll*x.b*y.a<1ll*x.a*y.b;}
void dfs(int x){
	if(g[x].empty()){sz[x]=1;return;}
	sz[x]=dp2[x]=0;
	for(int v:g[x]){
		dfs(v),sz[x]+=sz[v];
		dp2[x]+=dp2[v]+2;
	}
	if(op[x])dp2[x]=0;
	for(int v:g[x])dp[x]+=(dp[v]+1)*sz[v];
	//发现排序的过程可以压在整数里
	int c=0;
	for(int v:g[x])p[++c]=(qq){sz[v],dp2[v]+2};
	sort(p+1,p+c+1,cmp);int ns=0;
	for(int i=1;i<=c;i++)dp[x]+=1ll*p[i].a*ns,ns+=p[i].b;
	dp[x]/=sz[x];
}
int main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	scanf("%d",&n);
	for(int i=2,f;i<=n;i++){
		scanf("%d%s",&f,c);
		op[i]=(c[0]=='Y');
		g[f].push_back(i);
	}
	dfs(1);
	return printf("%.7lf",dp[1]),0;
}
/*
10
1 Y 1 N 2 N 2 N 2 N 3 N 3 Y 8 N 8 N
*/
