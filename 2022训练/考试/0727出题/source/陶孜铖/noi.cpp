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
const int MAXN=155,MAXM=525;
int N,M;
int A[MAXM][MAXN];
int prv[MAXM][MAXN];
int n1[MAXN][MAXN],n2[MAXN][MAXN],n3[MAXN][MAXN],n4[MAXN][MAXN];
int o[MAXN][MAXN],i1[MAXN][MAXN],i2[MAXN][MAXN];

signed main(void){
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>N>>M;REPA(i,N)REPA(j,M)cin>>A[j][i];
	REPA(i,M){
		REPA(j,N)prv[i][j]=prv[i][j-1]+A[i][j];
	}
	int k=0;
	memset(n1,0xcf,sizeof(n1));
	memset(n2,0xcf,sizeof(n2));
	memset(n3,0xcf,sizeof(n3));
	memset(n4,0xcf,sizeof(n4));
	memset(o,0xcf,sizeof(o));
	memset(i1,0xcf,sizeof(i1));
	memset(i2,0xcf,sizeof(i2));
	int n_mx=-LINF,o_mx=-LINF,ans=-LINF;
	REPA(i,M){
		REPA(l,N)for(int r=l+2;r<=N;++r){
			i1[l][r]=max(i1[l][r],o_mx);
			ans=max(ans,i2[l][r]+A[i][l]+A[i][r]);
			i2[l][r]=max(i2[l][r],i1[l][r]+prv[i][r-1]-prv[i][l]);
			i2[l][r]+=A[i][l]+A[i][r];
			i1[l][r]+=A[i][l]+A[i][r];
		}
		REP(l,N)for(int r=l+2;r<=N;++r){
			o_mx=max(o_mx,o[l][r]+prv[i-1][r-1]+prv[i-1][l]);
		}
		REPA(l,N)for(int r=l+2;r<=N;++r){
			o[l][r]=max(o[l][r],n_mx+prv[i][r-1]-prv[i][l]);
			o[l][r]+=A[i][l]+A[i][r];
		}
		REPA(l,N)for(int r=l;r<=N;++r)n_mx=max(n_mx,n4[l][r]);
		REPA(l,N){
			int suf=-LINF;
			for(int r=N;r>=l;--r){
				suf=max(suf,n1[l][r]);
				n1[l][r]=max(n1[l][r],0ll)+prv[i][r]-prv[i][l-1];
				n3[l][r]=max(n3[l][r],n2[l][r]);
				n2[l][r]=max(n2[l][r],suf);
				n2[l][r]+=prv[i][r]-prv[i][l-1];
				
			}
		}
		REPA(r,N){
			int suf=-LINF;
			for(int l=r;l>=1;--l){
				n4[l][r]=max(n4[l][r],suf);
				suf=max(suf,n3[l][r]);
			}
		}
		REPA(r,N){
			for(int l=1;l<=r;++l){
				n3[l+1][r]=max(n3[l+1][r],n3[l][r]);
			}
		}
		REPA(l,N){
			for(int r=l-1;r+1<=N;++r){
				n3[l][r+1]=max(n3[l][r+1],n3[l][r]);
			}
		}
		REPA(l,N)for(int r=l;r<=N;++r){
			n3[l][r]+=prv[i][r]-prv[i][l-1];
			n4[l][r]+=prv[i][r]-prv[i][l-1];
		}
//		cout<<i<<":\n";
//		REPA(l,N){
//			REPA(r,N){
//				cout<<n1[l][r]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//		REPA(l,N){
//			REPA(r,N){
//				cout<<n2[l][r]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//		REPA(l,N){
//			REPA(r,N){
//				cout<<n3[l][r]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//		REPA(l,N){
//			REPA(r,N){
//				cout<<n4[l][r]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*
think twice, code once;
think once, debug forever.
*/


