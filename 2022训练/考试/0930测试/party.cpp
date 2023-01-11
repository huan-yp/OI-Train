#include<bits/stdc++.h>
#define int long long
#define INF 1000000000
#define low(x) ((x)&-(x))
using namespace std;
template<typename T>
T read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1.5e5+10;
int i,j,k,m,n,s,t,tot,ans;
struct point{
	int l,r,x;
	void init(){read(l),read(r),read(x);}
	bool operator <(const point &a){return l<a.l;}
}P[N],Q[N];
struct line{
	int k,b;
	int operator ()(int x){return k*x+b;}
};
struct SGT_node{
	int ls,rs;line a;
	int operator ()(int x){return a(x);}
}a[N*64];
void push_down(int l,int r,int rt,line c){
	int mid=(l+r)>>1;
	if(c(mid)>a[rt](mid))swap(a[rt].a,c);
	if(c(l)>a[rt](l)){
		if(a[rt].ls==0)a[a[rt].ls=++tot].a=c;
		else push_down(l,mid,a[rt].ls,c);
	}
	else if(c(r)>a[rt](r)){
		if(a[rt].rs==0)a[a[rt].rs=++tot].a=c;
		else push_down(mid+1,r,a[rt].rs,c);
	}
}
int quert(int l,int r,int rt,int x){
	if(rt==0)return -INF;
	if(l==r)return a[rt](x);
	int mid=(l+r)>>1;
	if(x<=mid)return max(a[rt](x),quert(l,mid,a[rt].ls,x));
	else return max(a[rt](x),quert(mid+1,r,a[rt].rs,x));
}
struct BIT{
	int c[N];
	int quert(int x,int ret=0){for(;x<N;x+=low(x))cmax(ret,c[x]);return ret;}
	void updata(int x,int cc){for(;x;x-=low(x))cmax(c[x],cc);}
	void clear(){memset(c,0,sizeof(c));}
}B;
struct LiChao_BIT{
	int c[N];
	void clear(){
		tot=0;memset(a,0,sizeof(a));
		for(i=1;i<N;i++){c[i]=++tot;}
	}
	void updata(int x,line cc){
		for(;x;x-=low(x))
		push_down(0,N-1,c[x],cc);
	}
	int quert(int x,int q,int ret=0){
		for(;x<N;x+=low(x))
		cmax(ret,::quert(0,N-1,c[x],q));
		return ret;
	}
}C;
void solve(){
	B.clear(),C.clear();
	j=1;P[n+1].l=INF;
	while(Q[j].l<P[1].l)j++;
	for(i=1;i<=n;i++){
		B.updata(P[i].r,P[i].x);
		while(Q[j].l<P[i+1].l&&j<=n){
			int val=B.quert(Q[j].r);
			cmax(ans,val*Q[j].x*(Q[j].r-Q[j].l+1));
			j++;
		}
	}
	j=n,Q[0].l=-INF;
	while(Q[j].l>P[n].l&&j>=1)j--;
	for(i=n;i>=1;i--){
		C.updata(P[i].r,line{P[i].x,(-P[i].l+1)*P[i].x});
		while(Q[j].l>P[i-1].l&&j>=1){
			int val=C.quert(Q[j].r,Q[j].r);
			cmax(ans,val*Q[j--].x);
		}
	}
}

signed main(){
//	freopen("party.in","r",stdin);
//	freopen("party.out","w",stdout);
	//freopen(".in","w",stdout);
//	read(n),cout<<n<<endl;
	read(n);
	for(i=1;i<=n;i++)P[i].init();
	for(i=1;i<=n;i++)Q[i].init();
	sort(P+1,P+n+1);sort(Q+1,Q+n+1);
	solve();
	swap(P,Q);
	solve();
	cout<<ans<<endl;
	return 0;
}

