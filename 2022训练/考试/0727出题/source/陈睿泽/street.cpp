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
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
}
char buf[1<<21],*p1=buf,*p2=buf;
inline int getc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,(1<<20)+5,stdin),p1==p2)?EOF:*p1++;
}
#define getc getchar
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
inline void ckmx(int& x,const int k){ x=(k>x?k:x); }
inline void ckmn(int& x,const int k){ x=(k<x?k:x); }

int n,to,dep[100005],col[100005];
char ch[5];
vec e[100005];
ll f[100005],g[100005],siz[100005];
inline bool cmp1(int x,int y){ return g[x]*siz[y]<g[y]*siz[x]; }
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	if(!e[x].size()) return siz[x]=1,f[x]=0,g[x]=2,col[x]=1,void();
	vec son;
	for(int y:e[x]) dfs(y,x),g[x]+=g[y],siz[x]+=siz[y],son.epb(y);
	sort(all(son),cmp1); ll nw=0;
	for(int y:son){
		f[x]+=(nw+1)*siz[y]+f[y];
		nw+=g[y];
	}
	if(col[x]) g[x]=2;
}
signed main(){
	file();
	scanf("%d",&n);
	for(rg int i=2;i<=n;++i){
		scanf("%d%s",&to,ch); 
		col[i]=(ch[0]=='Y'); e[to].epb(i);
	}
	dfs(1,0);
	//printf("%lld %d\n",f[1],siz[1]);
	double ans=(double)f[1]/(double)siz[1];
	printf("%.8lf\n",ans);
	return 0;
}
/*
5 
1 N 
1 Y 
3 N
3 N

10 
1 Y 
1 N 
2 N 
2 N 
2 N 
3 N 
3 Y 
8 N
8 N
*/
