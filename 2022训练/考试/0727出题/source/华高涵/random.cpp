#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define re return
#define all(a) a.begin(),a.end()
#define int long long
#define rept(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) rept(i,0,a)
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define elif else if
using namespace std;
const int MOD=1000000007,INF=1000000000000000000;
template<typename T>inline void Mx(T &a,T b){a=max(a,b);}
template<typename T>inline void Mi(T &a,T b){a=min(a,b);}
inline int ad(int &a,int b,int c=MOD){re a=(a+b)%c;}
template<typename T>inline T read(){T a;cin>>a;re a;}
inline bool is_digit(int msk,int d){re (msk>>d)&1;}
const int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
vi pr,ans;
int pw[10];
int n,m,tot;
int fac[100005][10],num[100005][10];
void get_div(){
	int m2=m;
	rep(i,10)pw[i]=0;
	pr.clear();
	for(int i=2;i*i<=m2;i++){
		if(m2%i==0){
			while(m2%i==0)m2/=i,pw[tot]++;
			pr.pb(i);
			tot++;
		}
	}
	if(m2>1){
		pw[tot]++;
		pr.pb(m2);
		tot++;
	}
}
void get_num(int x){
	int x2=x;
	rep(i,10)num[x][i]=0;
	rep(i,tot){
		while(x2%pr[i]==0){
			x2/=pr[i];
			num[x][i]++;
		}
		fac[x][i]=fac[x-1][i]+num[x][i];
	}
}
void run(){
	cin>>n>>m;
	get_div();
	rep(i,tot)fac[0][i]=0;
	rept(i,1,n)get_num(i);
	ans.clear();
	rep(i,n){
		int ok=1;
		rep(j,tot)
			ok&=fac[n-1][j]-fac[i][j]-fac[n-1-i][j]>=pw[j];
		if(ok)
			ans.pb(i+1);
	}
	cout<<sz(ans)<<"\n";
	for(int i:ans)cout<<i<<"\n";
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	for(int tc=read<int>();tc;tc--)
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
		run();
	re 0;
}


