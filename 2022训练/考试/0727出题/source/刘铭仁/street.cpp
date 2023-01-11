#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
vector<int>g[100005];
long long s[100005];
long long l[100005];
long long c[100005];
bool cmp(int i,int j) {
	return (l[j]+2)*s[i]>(l[i]+2)*s[j];
}
void dfs(int u) {
	if(g[u].size()==0)s[u]=1;
	for(int v:g[u]) {
		dfs(v);
		s[u]+=s[v];
		l[u]+=l[v]+2;
	}
	sort(g[u].begin(),g[u].end(),cmp);
	long long sum=1;
	for(int v:g[u]) {
		c[u]+=c[v]+sum*s[v];
		sum+=l[v]+2;
	}
	if(a[u])l[u]=0;
}
int main() {
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	scanf("%d",&n);
	for(int i=2; i<=n; i++) {
		int fa;
		char ch;
		scanf("\n%d %c",&fa,&ch);
		g[fa].push_back(i);
		a[i]=(ch=='Y');
	}
	dfs(1);
	printf("%.10lf",(double)c[1]/s[1]);
	return 0;
}
