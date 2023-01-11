#include<bits/stdc++.h>
#define ll long long
#define int ll
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define REP(i,j) for(int i=0;i<j;++i)
#define REPA(i,j) for(int i=1;i<=j;++i)
#define vi vector<int>
#define pii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
const ll LINF=0x3f3f3f3f3f3f3f3f;
const ll MOD=1e9+7;
inline void read(int &x){
//	short neg=1;
	x=0;
	char c=getchar();
	/*while(c<'0'||c>'9'){
		if(c=='-')neg=-1;
		c=getchar();
	}*/
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
//	x*=neg;
}
ll quick_mod(ll A,ll B){//A^B
    ll ret=1;
    A%=MOD;
    while(B){
        if(B&1)ret=ret*A%MOD;
        B>>=1;
        A=A*A%MOD;
    }
    return ret;
}
inline void chkmin(ll &x,ll y){x=min(x,y);}
inline void chkmax(ll &x,ll y){x=max(x,y);}
inline void add(ll &x,ll y){x=(x+y)%MOD;}
inline ll rev(ll x){return quick_mod(x,MOD-2);}
inline int lowbit(int x){return x&(-x);}
const int MAXN=1e5+100;
int N,M;
vector<pii>v[MAXN];
int val[MAXN];
int cnt[MAXN];

signed main(void){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>N>>M;
	if(M==1){
		cout<<N<<"\n";
		REPA(i,N)cout<<i<<" ";
		return 0;
	}
	if(N==1){
		cout<<0<<"\n";
		return 0;
	}
	vector<pii>vm;
	for(int i=2;i*i<=M;++i){
		if(M%i==0){
			int tmp=0;
			while(M%i==0)M/=i,++tmp;
			vm.pb(mp(i,tmp));
		}
	}
	if(M>1)vm.pb(mp(M,1));
	for(auto x:vm){
		if(x.fi>=MAXN){
			cout<<0;
			return 0;
		}
	}
	REPA(i,N)val[i]=i;
	for(int i=2;i<=N;++i)if(val[i]>1){
		for(int j=i;j<=N;j+=i){
			int tmp=0;
			while(val[j]%i==0)val[j]/=i,++tmp;
			v[j].pb(mp(i,tmp));
		}
	}
	vi ans;ans.clear();
	for(int x=N-1,y=1;y<N;++y,--x){
		for(auto it:v[x])cnt[it.fi]+=it.se;
		for(auto it:v[y])cnt[it.fi]-=it.se;
		bool flag=1;
		for(auto it:vm){
			if(cnt[it.fi]<it.se){
				flag=0;
				break;
			}
		}
		if(flag){
			ans.pb(y+1);
		}
	}
	cout<<ans.size()<<"\n";
	for(auto x:ans){
		cout<<x<<' ';
	}
	return 0;
}
/*
think twice, code once;
think once, debug forever.
*/


