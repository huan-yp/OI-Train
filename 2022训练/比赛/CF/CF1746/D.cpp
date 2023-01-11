#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=2e5+10;
int i,j,n,s,t,m,k;
int c[N];
__gnu_pbds::gp_hash_table<int,int> dp[N];
vector<int> e[N];
int solve(int u,int k){
	if(k==0)return 0;
	auto it=dp[u].find(k);
	if(it!=dp[u].end())return it->second;
	dp[u][k]=c[u]*k;
	int sz=e[u].size();
	if(sz==0)return dp[u][k];
	if(sz==1)return dp[u][k]+=solve(e[u][0],k);
	vector<int> sl;
	int ik=k/sz,xk=ik+1,ck=k%sz;
	for(auto v:e[u]){
		sl.push_back(solve(v,xk)-solve(v,ik));
		dp[u][k]+=solve(v,ik);
	}
	sort(sl.begin(),sl.end(),greater<int>());
	for(int i=0;i<ck;i++)
	dp[u][k]+=sl[i];
	return dp[u][k];
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		read(n),read(k);
		for(i=1;i<=n;i++)e[i].clear(),dp[i].clear();
		for(i=2;i<=n;i++){
			int x;read(x);
			e[x].push_back(i);
		}
		for(i=1;i<=n;i++)read(c[i]);
		printf("%lld\n",solve(1,k));
	}
	return 0;
}


