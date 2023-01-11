#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=37,M=36*36+5,T=M,W=T*T;
struct trans{
	int rk,l,r;
	friend bool operator ==(const trans &a,const trans &b){
		return a.rk==b.rk&&a.l==b.l&&a.r==b.r;
	}
};
struct hash_fun{
	long long operator ()(const trans &x) const{
		return 1ll*x.rk*W+x.l*T+x.r;
	}
};
__gnu_pbds::gp_hash_table<trans,int,hash_fun>dp;
int i,j,k,m,n,s,t;
int a[M],val[4][N][N],rk[4][N][N];
vector<int> e[M];
void addedge(int u,int v){
	e[u].push_back(v),e[v].push_back(u);
}
int solve(int rk,int l,int r){
	//底层研究：局部 vector 是否会频繁 new,delete 
	auto it=dp.find(trans{rk,l,r});
	if(it!=dp.end())return it->second;
	t++;int w=1;
	for(auto v1:e[rk]){
		if(a[v1]<l||a[v1]>r)continue;
		for(auto v2:e[rk]){
			int sum=1;
			if(a[v2]<l||a[v2]>r)continue;
			if(a[v1]<a[rk])sum+=solve(v1,l,a[rk]-1);
			if(a[v2]>a[rk])sum+=solve(v2,a[rk]+1,r);
			cmax(w,sum);
		}
	}
	return dp[trans{rk,l,r}]=w;
}
int main(){
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	//read(n),cout<<n<<endl;
	read(n);
	for(int o=0;o<4;o++){
		for(i=1;i<=n;i++){
			for(j=1;j<=2*i-1;j++)
			rk[o][i][j]=++s,read(a[s]);
			for(j=1;j<2*i-1;j++)
			addedge(rk[o][i][j],rk[o][i][j+1]);
			for(j=2;j<=2*i-1;j+=2)
			addedge(rk[o][i][j],rk[o][i-1][j-1]);
		}
	}
	//AD
	for(i=1;i<=n;i++)addedge(rk[0][n][i*2-1],rk[3][n-i+1][1]);
	//BD
	for(i=1;i<=n;i++)addedge(rk[1][n][i*2-1],rk[3][i][2*n-1]);
	//CD
	for(i=1;i<=n;i++)addedge(rk[2][n][i*2-1],rk[3][n][2*n-2*i+1]);
	//AB
	for(i=1;i<=n;i++)addedge(rk[0][i][i*2-1],rk[1][i][1]);
	//BC
	for(i=1;i<=n;i++)addedge(rk[1][i][i*2-1],rk[2][i][1]);
	//CA
	for(i=1;i<=n;i++)addedge(rk[2][i][i*2-1],rk[0][i][1]);
	int ans=0;
	for(int o=0;o<4;o++)
	for(i=1;i<=n;i++)
	for(j=1;j<2*i;j++)
	cmax(ans,solve(rk[o][i][j],1,n*n*4));
	cout<<ans<<endl;
//	cout<<t<<endl;
	return 0;
}

