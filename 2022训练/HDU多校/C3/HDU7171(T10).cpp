#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
int read() {
    const int M = 1e7;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0;
    while(c < 48) c = gc;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=1e5+10,T=10,P=1<<T,R=1<<T-6; 
int i,j,k,n,s,t,m,tp1,tp2;
int ans[N],g[N][2],from[N],rk[N];
template<int S>
struct Bitset{
	#define ull unsigned long long
	unsigned long long a[(S-1>>6)+1];
	void reset(){
		memset(a,0,sizeof(a));
	}
	void set(int x,int val){
		if(a[x>>6]&(ull)1<<(x&63)){
			a[x>>6]&=((~(ull)0)^((ull)1<<(x&63)))|(ull)val<<(x&63);
		}
		else{
			a[x>>6]|=(ull)val<<(x&63);
		}
	}
	bool operator [](int x){
		return a[x>>6]&((ull)1<<(x&63));
	}
	void trans(const Bitset<S> &b,const Bitset<S> &c){
		for(int i=0;i<R;i+=4){
			a[i]|=b.a[i]&c.a[i];
			a[i+1]|=b.a[i+1]&c.a[i+1];
			a[i+2]|=b.a[i+2]&c.a[i+2];
			a[i+3]|=b.a[i+3]&c.a[i+3];
		}
	}
	void operator ^=(const Bitset<S> &b){
		for(int i=0;i<R;i+=4){
			a[i]^=b.a[i];
			a[i+1]^=b.a[i+1];
			a[i+2]^=b.a[i+2];
			a[i+3]^=b.a[i+3];
		}
	}
//	void operator =(const Bitset<S> &b){
//		memcpy(a,b.a,sizeof((S-1>>6)+1));
//	}
	#undef ull
};
Bitset<P>arr[N>>1],mask[N];
struct edge{
	int v,S;
};
bool cmp(int a,int b){
	return g[a][0]<g[b][0];
}
struct query{
	int l,r,u,v,rk;
	void init(int x){
		u=read(),v=read(),l=read(),r=read();
		rk=x;arr[u].set(x&(P-1),1);
		mask[l].set(x&(P-1),1),mask[r+1].set(x&(P-1),1);
	}
	void get(){
		ans[rk]=arr[v][rk&(P-1)];
	}
}qry[N];
void solve(){
	for(int i=1;i<=m;i++){
		int u=g[rk[i]][0],v=g[rk[i]][1];
		arr[v].trans(arr[u],mask[rk[i]]);
	}
	for(i=0;i<=s;i++)qry[i].get();
}
signed main()
{
	t=read();
	while(t--){
		int q;
		n=read(),m=read(),q=read();
		for(i=1;i<=m;i++)g[i][0]=read(),g[i][1]=read(),rk[i]=i;
		
		sort(rk+1,rk+m+1,cmp);
		for(int b=0;b<=q-1>>T;b++){
			
			memset(mask,0,sizeof(mask));
			for(i=1;i<=n;i++)arr[i].reset();
			s=(b==q>>T)?(q-1)&(P-1):P-1;
			for(i=0;i<=s;i++)
			qry[i].init((b*P)+i);
			
			for(i=1;i<=m;i++)mask[i]^=mask[i-1];
			
			solve();
		}
		for(i=0;i<q;i++)
		if(ans[i])puts("YES");
		else puts("NO");
	}
	return 0;
}
