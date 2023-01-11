#include<bits/stdc++.h>
#define int long long
#define INF 1000000000
#define y1 y3647
#define pii pair<int,int>
#define low(x) ((x)&(-x))
using namespace std;
void read(int &x){
	char ch=getchar();x=0;int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>void cmax(_type &x,const _type &y){x=max(x,y);}
template<typename _type>void cmin(_type &x,const _type &y){x=min(x,y);}
const int N=2e5+10;
int i,j,k,m,n,s,t,p;
int dep[N],fa[N][20],ans[N],pre[N],a[N],cnt[N],sid[N],sid2[N];
int sp[N],spi[N];
struct query{
	int op,l,r,rk;
	vector<int> ex1,ex2;
	friend bool operator <(const query &a,const query &b){
		return a.r<b.r;
	}
}q[N<<2]; 
struct node{
	int p,pi,i,c;
	node(int p1=0,int pi1=0,int i1=0,int c1=0){
		p=p1,pi=pi1,i=i1,c=c1;
	}
	friend node operator +(const node &a,const node &b){
		return node{a.p+b.p,a.pi+b.pi,a.i+b.i,a.c+b.c};
	}
};
struct SegmentTree{
	int a[N<<2],lazy[N<<2];
	void push_up(int rt){
		a[rt]=a[rt<<1]+a[rt<<1|1];
	}
	void push_down(int l,int r,int rt){
		if(lazy[rt]==0)return;
		int mid=(l+r)/2;
		lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
		a[rt<<1]+=lazy[rt]*(mid-l+1),a[rt<<1|1]+=lazy[rt]*(r-mid);
		lazy[rt]=0;
	}
	void updata(int l,int r,int rt,int x,int y,int c){
		if(x<=l&&y>=r){
			a[rt]+=(r-l+1)*c,lazy[rt]+=c;
			return ;
		}
		int mid=(l+r)/2;
		push_down(l,r,rt);
		if(x<=mid)updata(l,mid,rt<<1,x,y,c);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y){
		if(x>y)return 0;
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)/2,ret=0;
		push_down(l,r,rt);
		if(x<=mid)ret+=quert(l,mid,rt<<1,x,y);
		if(y>mid)ret+=quert(mid+1,r,rt<<1|1,x,y);
		return ret;
	}
	void clear(){
		memset(a,0,sizeof(a)),memset(lazy,0,sizeof(lazy));
	}
}T;
struct BIT{
	node c[N];
	void updata(int x,node cc){
		if(x==0){
			c[0]=c[0]+cc;
			return ;
		}
		for(;x<=p;x+=low(x))c[x]=c[x]+cc;
	}
	node quert(int x){
		node ret;
		for(;x;x-=low(x))ret=ret+c[x];
		return ret+c[0];
	}
	void clear(){
		memset(c,0,sizeof(c));
	}
}T2;
vector<int> e[N];
unsigned seed;
unsigned Rand(){
	seed^=seed<<13;seed^=seed>>17;
	seed^=seed<<5;return seed;
}
void AddEdge(int x,int y){
	e[x].push_back(y),e[y].push_back(x);
}
void dfs(int u){
	for(int i=1;i<=19;i++)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:e[u]){
		if(v==fa[u][0])continue;
		fa[v][0]=u,dep[v]=dep[u]+1;dfs(v);
	}
}
int lca(int x,int y){
	if(dep[y]>dep[x])swap(x,y);
	int p=dep[x]-dep[y];
	for(int i=19;i>=0;i--)
	if(1<<i&p)x=fa[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
	if(fa[x][i]!=fa[y][i])
	x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int get_line(int x,vector<int> &ex){
	if(x<=p)return x;
	ex.push_back(x);
	return get_line(fa[x][0],ex);
}
void Gen(){
	for(i=1;i<=n;i++)e[i].clear();
	std::cin >> n >> p >> seed;
	for(i=2;i<=p;i++)AddEdge(i-1,i);
	for(i=p+1;i<=n;i++)AddEdge(Rand()%(i-1)+1,i);
	for(i=1;i<=n;i++)a[i]=Rand()%n+1;
}
int ask(int x,int y,int ret=0){
	vector<int> c;c.clear();
	if(dep[y]>dep[x])swap(y,x);
	while(dep[x]!=dep[y]){
		cnt[a[x]]++;c.push_back(a[x]);
		ret+=cnt[a[x]]==1;x=fa[x][0];
	}
	while(x!=y){
		cnt[a[x]]++,c.push_back(a[x]);ret+=cnt[a[x]]==1;
		cnt[a[y]]++,c.push_back(a[y]);ret+=cnt[a[y]]==1;
		x=fa[x][0],y=fa[y][0];
	}
	cnt[a[x]]++,ret+=cnt[a[x]]==1,c.push_back(a[x]);
	while(!c.empty())cnt[c.back()]--,c.pop_back();
	return ret;
}
void process(query &qr){
	int A=qr.l,B=qr.r;
	if(qr.op==1){
		ans[qr.rk]+=T.quert(1,p,1,qr.l,qr.l);
		auto res=qr.ex1;for(auto u:qr.ex2)res.push_back(u);
		for(auto v:res){
			if(pre[a[v]]<A&&cnt[a[v]]==0)ans[qr.rk]++;
			cnt[a[v]]++;
		}
		for(auto v:res)cnt[a[v]]=0;
		return ;	
	}
	if(qr.op==3){
		ans[qr.rk]+=T.quert(1,p,1,1,B)*qr.ex2.size();int ct=0;
		for(auto u:qr.ex2){
			++ct,cnt[a[u]]++;if(cnt[a[u]]!=1)continue;
			ans[qr.rk]+=(B-pre[a[u]])*(qr.ex2.size()-ct+1);
		}
		for(auto u:qr.ex2)cnt[a[u]]--;
		return ;
	}
	int now=T.quert(1,p,1,A,A);
	for(int u:qr.ex1){
		if(pre[a[u]]<A&&cnt[a[u]]==0)now++;
		if(A!=B)cnt[a[u]]++;int tmp=now;
		for(int v:qr.ex2){
			if(A==B){
				ans[qr.rk]+=ask(u,v);
				continue;
			}
			cnt[a[v]]++;if(pre[a[v]]<A&&cnt[a[v]]==1)tmp++;
			ans[qr.rk]+=tmp;
		}
		if(A!=B)for(auto v:qr.ex2)cnt[a[v]]--;
	}
	if(A!=B)for(auto u:qr.ex1)cnt[a[u]]--;
//	
	ans[qr.rk]+=T.quert(1,p,1,1,A)*qr.ex1.size();int ct=0;
	for(auto u:qr.ex1){
		++ct,cnt[a[u]]++;if(cnt[a[u]]!=1||pre[a[u]]>=A)continue;
		ans[qr.rk]+=(A-pre[a[u]])*(qr.ex1.size()-ct+1);
	}
	for(auto u:qr.ex1)cnt[a[u]]--;
	ans[qr.rk]+=(A+B+2)*(sid[A]-sp[A])-2*sid2[A]+2*spi[A]-A;
	ans[qr.rk]-=A*(A*(B+1)-sid[A])+spi[A]-(B+1)*sp[A];
	auto res=T2.quert(A-1);
	ans[qr.rk]+=A*(res.c*(B+1)-res.i)+res.pi-res.p*(B+1);
}
void process2(query &qr){
	int B=qr.l,A=qr.r;
	if(qr.op!=2)return;	
	ans[qr.rk]+=T.quert(1,p,1,A+1,B)*qr.ex2.size();int ct=0;
	for(auto u:qr.ex2){
		++ct,cnt[a[u]]++;if(cnt[a[u]]!=1||pre[a[u]]==A)continue;
		ans[qr.rk]+=(min(pre[a[u]]-1,B)-A)*(qr.ex2.size()-ct+1);
	}
	for(auto u:qr.ex2)cnt[a[u]]--;
}
unsigned SA, SB, SC;
unsigned rng61(){
	SA ^= SA << 16;
	SA ^= SA >> 5;
	SA ^= SA << 1;
	unsigned int t = SA;
	SA = SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}
void gen(){
	for(i=1;i<=n;i++)e[i].clear();
	std::cin>>n>>p>>SA>>SB>>SC;
	for(int i = 2; i <= p; i++)
	AddEdge(i - 1, i);
	for(int i = p + 1; i <= n; i++)
	AddEdge(rng61() % (i - 1) + 1, i);
	for(int i = 1; i <= n; i++)
	a[i] = rng61() % n + 1;
}
signed main(){
//	freopen("right.in","r",stdin);
//	freopen("right.out","w",stdout);
	for(i=1;i<N;i++)sid[i]=sid[i-1]+i,sid2[i]=sid2[i-1]+i*i;
	int tot;read(tot);
	while(tot--){
		gen();dfs(1);
		memset(q,0,sizeof(q));memset(pre,0,sizeof(pre));
		T2.clear();T.clear();
		read(m);s=0;
		for(i=1;i<=m;i++){
			int op,x,y;ans[i]=0;
			read(op),read(x),read(y);
			if(op==1){
				if(lca(x,y)>p){
					ans[i]=ask(x,y);
					continue;
				} 
				int lx=get_line(x,q[++s].ex2),ly=get_line(y,q[s].ex1);
				if(lx>ly)swap(lx,ly);
				q[s].op=1,q[s].l=lx,q[s].r=ly,q[s].rk=i;
			}
			if(op==2){
				int lx=get_line(x,q[++s].ex2),ly=get_line(y,q[s].ex1);
				reverse(q[s].ex1.begin(),q[s].ex1.end());
				reverse(q[s].ex2.begin(),q[s].ex2.end());
				if(lx>ly)swap(lx,ly),swap(q[s].ex1,q[s].ex2);
				q[s].op=2,q[s].l=lx,q[s].r=ly,q[s].rk=i;
				q[++s]=q[s];q[s].op=3;q[s].r=q[s].l;
			}
		}		
		sort(q+1,q+s+1);int now=1;
		for(i=1;i<=p;i++){
			T2.updata(pre[a[i]],node{pre[a[i]],pre[a[i]]*i,i,1});
			T.updata(1,p,1,pre[a[i]]+1,i,1);
			sp[i]=sp[i-1]+pre[a[i]],spi[i]=spi[i-1]+i*pre[a[i]];
			pre[a[i]]=i;
			while(q[now].r==i&&now<=s)process(q[now++]);
		}
		T.clear();now=s;
		for(i=1;i<=s;i++)swap(q[i].l,q[i].r);
		sort(q+1,q+s+1);
		for(i=0;i<=n;i++)pre[i]=p+1;
		for(i=p;i>=1;i--){
			T.updata(1,p,1,i,pre[a[i]]-1,1);pre[a[i]]=i;
			while(q[now].r==i&&now>=1)process2(q[now--]);
		}
		for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
	}	
	return 0;
}

