/*
First contest after losing you.
In memory of you.
The smile lighting me up.
*/
#include<bits/stdc++.h>
#define int long long
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
const int N=1005,M=2005,mod=998244353;
int i,j,k,m,n,s,t,q;
int dp[2][N];
signed e[M][3],maxn[N];
struct line{
	int k,b;
	int operator ()(int x){
		return x*k+b;
	}
	bool operator <(const line &a) const{
		if(k!=a.k)return k<a.k;
		return b<a.b;
	}
	
}st[N],all[N];
int get_sum(int l,int r){
	return (1ll*(r-l+1)*(l+r)/2)%mod;
}
int calc_ans(int l,int r,line a){
	return get_sum(l,r)*a.k+(r-l+1)*a.b;
}
int get_ins(line L,line R){
	assert(L.k<R.k&&L.b>R.b);
	int l=-2e9,r=2e9,res=-2e9;
	while(r>=l){
		int mid=(l+r)/2;
		if(L(mid)>=R(mid))
		res=mid,l=mid+1;
		else
		r=mid-1;
	}
	return res;
}
double slope(line a,line b){
	return 1.0*(a.b-b.b)/(b.k-a.k);
}
void solve(){
	int top=0,ans=0;
	memset(maxn,0,sizeof(maxn));
	read(n),read(m),read(q);
	for(i=1;i<=m;i++){
		read(e[i][0]),read(e[i][1]),read(e[i][2]);
		cmax(maxn[e[i][0]],e[i][2]);
		cmax(maxn[e[i][1]],e[i][2]);
	}
	for(i=1;i<=n;i++)all[i].k=maxn[i],all[i].b=-1e18;
	memset(dp,193,sizeof(dp));dp[0][1]=0;
	for(i=0;i<=n;i++){
		int res=0;
		for(j=1;j<=n;j++){
			cmax(all[j].b,(dp[i&1][j]-i*all[j].k)%mod);
			cmax(res,dp[i&1][j]);
		}
		for(j=1;j<=m;j++){
			cmax(dp[i+1&1][e[j][1]],dp[i&1][e[j][0]]+e[j][2]);
			cmax(dp[i+1&1][e[j][0]],dp[i&1][e[j][1]]+e[j][2]);
		}
		if(i<=q)ans+=res;
	}
	sort(all+1,all+n+1);
	for(i=1;i<=n;i++){
		while((top&&all[i].b>=st[top].b)||(top>1&&slope(all[i],st[top-1])>slope(all[i],st[top])))top--;
		st[++top]=all[i];
	}
	int lst=min(n,q);
	for(i=1;i<top;i++){
		if(lst==q)break;
		int end=get_ins(st[i],st[i+1]);cmin(end,q);
		if(end<=lst)continue;
		ans=(ans+calc_ans(lst+1,end,st[i]))%mod;
		lst=end;
	}
	if(lst!=q)ans=(ans+calc_ans(lst+1,q,st[top]))%mod;
	cout<<(ans%mod+mod)%mod<<endl;
}
signed main(){
//	freopen("wool.in","r",stdin);
//	freopen("wool.out","w",stdout);
	int t;read(t);
	while(t--){
		solve();	
	}
	return 0;
}

