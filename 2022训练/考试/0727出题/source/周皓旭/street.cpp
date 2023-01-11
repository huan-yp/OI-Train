#include<bits/stdc++.h>
#define int long long
#define N 200005
#define pb push_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
int n,dep[N],ans,cnt; vector<int>g[N];
void dfs(int x){
	for(int &u:g[x]) dep[u]=dep[x]+1,dfs(u);
	if(!g[x].size()) ans+=dep[x],++cnt;
}
signed main(){
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	cin>>n;
	for(int i=2,u;i<=n;i++){
		char ch=0; cin>>u>>ch;
		g[u].pb(i);
	}dfs(1); printf("%.10lf\n",ans*1.0/cnt);
	return 0;
}
