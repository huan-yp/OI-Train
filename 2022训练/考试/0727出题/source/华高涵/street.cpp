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
double dp2[100005];
int dp1[100005],cnt[100005],pa[100005],ok[100005];
vi v[100005];
int n;
void run(){
	cin>>n;
	rept(i,1,n){
		int x;string y;
		cin>>x>>y;
		x--;
		pa[i]=x;
		v[x].pb(i);
		if(y[0]=='Y')ok[i]=1;
	}
	for(int i=n-1;i>=0;i--){
		if(v[i].empty()){
			cnt[i]=ok[i]=1;
			dp1[i]=0;
		}
		else{
			dp1[i]=0;
			if(!ok[i])dp1[i]=sz(v[i])*2;
			for(int j:v[i]){
				cnt[i]+=cnt[j];
				if(!ok[i])dp1[i]+=dp1[j];
			}
		}
	//	cout<<i<<": "<<dp1[i]<<"\n";
	}
	for(int i=n-1;i>=0;i--){
		dp2[i]=0.0;
		vector<pii>vv;
		int s=0,ss=0;
		for(int j:v[i])s+=cnt[j];
		for(int j:v[i])vv.pb({(s-cnt[j])*(dp1[j]+2),j});
		sort(all(vv));
		for(pii j:vv)dp2[i]+=1.0*cnt[j.S]/s*(ss+1.0+dp2[j.S]),ss+=dp1[j.S]+2;//,cout<<j.S<<" "<<dp2[i]<<" "<<ss<<"\n";cout<<"\n";
	//	cout<<i<<": "<<dp2[i]<<"\n";
	}
	cout<<fixed<<setprecision(8)<<dp2[0]<<"\n";
}
signed main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	for(int tc=read<int>();tc;tc--)
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
		run();
	re 0;
}


