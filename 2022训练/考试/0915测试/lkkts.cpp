#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline int read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 &b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 &b){if(a<b)a=b;}
const int N=1e5+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int son[N],rak[N],top[N],fa[N],dfn[N],dep[N],v1[N],v2[N],v3[N],sz[N],a[N];
vector<int> e[N];
struct mdf{
	int m=1,a=0;
	friend int operator +(const int &x,const mdf &a){return (1ll*x*a.m+a.a)%mod;}
	friend int operator +=(int &x,const mdf &a){return x=(1ll*x*a.m+a.a)%mod;}
	friend mdf operator +(const mdf &a,const mdf &b){return mdf{1ll*a.m*b.m%mod,(1ll*a.a*b.m+b.a)%mod};}
	mdf operator +=(const mdf &b){return (*this)=mdf{1ll*m*b.m%mod,(1ll*a*b.m+b.a)%mod};}
};
struct SGT{
	mdf lazy[N<<2];int a[N<<2];
	void init(int in=1){for(int i=0;i<N<<2;i++)a[i]=in;}
	void modify(int rt,const mdf &c,int len){a[rt]=(1ll*a[rt]*c.m+1ll*len*c.a)%mod;lazy[rt]+=c;}
	void push_up(int rt){a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;}
	void push_down(int l,int r,int rt){
		if(lazy[rt].m==1&&lazy[rt].a==0)return ;int mid=l+r>>1;
		modify(rt<<1,lazy[rt],mid-l+1);
		modify(rt<<1|1,lazy[rt],r-mid);
		lazy[rt].m=1,lazy[rt].a=0;
	}
	void updata(int l,int r,int rt,int x,int y,const mdf &c){
		if(x>y)return ;
		if(x<=l&&y>=r){modify(rt,c,r-l+1);return ;}
		push_down(l,r,rt);int mid=l+r>>1;
		if(x<=mid)updata(l,mid,rt<<1,x,y,c);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y,c);
	}
	int quert(int l,int r,int rt,int x){
		if(l==r)return a[rt];
		push_down(l,r,rt);int mid=l+r>>1;
		if(x<=mid)return quert(l,mid,rt<<1,x);
		else return quert(mid+1,r,rt<<1|1,x);
	}
}T1,T2,T3;
void dfs1(int u){
	sz[u]=1;
	for(auto v:e[u]){
		if(fa[u]==v)continue;
		fa[v]=u,dep[v]=dep[u]+1;dfs1(v);
		sz[u]+=sz[v];if(sz[v]>sz[son[u]])son[u]=v;
	}
}
void dfs2(int u){
	dfn[u]=++t,rak[t]=u;
	if(son[fa[u]]==u)top[u]=top[fa[u]];
	else top[u]=u;
	if(son[u])dfs2(son[u]);
	for(auto v:e[u]){
		if(v==fa[u]||v==son[u])continue;
		dfs2(v);
	}
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
void visit(int l,int r,int rt){
	if(l==r){
		v1[rak[l]]=T1.a[rt];
		v2[rak[l]]=T2.a[rt];
		v3[rak[l]]=T3.a[rt];
		return ;
	}
	int mid=l+r>>1;
	T1.push_down(l,r,rt);T2.push_down(l,r,rt);T3.push_down(l,r,rt);
	visit(l,mid,rt<<1),visit(mid+1,r,rt<<1|1);
}
void update(int u,mdf c1,mdf c2){
	int iv=quick(c2.m,mod-2);
	int lst=0;
	while(u){
//		for(auto v:e[u])if(v!=fa[u]&&v!=lst)
//		a[v]+=c2;
//		a[lst=u]+=c1;u=fa[u];
		if(u!=1){
			int mul=T2.quert(1,n,1,dfn[fa[top[u]]]),mul2=mul+c2;
			int time=T3.quert(1,n,1,dfn[fa[top[u]]]);
			int res=T1.quert(1,n,1,dfn[top[u]]);
			if(c2.m!=mod){
				int im=quick(mul2,mod-2);
				if(time>a[top[u]])res=1ll*c1.a*im%mod;
				else res=1ll*((1ll*res*mul%mod)+c1)*im%mod;
				T1.updata(1,n,1,dfn[top[u]],dfn[top[u]],mdf{0,res});
			}
			else{
				int im=quick(mul,mod-2);
				if(time>a[top[u]])res=1ll*c1.a%mod;
				else res=1ll*((1ll*res*mul%mod)+c1)%mod;
				T1.updata(1,n,1,dfn[top[u]],dfn[top[u]],mdf{0,res});
			}
			a[top[u]]=i;
		}
		T1.updata(1,n,1,dfn[top[u]]+1,dfn[u],c1);
		if(c2.m!=mod)T2.updata(1,n,1,dfn[top[u]],dfn[u],c2);
		else{
			T3.updata(1,n,1,dfn[top[u]],dfn[u],{0,i});
			T2.updata(1,n,1,dfn[top[u]],dfn[u],{0,1});
		}
		if(top[rak[dfn[u]+1]]==top[u])
		T1.updata(1,n,1,dfn[u]+1,dfn[u]+1,c2);
		u=fa[top[u]];
	}
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n),read(m);int f=0;
	for(i=2;i<=n;i++)e[read(f)].push_back(i);
	dfs1(1);dfs2(1);T2.init();
	for(i=1;i<=m;i++){
		int u,c,p;
		read(u),read(c),read(p);
		update(u,mdf{mod+1-p,1ll*c*p%mod},mdf{mod+1-p,0});
		int ans1=0,ans2=0;
	}
	int ans1=0,ans2=0;
	visit(1,n,1);
	for(i=2;i<=n;i++){
	//	int ans=a[i];
		int ans=v1[i];
		if(top[i]==i)ans=1ll*ans*v2[fa[i]]*(a[i]>=v3[fa[i]])%mod;
		ans1=(ans1+ans)%mod,ans2=(ans2+1ll*ans*i)%mod;
	}
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}
