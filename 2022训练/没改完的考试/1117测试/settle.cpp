#include<bits/stdc++.h>
#define INF 1000000000
#define LL long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int mod=1e9+7,N=105;
int k,m,n,t,ans;
int e[N][4],fa[N],dep[N],dp[N];
int mp[N][N][2];
vector<tuple<int,int,int>> ed[N];
bool ok(vector<int> ve){
	for()
}
vector<int> dfs(int u){
	vector res;int flag;
	for(auto [v,d,s]:e[u]){
		
	}
	if(!res.empty()){
		res.push_back(u);
		if(ok(res))
	}
	return res;
}
int main(){
	freopen("settle.in","r",stdin);
//	freopen("settle.out","w",stdout);
	int tot,i,j;
	read(tot);
	while(tot--){
		int base=1,maxn=0;
		memset(dp,0,sizeof(dp));
		read(n),read(m),read(k);
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		mp[i][j][0]=mp[i][j][1]=1;
		for(i=1;i<=m;i++){
			for(j=0;j<4;j++)
			read(e[i][j]);
			mp[e[i][1]][e[i][0]][1]=1ll*mp[e[i][1]][e[i][0]][1]*e[i][2]%mod;
			mp[e[i][1]][e[i][0]][0]=1ll*mp[e[i][1]][e[i][0]][0]*e[i][3]%mod;
			mp[e[i][0]][e[i][1]][0]=1ll*mp[e[i][0]][e[i][1]][0]*e[i][3]%mod;
			mp[e[i][0]][e[i][1]][1]=1ll*mp[e[i][0]][e[i][1]][1]*e[i][2]%mod;
		}
		for(i=1;i<=n;i++)base=1ll*base*mp[i][i][0]%mod;
		for(i=1;i<=n;i++)for(j=1;j<i;j++){
			if(mp[i][j][0]==1&&mp[i][j][1]==1)continue;
			ed[i].emplace_back(j,mp[i][j][1],mp[i][j][0]);
			ed[j].emplace_back(i,mp[i][j][1],mp[j][i][0]);
		}
		memset(dep,1,sizeof(dep));
		dep[1]=1;queue<int> q;q.push(1);
		while(!q.empty()){
			int u=q.front();q.pop();
			cmax(maxn,dep[u]);
			for(auto [v,d,s]:ed[u]){
				if(dep[v]<=dep[u]+1)continue;
				dep[v]=dep[u]+1,fa[v]=u;
				q.push(v);
			}
		}
		cout<<maxn<<endl;
		dfs(1);
		cout<<dp[1]<<endl;
	}
	return 0;
}

