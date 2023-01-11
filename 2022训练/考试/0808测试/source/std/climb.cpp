/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
struct vec{
	long double x,y;
	long double operator * (vec oth){
		return x*oth.y-y*oth.x;
	}
	vec operator - (vec oth){
		return vec{x-oth.x,y-oth.y};
	}
	vec operator + (vec oth){
		return vec{x+oth.x,y+oth.y};
	}
};
bool cmp(vec A,vec B){
	return A.x<B.x;
}
const int MAXN=2e5+233;
const long double eps=1e-7;
int n;
vec a[MAXN];
int sz;
vec sta[MAXN];
int sta2[MAXN];
vector<vec> ip;
void cross(vec A,vec B,vec C,vec D){
	long double k=(A.y-B.y)/(A.x-B.x);
	long double b=A.y-A.x*k;
	long double k2,b2;
	k2=(C.y-D.y)/(C.x-D.x);
	b2=C.y-C.x*k2;
	long double x,y;
	if(abs(k-k2)<eps) return;
	if(C.x>D.x) swap(C,D);
	x=(b2-b)/(k-k2);
	y=x*k+b;
	if(x+eps<D.x&&x-eps>C.x){
		ip.PB(vec{x,y});
	}
}
int le[MAXN],ri[MAXN],id[MAXN];
long double tar[MAXN];
bool equ(vec A,vec B){
	return abs(A.x-B.x)<eps&&abs(A.y-B.y)<eps;
}
vector<int> g[MAXN];
long double dis[MAXN];
long double rest[MAXN];
long double get(int u,int v){
	if(u>v) swap(u,v);
	return dis[v]-dis[u];
}
void dfs(int now){
	for(auto it:g[now]){
		rest[it]=rest[now]+get(it,now); 
		dfs(it);
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%Lf%Lf",&a[i].x,&a[i].y);
	sz=0;
	rb(i,1,n) ip.PB(a[i]);
	rb(i,1,n){
		while(sz>=2&&(sta[sz-1]-sta[sz])*(a[i]-sta[sz])<eps) {
			cross(sta[sz-1],sta[sz],a[i-1],a[i]);
			--sz;
		}
		sta[++sz]=a[i];
	}
	sz=0;
	rl(i,n,1){
		while(sz>=2&&(sta[sz-1]-sta[sz])*(a[i]-sta[sz])>-eps) {
			cross(sta[sz-1],sta[sz],a[i+1],a[i]);
			--sz;
		}
		sta[++sz]=a[i];
	}
	sort(ALL(ip),cmp);
	vector<vec> v;
	vec last=vec{INF,INF};
	for(auto it:ip){
		if(equ(last,it)){
			continue;
		}
		last=it;
		v.PB(it);
	}
	int m=v.size();
	int to=1;
	rep(i,m){
		while(to<=n&&a[to].x+eps<v[i].x)++to;
		if(to<=n&&equ(a[to],v[i])) id[to]=i;
	}
	rep(i,m){
//		printf("(%.6Lf %.6Lf)\n",v[i].x,v[i].y);
		le[i]=ri[i]=i;
		tar[i]=v[i].y;
	}
	sz=0;
	rep(i,m){
		while(sz>=2&&(sta[sz-1]-sta[sz])*(v[i]-sta[sz])<eps) {--sz;}
		if(sz>=1&&sta[sz].y>v[i].y) le[i]=sta2[sz],tar[i]=sta[sz].y;
		sta[++sz]=v[i];
		sta2[sz]=i;
	}
	sz=0;
	rl(i,m-1,0){
		while(sz>=2&&(sta[sz-1]-sta[sz])*(v[i]-sta[sz])>-eps) {--sz;}
		if(sz>=1&&sta[sz].y>v[i].y){
			ri[i]=sta2[sz];
			if(v[ri[i]].y>tar[i]) tar[i]=v[ri[i]].y;
//			cout<<i<<endl;
		}
		sta[++sz]=v[i];
		sta2[sz]=i;
	}
	int root=0;
	rep(i,m){
		if(ri[i]==le[i]) root=i;
	}
	stack<pair<long double ,int> > stk;
	rep(i,m){
		if(i==root) continue;
		while(!stk.empty()&&stk.top().FIR<=tar[i]+eps){stk.pop();}
		if(v[le[i]].y>v[ri[i]].y){
			if(stk.empty()||stk.top().SEC<=le[i]) g[le[i]].PB(i);
			else g[stk.top().SEC].PB(i); 
		}
		stk.push(II(tar[i],i));
	}
	while(!stk.empty()) stk.pop();
	rl(i,m-1,0){
		if(i==root) continue;
		while(!stk.empty()&&stk.top().FIR<=tar[i]+eps){stk.pop();}
		if(v[ri[i]].y>=v[le[i]].y){
			if(stk.empty()||stk.top().SEC>=ri[i]) g[ri[i]].PB(i);
			else g[stk.top().SEC].PB(i); 
		}
		stk.push(II(tar[i],i));
	}
//	rep(i,m){
//		cout<<le[i]<<' '<<ri[i]<<' ';
//		printf("%.6Lf\n",tar[i]);
//	}
	rb(i,1,m){
		double X,Y;
		X=v[i].x-v[i-1].x;
		Y=v[i].y-v[i-1].y;
		X=X*X;
		Y=Y*Y;
		dis[i]=sqrt(X+Y);
		dis[i]+=dis[i-1];
	}
	rest[root]=0;
	dfs(root);
	rb(i,1,n){
		printf("%.2Lf\n",rest[id[i]]);
	}
	return 0;
}

