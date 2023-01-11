#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
int n,m,s,l,siz[200005];
char t;
bool a[200005];
double f[200005],g[200005];
vector<int>e[200005];
bool cmp(int x,int y){
	return (g[x]+2)*siz[y]<(g[y]+2)*siz[x];
}
double dfs(int x){
//	cout<<x<<endl;
	if(!e[x].size())return siz[x]=1,0;
	for(int i=0;i<e[x].size();i++){
		dfs(e[x][i]);
		siz[x]+=siz[e[x][i]];
	}
	sort(e[x].begin(),e[x].end(),cmp);
	for(int i=0;i<e[x].size();i++){
		f[x]+=(g[x]+f[e[x][i]]+1)*siz[e[x][i]]/siz[x];
		g[x]+=g[e[x][i]]+2;
	}
	if(a[x]) g[x]=0;
	return f[x];
}
signed main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	cin>>n;
	for(int i=2,j;i<=n;i++){
		scanf("%lld\n%c",&j,&t);
		e[j].push_back(i);
		if(t=='Y') a[i]=true;
	}
	printf("%.10Lf\n",dfs(1));
	return 0;
}
