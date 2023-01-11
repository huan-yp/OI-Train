#include<cstdio>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<vector>
#define rep(i,x,y) for(int i=(x),_=(y);i<=_;i++)
#define per(i,x,y) for(int i=(x),_=(y);i>=_;i--)
using namespace std;
typedef long long LL;

const int N=1e5+10;

int n,m;
int prime[N+1],pos[N+1],tot,mx;
bool nprime[N+1]; 

inline bool
isprime(int x){
	if(x<=n) return !nprime[x];
	rep(i,1,tot) if(x%prime[i]==0) return 0;
	return 1;
}

LL
power(LL a,int b){
	LL res=1;
	for(;b;b>>=1,a=a*a%m) if(b&1) res=res*a%m;
	return res; 
}

int cnt[2][N+1];

inline int
fool(){
	cout<<n<<'\n';
	rep(i,1,n) cout<<i<<' ';
	cout<<endl;
	return 0;
}

inline void
work(LL x,int *cnt,int add,int &mx){
	rep(i,1,tot){
		if(prime[i]*prime[i]>x) break;
		if(x%prime[i]==0){
			do cnt[i]+=add,x/=prime[i];
			while(x%prime[i]==0);
			mx=i;	
		}
	}
	if(x!=1) cnt[pos[x]]+=add,mx=max(mx,pos[x]);
}

inline bool
pd(){
	rep(i,1,mx) if(cnt[0][i]<cnt[1][i]) return 0;
	return 1;
}

int
main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;nprime[1]=1;
	if(m==1) return fool();
	rep(i,2,n){
		if(!nprime[i]) prime[++tot]=i,pos[i]=tot;
		for(int j=1;j<=tot&&i*prime[j]<=n;j++){
			nprime[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	if(isprime(m)&&m>n) return cout<<0<<endl,0;
	int tot=0;LL c=1;
	work(m,cnt[1],+1,mx);int rub;
	vector<LL>res;
	rep(i,1,n-1){
		work(n-i,cnt[0],+1,rub);
		work(i,cnt[0],-1,rub);
		if(pd()) res.emplace_back(i);
	}
	cout<<res.size()<<endl;
	for(const LL i:res) cout<<i+1<<' ';
	return 0;
}
//应该是杨辉三角吧 
