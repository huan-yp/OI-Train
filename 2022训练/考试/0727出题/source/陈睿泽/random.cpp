//Was yea ra,rra yea ra synk sphilar yor en me exec hymme METAFALICA waath!
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define rg register
#define ll long long
#define ull unsigned ll
#define lowbit(x) (x&(-x))
#define djq 998244353
const double eps=1e-8;
const short sint=0x3f3f;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const double alpha=0.73;
inline void file(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
}
char buf[1<<21],*p1=buf,*p2=buf;
inline int getc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,(1<<20)+5,stdin),p1==p2)?EOF:*p1++;
}
//#define getc getchar
inline ll read(){
	rg ll ret=0,f=0;char ch=getc();
    while(!isdigit(ch)){if(ch==EOF)exit(0);if(ch=='-')f=1;ch=getc();}
    while(isdigit(ch)){ret=ret*10+ch-48;ch=getc();}
    return f?-ret:ret;
}
#define epb emplace_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define it iterator
#define mkp make_pair
#define naive return 0*puts("YES")
#define angry return 0*puts("NO")
#define fls fflush(stdout)
#define rep(i,a) for(rg int i=1;i<=a;++i)
#define per(i,a) for(rg int i=a;i;--i)
#define rep0(i,a) for(rg int i=0;i<=a;++i)
#define per0(i,a) for(rg int i=a;~i;--i)
typedef vector<int> vec;
typedef pair<int,int> pii;
struct point{ int x,y; point(int x=0,int y=0):x(x),y(y) {} inline bool operator<(const point& T)const{ return x^T.x?x<T.x:y<T.y; }; };
inline int ksm(int base,int p){int ret=1;while(p){if(p&1)ret=1ll*ret*base%djq;base=1ll*base*base%djq,p>>=1;}return ret;}
inline void pls(int& x,const int k){ x=(x+k>=djq?x+k-djq:x+k); }
inline int add(const int a,const int b){ return a+b>=djq?a+b-djq:a+b; }
inline void sub(int& x,const int k){ x=(x-k<0?x-k+djq:x-k); }

int n,m;
int a[100005][55],nw[55];
int p[55],c[55],cnt;
vec ans;
signed main(){
	file();
	n=read(),m=read();
	for(rg int i=2;i*i<=m;++i){
		if(m%i) break;
		p[++cnt]=i;
		while(m%i==0) ++c[cnt],m/=i;
	}
	if(m!=1) p[++cnt]=m,c[cnt]=1;
	rep(i,n-1){
		int tmp=i;
		rep(j,cnt) while(tmp%p[j]==0) tmp/=p[j],++a[i][j];
	}
	for(rg int i=0;i<n;++i){
		rep(j,cnt) nw[j]+=a[n-i][j],nw[j]-=a[i][j];
		bool fla=1;
		rep(j,cnt) if(nw[j]<c[j]){ fla=0; break; }
		if(fla) ans.epb(i+1);
	}
	printf("%d\n",ans.size());
	for(int x:ans) printf("%d ",x);
	return 0;
}
/*


*/
