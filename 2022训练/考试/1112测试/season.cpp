#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=8e5+10;
int n,m,cnt;
int fa[N],id[N],cl[N];
LL ans;
vector<tuple<int,int,int>> e[N];
struct Data{
	int col;LL minu;
	Data(int c=0,LL m=1e18){col=c,minu=m;}
	bool operator <(const Data &a)const{return minu<a.minu;}
	bool operator >(const Data &a)const{return minu>a.minu;}
	bool operator ==(const Data &a)const{return col==a.col;}
}f[N];
struct node{
	Data mi[2];
	node(int c=0,LL m=1e18){
		mi[0]=Data(c,m);
		mi[1]=Data(-1,1e18);
	}
	friend node operator +(const node &a,node b){
		node res=a;
		if(b.mi[0]<res.mi[0])swap(b.mi[0],res.mi[0]);
		if(res.mi[0]==res.mi[1])res.mi[1]=b.mi[1];
		if(!(res.mi[0]==b.mi[0])&&res.mi[1]>b.mi[0])res.mi[1]=b.mi[0];
		if(!(res.mi[0]==b.mi[1])&&res.mi[1]>b.mi[1])res.mi[1]=b.mi[1];
		return res;
	}
	node& operator +=(const node &a){return *this=*this+a;}
	node& operator +=(const LL &a){this->mi[0].minu+=a,this->mi[1].minu+=a;return *this;}
	Data operator ()(int col){return mi[0].col!=col?mi[0]:mi[1];}
};
struct SGT{
	node a[N<<2];
	LL lazy[N<<2];
	void push_down(int rt){
		if(lazy[rt]==0)return ;
		lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
		a[rt<<1]+=lazy[rt],a[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
	void push_up(int rt){a[rt]=a[rt<<1|1]+a[rt<<1];}
	void updata(int l,int r,int rt,int x,int y,int c){
		if(x<=l&&y>=r){
			a[rt]+=c,lazy[rt]+=c;
			return ;
		}
		int mid=(l+r)/2;push_down(rt);
		if(x<=mid)updata(l,mid,rt<<1,x,y,c);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y,c);
		push_up(rt);
	}
	void build(int l,int r,int rt){
		lazy[rt]=0;
		if(l==r)return void(a[rt]=node(id[l],0));
		build(l,l+r>>1,rt<<1),build((l+r>>1)+1,r,rt<<1|1);
		push_up(rt);
	}
}T;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(int a,int b,int c,int d,int w){
	e[a].emplace_back(c,d,w);
	e[b+1].emplace_back(c,d,-w);
}
void ___solve(){
	int i,j;
	read(n),read(m),cnt=n;
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++){
		int a,b,c,d,w;
		read(a),read(b),read(c),read(d),read(w);
		add(a,b,c,d,w);
		add(c,d,a,b,w);
	}
	while(cnt!=1){
		int sum=0;
		for(i=1;i<=n;i++)if(fa[i]==i)id[i]=++sum,cl[sum]=i;
		for(i=1;i<=n;i++)id[i]=id[find(i)];
		for(i=1;i<=n;i++)f[i]=Data(-1,1e18);
		T.build(1,n,1);
		for(i=1;i<=n;i++){
			for(auto [l,r,w]:e[i])
			T.updata(1,n,1,l,r,w);
			cmin(f[id[i]],T.a[1](id[i]));
		}
		for(i=1;i<=sum;i++){
			int v=cl[f[i].col];
			if(find(v)!=find(cl[i])){
				fa[find(v)]=find(cl[i]);
				ans+=f[i].minu;
				cnt--;
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
 	freopen("season.in","r",stdin);
	freopen("season.out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


