#include<bits/stdc++.h>
using namespace std;
namespace Def{
#define ll long long
#define lll __int128
#define lb long double
#define D double
#define emb emplace_back
#define mkp make_pair
#define Array vector<int>
#define Pair pair<int,int>
#define fi first
#define se second
#define rep(variable,leftrange,rightrange) for(int variable=leftrange;variable<=rightrange;++variable)
#define Rep(variable,leftrange,rightrange) for(int variable=leftrange;variable>=rightrange;--variable)
#define Find(a,b) (lower_bound(a.begin(),a.end(),b)-a.begin())
#define Uniq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define All(x) x.begin(),x.end()
#define nxtl puts("")
#define sq(x) ((x)*(x))
#define lowbit(x) ((x)& -(x))
#define IF(x,y,z) (x)&&(y)||(z)
#define If(x,y) (x)&&(y)
}
namespace LOCAL{
#ifdef DEBUG
#define react puts("reacting now !")
#define debug(x) cout << #x << " = " <<  x << "\n"; 
#define debug2(l,r) cout << "[" #l "," #r "] = [" << l << "," << r << "]\n" ;
#define debug3(x,y,z) cout << "{" #x "," #y "," #z "} = " << "{" << x << "," << y << "," << z << "}\n" ; 
#define debug_vec(v) cout << #v": size= " << v.size() << "\nelement: " ; for(auto p:v)  cout << p << " " ;
#define FileIO(x) 
#else 
#define react
#define debug(x) 
#define debug2(l,r)
#define debug3(x,y,z)
#define debug_vec(v)
#define FileIO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#endif 
}
namespace IO {
#define MAXSIZE (1<<20)
char *IO_p1,*IO_p2,IO_buf[MAXSIZE];
#ifdef DEBUG
#define gchar() getchar()
#else
#define gchar() (IO_p1==IO_p2&&(IO_p2=(IO_p1=IO_buf)+fread(IO_buf,1,MAXSIZE,stdin),IO_p1==IO_p2)?EOF:*IO_p1++)
#endif
template<typename _Tp>inline void read(_Tp &x){
    x=0;char ch=gchar();
    for(;!isdigit(ch);ch=gchar());
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
}
template<typename _Tp>inline void nread(_Tp &x){
    x=0;_Tp f=1;char ch=gchar();
    for(;!isdigit(ch);ch=gchar())ch=='-'&&(f=-1);
    for(;isdigit(ch);ch=gchar())x=(x<<1)+(x<<3)+(ch^48);
    x*=f;
}
template<typename _Tp,typename ...Args>
inline void read(_Tp &x,Args &...args){read(x),read(args...);}
template<typename _Tp,typename ...Args>
inline void nread(_Tp &x,Args &...args){nread(x),nread(args...);}
template<typename _Tp>inline void wrt(_Tp x){
    if(x<0)x=-x,putchar('-');
    if(x>9)wrt(x/10);
    putchar(x%10+48);
}
inline void wrt(char ch){putchar(ch);}
template<typename _Tp,typename ...Args>
inline void wrt(_Tp x,Args ...args){wrt(x),wrt(args...);}
#undef MAXSIZE
}
namespace Fast{
    inline void Read(pair<int,int> &x) { IO::read(x.fi,x.se); }
    inline void Read(vector<int> &v,int n){v.resize(n);for(auto &p:v) IO::read(p);}
    inline void Wrt(pair<int,int> x,char c) { IO::wrt(x.fi,' ',x.se,c); }
    inline void Wrt(vector<int> v,char c){for(auto p:v) IO::wrt(p,c);}    
    template<typename _Tp>inline void Swap(_Tp &x,_Tp &y) {x^=y^=x^=y;}
    template<typename _Tp>inline _Tp Min(_Tp x,_Tp y){return x<y?x:y;}
    template<typename _Tp>inline _Tp Max(_Tp x,_Tp y){return x>y?x:y;}
    template<typename _Tp>inline void Add(_Tp &x,_Tp y,_Tp p){x+=y;if(x>=p)x-=p;}
    template<typename _Tp>inline void upmax(_Tp &x,_Tp y){if(y>x)x=y;} 
    template<typename _Tp>inline void upmin(_Tp &x,_Tp y){if(y<x)x=y;}
}
using namespace IO ;
using namespace Def ;
using namespace Fast ; 
using namespace LOCAL ;
const int N = 2e5 + 20 ;
int n , mst , dfs[N] , bfs[N] , ibfs[N] , idfs[N] , res[N]; 
int nwdfs[N] , determined[N];  
ll tot = 0 ; 
/*互相独立，维护区间覆盖*/

namespace Cover{
    int cv[N << 2] ;
    void cov(int x,int l,int r,int L,int R) {
        if(R < L) return ; 
        if(L<=l&&r<=R) return cv[x] = 1 ,void ( );
        int mid = (l + r) >> 1 ; 
        if(L<=mid) cov(x<<1,l,mid,L,R);
        if(R>mid) cov(x<<1|1,mid+1,r,L,R);
    }
    int qry(int x,int l,int r,int p) {
        if(l == r) return cv[x] ; 
        int mid = (l + r) >> 1 ;
        if(p<=mid) return cv[x] || qry(x << 1 , l , mid , p ) ;
        return cv[x] || qry(x << 1 | 1 , mid + 1 , r , p ) ;
    }
}

signed main()
{
    FileIO(tree) ;
    read(n);
    
    rep(i,1,n) read(dfs[i]) , idfs[dfs[i]] = i ;
    rep(i,1,n) read(bfs[i]) , ibfs[bfs[i]] = i ;
    rep(i,1,n) nwdfs[idfs[bfs[i]]] = i ; 
    rep(i,1,n) idfs[nwdfs[i]] = i ;
    tot = 4 ; 
    rep(i,1,n - 1) if(idfs[i] > idfs[i + 1]) determined[i] = 1 , tot += 2 ;
    rep(i,1,n - 1) {
        if(nwdfs[i] + 1 < nwdfs[i + 1]) {
            Cover::cov(1,1,n,nwdfs[i],nwdfs[i+1]-1);
        }
    } 
    rep(i,2,n - 1) {
        if(!determined[i] && !Cover::qry(1,1,n,i)) tot ++  ; 
    }
    D ret = tot / 2.0 ;
    printf("%.6lf\n",ret);
    return 0;
}