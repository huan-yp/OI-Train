#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=2e5+10;
int i,j,k,n,s,t,m,tp1,tp2,q;
int fa[N],sz[N],ans[N];
int e[N][2],c[N];
set<pair<int,int>> st[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
struct ask{
	int a,b,rk;
	void init(){
		read(a),read(b),rk=i;
		ans[rk]=INF;
	}
	int identify(){
		int rt=find(a);
		auto it=st[rt].upper_bound(make_pair(a,INF));
		it--;
		if(it->second>=b)cmin(ans[rk],i);
		return it->second>=b;
	}
	friend bool operator <(ask a,ask b){
		return a.b>b.b;
	}
}qry[N];
struct area{
	int l,r,time;
	friend bool operator <(area a,area b){
		return a.r>b.r;
	}
}ar[N*32];
int eq[N];
int merge_cost;
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u==v)return ;
	if(st[v].size()+eq[v]>st[u].size()+eq[u])swap(v,u);
	fa[v]=u;sz[u]+=sz[v];eq[u]+=eq[v];
	merge_cost+=eq[v]+st[v].size();
	for(auto seg:st[v]){
		auto it=st[u].lower_bound(seg);
		if(it!=st[u].end()){
			if(seg.second==it->first-1){
				auto val=*it;st[u].erase(*it);
				it=st[u].insert(make_pair(seg.first,val.second)).first;
				ar[++s]={it->first,it->second,i};
			}
			else{
				it=st[u].insert(seg).first;
			}
		}
		else{
			it=st[u].insert(seg).first;
		}
		if(it!=st[u].begin()){
			auto pre=prev(it);
			if(pre->second==it->first-1){
				auto val=*pre;st[u].erase(val);
				st[u].insert(make_pair(val.first,it->second));
				ar[++s]={val.first,it->second,i};
				st[u].erase(it);
			}
		}
	}
}
void solve(){
	for(i=1;i<=m;i++){
		int u=e[i][0],v=e[i][1];
		merge(u,v);
	}
}
void updata(int x,int cc){
	for(;x<=n;x+=x&(-x))
	cmin(c[x],cc);
}
int quert(int x,int ret=INF){
	for(;x;x-=x&(-x))
	cmin(ret,c[x]);
	return ret;
}
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(t);
	while(t--){
		s=0;
		read(n),read(m),read(q);
		for(i=1;i<=m;i++){
			read(e[i][0]),read(e[i][1]);
		}
		for(i=1;i<=n;i++){
			sz[i]=1,fa[i]=i,c[i]=m;
			st[i].clear();
			eq[i]=0;
			st[i].insert(make_pair(i,i));
		}
		for(i=1;i<=q;i++){
			qry[i].init();
			eq[qry[i].a]++;
			eq[qry[i].b]++;
			if(qry[i].a==qry[i].b)ans[i]=0;
		}
		solve();
		sort(ar+1,ar+s+1);
		sort(qry+1,qry+q+1);
		int now=0;
		for(i=1;i<=s;i++){
			updata(ar[i].l,ar[i].time);
			while((qry[now+1].b>ar[i+1].r||i==s)&&now+1<=q){
				now++;
				cmin(ans[qry[now].rk],quert(qry[now].a));
			}
		}
		for(i=1;i<=q;i++)
		cout<<ans[i]<<" ";
		cout<<endl;
	}
//	cout<<merge_cost<<endl;
	if(merge_cost>1e7)cout<<"Oh my god!!!\n";
	return 0;
}

