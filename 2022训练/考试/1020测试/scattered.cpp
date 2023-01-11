#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
const int N=1e5+10;
int i,j,k,m,n,s,t,ans;
int fa[N];
int tr[N][25],mer[N][25];
vector<int> e[N],a[N];
void dfs(int u,int dep){
	a[dep].push_back(u);
	for(auto v:e[u]){
		if(v==fa[u])continue;
		fa[v]=u;dfs(v,dep+1);
	}
}
void use(int u,int rk,int target){
	int dec=min(mer[u][rk],tr[u][target]);
	mer[u][rk]-=dec,tr[u][target]-=dec;
}
void oper(int u,int x){
	int ass=0;
	tr[u][0]++;
	if(mer[u][0])mer[u][0]=tr[u][0]=0;
	for(int i=1;i<k;i++){
		use(u,i,i);
		use(u,i,i-1);
	}
	if(tr[u][k]){
		ass=(tr[u][k]-1)/s+1;
		mer[u][k]+=ass*s;
		use(u,k,k);
		use(u,k,k-1);
	}
	for(int i=0;i<k;i++){
		tr[fa[u]][i+1]+=tr[u][i];
		mer[fa[u]][i]+=mer[u][i+1];
	}
	if(u==x){
		int all=0;
		for(int i=k;i>=0;i--)
		for(int j=i;j>=0;j--)
		use(u,i,j);
		for(int i=0;i<=k;i++)
		all+=tr[u][i];
		ans+=!all?0:((all-1)/s+1);
	}
	ans+=ass;
}
int solve(int x){
	for(i=1;i<=n;i++)a[i].clear();
	dfs(x,1);
	for(i=n;i>=1;i--){
		for(auto v:a[i])
		oper(v,x);
	}
	return ans;
}
signed main(){
	read(n),read(s),read(k);
	for(i=1;i<n;i++){
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cout<<solve(1)<<endl;
	return 0;
}

