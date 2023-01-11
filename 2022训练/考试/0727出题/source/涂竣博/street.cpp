#include<bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,j,s) for(register int i=j;i<=s;++i)
#define g(i,j,s) for(register int i=j;i>=s;--i)
int n,m,s,l;
char opt[3];
int a[202020];
int siz[202020];
double f[202020];
double g[202020];
vector<int>q[202020];
inline bool cmp(int x,int y){return (g[x]+2)*siz[y]<(g[y]+2)*siz[x];}
inline double dfs(int x){
	if(!q[x].size())return siz[x]=1,0;
	int y;
	f(i,1,q[x].size()){
		y=q[x][i-1];
		dfs(y);
		siz[x]+=siz[y];
	}
	sort(q[x].begin(),q[x].end(),cmp);
	f(i,1,q[x].size()){
		y=q[x][i-1];
		f[x]+=(g[x]+f[y]+1)*siz[y]/siz[x];
		g[x]+=g[y]+2;
	}
	if(a[x])g[x]=0;
	return f[x];
}
signed main(){
    freopen("street.in","r",stdin);
    freopen("street.out","w",stdout);
	cin>>n;
	f(i,2,n){
		scanf("%lld %s",&s,opt);
		q[s].push_back(i);
		a[i]=(opt[0]=='Y');
	}
	return printf("%lf\n",dfs(1)),0;
}
/*
CompileRun 涂竣博\street.cpp
5
1 N
1 Y
3 N
3 N
CompileRun 涂竣博\street.cpp
10
1 Y
1 N
2 N
2 N
2 N
3 N
3 Y
8 N
8 N

*/