#include<bits/stdc++.h>
#define debug(...) std::cerr<<#__VA_ARGS__<<" : "<<__VA_ARGS__<<std::endl

using ll=long long;

const int maxn=100005;
int n;
bool c[maxn];
std::vector<int> G[maxn];
double f[maxn];
ll g[maxn],w[maxn];

bool cmp(std::pair<ll,ll> p1,std::pair<ll,ll> p2) {
	return p1.first*p2.second>p2.first*p1.second;
}

void dfs(int pos,int fa) {
	std::vector<int> son;
	for(auto nxt : G[pos]) {
		if(nxt==fa) continue;
		dfs(nxt,pos);
		son.push_back(nxt);
		g[pos]+=g[nxt]+2;
		w[pos]+=w[nxt];
	}
	if(son.empty()) {
		f[pos]=0.0,g[pos]=0,w[pos]=1;
		return;
	}
	if(c[pos]) g[pos]=0;
	f[pos]=0.0;
	std::vector<std::pair<ll,ll>> a;
	for(auto nxt : son) {
		f[pos]+=(double)w[nxt]/(double)w[pos]*double(f[nxt]+1);
		a.push_back({g[nxt]+2,w[nxt]});
	}
	std::sort(a.begin(),a.end(),cmp);
	ll cur=0;
	for(auto par : a) {
		double prob=(double)cur/(double)w[pos];
		f[pos]+=prob*(double)par.first;
		cur+=par.second;
	}
}

int main() {
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		int x; char ch;
		scanf("%d%c%c",&x,&ch,&ch);
		c[i]=(ch=='Y');
		G[x].push_back(i);
		G[i].push_back(x);
	}
	dfs(1,0);
	printf("%.14lf\n",f[1]);
	return 0;
}
