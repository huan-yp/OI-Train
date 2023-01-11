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
const int MAXN=2e5+100;
int N,A[MAXN],B[MAXN],ta[MAXN],id[MAXN];

signed main(void){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>N;
	REPA(i,N)cin>>A[i],ta[A[i]]=i;
	REPA(i,N)cin>>B[i],id[i]=ta[B[i]];
//	REPA(i,N)cout<<id[i]<<' ';
//	cout<<endl;
	int cnt=0,m=0;
	ld ans=0;
	vector<pii>stk;
	id[1]=INF;
	stk.pb(mp(1,1));
	for(int i=2;i<=N;++i){
		if(id[i]<id[i-1])++m;
		while(stk.size()&&stk.back().fi>id[i]){
//			if(stk.back().se)cout<<"??\n";
			stk.pop_back();
		}
		if(id[i]<id[i-1]||id[i]-stk.back().fi!=1)stk.pb(mp(id[i],1));
		else stk.pb(mp(id[i],0));
	}
	for(auto x:stk)if(!x.se)++cnt;
	ans=(ld)m+1+(ld)cnt*(ld)0.5;
//	cout<<m<<' '<<cnt<<endl;
	cout<<fixed<<setprecision(3)<<ans;
	return 0;
}
/*
think twice, code once;
think once, debug forever.
*/
/*
7
1 2 3 4 5 6 7
1 2 3 5 4 6 7
*/

