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
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
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
inline void ckmx(int& x,const int k){ x=(k>x?k:x); }
inline void ckmn(int& x,const int k){ x=(k<x?k:x); }
int n,m;
int a[155][505],s;
int f1[155][155][3],pre1[155][505];
int g1[505],g2[505],g3[505];
int fmx0[155][155],fmx1[155][155],fmx2[155][155];
//g1:I  g2:O+I  g3:N
signed main(){
	file();
	n=read(),m=read();
	per(i,n) rep(j,m) a[i][j]=read();
	//printf("%d\n",s);
	//init
	rep(j,m) rep(i,n) pre1[i][j]=pre1[i-1][j]+a[i][j];
	//calculate "I" 
	memset(f1,~0x3f,sizeof(f1));
	memset(g1,~0x3f,sizeof(g1));
	per(j,m){
		g1[j]=g1[j+1];
		for(rg int i=1;i<=n-2;++i){
			for(rg int k=i+2;k<=n;++k){
				if(j<m-2) ckmx(f1[i][k][2],f1[i][k][2]+a[i][j]+a[k][j]);
				if(j<m-1) ckmx(f1[i][k][2],f1[i][k][1]+a[i][j]+a[k][j]);
				if(j<m-1) ckmx(f1[i][k][1],f1[i][k][1]+pre1[k][j]-pre1[i-1][j]);
				if(j<m) ckmx(f1[i][k][1],f1[i][k][0]+pre1[k][j]-pre1[i-1][j]);
				if(j<m) ckmx(f1[i][k][0],f1[i][k][0]+a[i][j]+a[k][j]);
				ckmx(f1[i][k][0],a[i][j]+a[k][j]);
				ckmx(g1[j],f1[i][k][2]);
			}
		}
	}
	//calculate "O+I"
	memset(f1,~0x3f,sizeof(f1));
	memset(g2,~0x3f,sizeof(g2));
	per(j,m-4){
		g2[j]=g2[j+1];
		for(rg int i=1;i<=n-2;++i){
			for(rg int k=i+2;k<=n;++k){
				if(j<m-5) ckmx(f1[i][k][2],f1[i][k][1]+pre1[k][j]-pre1[i-1][j]);
				if(j<m-5) ckmx(f1[i][k][1],f1[i][k][1]+a[i][j]+a[k][j]);
				if(j<m-4) ckmx(f1[i][k][1],f1[i][k][0]+a[i][j]+a[k][j]);
				ckmx(f1[i][k][0],pre1[k][j]-pre1[i-1][j]+g1[j+2]);
				ckmx(g2[j],f1[i][k][2]);
			}
		}
		//printf("%d %d\n",j,g2[j]);
	}
	//calculate "N"
	memset(f1,~0x3f,sizeof(f1));
	memset(g3,~0x3f,sizeof(g3));
	rep(j,m){
		g3[j]=g3[j-1];
		if(j>2){
			for(rg int i=1;i<=n;++i){
				for(rg int k=i;k<=n;++k){
					if(j>3) ckmx(f1[i][k][2],f1[i][k][2]+pre1[k][j]-pre1[i-1][j]);
					if(j>2) ckmx(f1[i][k][2],fmx1[i][k-1]+pre1[k][j]-pre1[i-1][j]);
					ckmx(g3[j],f1[i][k][2]);
				}
			}
		}
		if(j>2){
			for(rg int k=n;k;--k){
				int mx=fmx2[k+1][k+1];
				for(rg int i=k;i;--i){
					ckmx(mx,fmx2[i][k]);
					//if(j==5&&k==5&&i==3) printf("!! %d\n",mx);
					ckmx(f1[i][k][1],mx+pre1[k][j]-pre1[i-1][j]);
				}
			}
		}
		memset(fmx1,~0x3f,sizeof(fmx1));
		memset(fmx2,~0x3f,sizeof(fmx2));
		if(j>1){
			for(rg int i=1;i<=n;++i) 
				for(rg int k=i;k<=n;++k) 
					ckmx(f1[i][k][1],fmx0[i-1][k]+pre1[k][j]-pre1[i-1][j]),
					fmx1[i][k]=max(fmx1[i][k-1],f1[i][k][1]);
			for(rg int i=1;i<=n;++i)
				for(rg int k=n;k>=i;--k)
					fmx2[i][k]=max(fmx2[i][k+1],f1[i][k][1]);
		}
		memset(fmx0,~0x3f,sizeof(fmx0));
		for(rg int i=1;i<=n;++i){
			for(rg int k=i;k<=n;++k){
				if(j>1) ckmx(f1[i][k][0],f1[i][k][0]+pre1[k][j]-pre1[i-1][j]);
				ckmx(f1[i][k][0],pre1[k][j]-pre1[i-1][j]);
				fmx0[i][k]=max(fmx0[i-1][k],f1[i][k][0]);
			}
		}
		//if(j==4) printf("%d %d\n",f1[5][6][1],fmx2[5][5]);
	}
	//merge "N" and "O+I"
	int ans=-inf;
	for(rg int j=3;j<=m-8;++j) ckmx(ans,g3[j]+g2[j+2]);
	printf("%d",ans);
	return 0;
}
/*
3 13 
1 1 -1 -1 1 -1 1 1 1 -1 1 1 1 
1 -1 1 -1 1 -1 1 -1 1 -1 -1 1 -1
1 -1 -1 1 1 -1 1 1 1 -1 1 1 1

3 13 
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

8 16
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 
-1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
1 1 1 1 -1 1 -1 1 1 1 1 -1 -1 -1 -1 -1  
1 1 1 1 1 1 -1 1 -1 -1 1 -1 -1 -1 -1 -1  
1 1 -1 -1 1 1 -1 1 -1 -1 1 -1 1 1 1 1  
-1 -1 -1 -1 1 1 -1 1 1 1 1 -1 -1 1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 -1 -1 
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 1 1 1 
*/
