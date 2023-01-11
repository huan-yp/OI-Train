#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T>
int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(b>a)a=b;}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(b<a)a=b;}
const int N=8e5+10;
const double eps=1e-9;
int i,j,k,m,n,t,res=INF;
int b[N],top_rk[N],from[N];
vector<int> e[N];
struct Segment{
	int x1,x2,y1,y2,rk;
	void init(){
		read(x1),read(y1);read(x2),read(y2);rk=i;
		b[++m]=x1,b[++m]=y1,b[++m]=x2,b[++m]=y2;
		b[++m]=-x1,b[++m]=-y1,b[++m]=-x2,b[++m]=-y2;
	}
	double calc(int x) const{
		return 1.0*(y2-y1)/(x2-x1)*(x-x1)+y1;
	}
	friend bool operator <(const Segment &a,const Segment &b){
		return a.calc(k)+eps<=b.calc(k);
	}
	bool operator !=(const Segment &a) const{
		return rk!=a.rk;
	}
}s[N];
set<Segment> st;
struct SegmentTree{
	int a[N<<2],lazy[N<<2];
	void clear(){memset(a,31,sizeof(a));memset(lazy,31,sizeof(lazy));}
	void push_up(int rt){a[rt]=min(a[rt<<1],a[rt<<1|1]);}
	void push_down(int rt){
		if(lazy[rt]>N)return ;
		cmin(lazy[rt<<1],lazy[rt]),cmin(lazy[rt<<1|1],lazy[rt]);
		cmin(a[rt<<1],lazy[rt]),cmin(a[rt<<1|1],lazy[rt]);
		return void(lazy[rt]=INF);
	}
	void update(int l,int r,int rt,int x,int y,int c){
		if(x<=l&&y>=r)return cmin(a[rt],c),cmin(lazy[rt],c);
		int mid=(l+r)/2;push_down(rt);
		if(x<=mid)update(l,mid,rt<<1,x,y,c);
		if(y>mid)update(mid+1,r,rt<<1|1,x,y,c);
		push_up(rt);
	}	
	int quert(int l,int r,int rt,int x,int y){
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)/2,ret=INF;push_down(rt);
		if(x<=mid)cmin(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid)cmin(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
}T;
struct{
	int op,rk;
}c[N];
struct ScanLine{
	int val,op;Segment s;
	friend bool operator <(const ScanLine &a,const ScanLine &b){
		if(a.val!=b.val)return a.val<b.val;
		return a.op<b.op;
	}
}sl[N];
void top_sort(){
	queue<int> q;int cnt=0;
	for(i=1;i<=n;i++)for(auto v:e[i])from[v]++;
	for(i=1;i<=n;i++)if(!from[i])q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();top_rk[u]=++cnt;
		for(auto v:e[u])if((--from[v])==0)q.push(v);
	}
}
void solve(int type){
	st.clear();T.clear();
	for(i=1;i<=n;i++){
		sl[i<<1]={s[i].x1,s[i].x1<=s[i].x2,s[i]};
		sl[i-1<<1|1]={s[i].x2,s[i].x2<s[i].x1,s[i]};
		e[i].clear();
	}
	sort(sl+1,sl+2*n+1);
	for(i=1;i<=2*n;i++){
		if(sl[i].op){
			k=sl[i].val;	
			auto it=st.lower_bound(sl[i].s);
			if(it!=st.end())e[it->rk].push_back(sl[i].s.rk);
			if(it!=st.begin())e[sl[i].s.rk].push_back((--it)->rk);
			st.insert(sl[i].s);
		}
		else{
			int pre=st.size();
			k=sl[i].val;
			auto it=st.lower_bound(sl[i].s);
			if(*it!=sl[i].s)it--;
			st.erase(it);
			assert(pre==st.size()+1);
		}
	}
	top_sort();
	for(i=n;i>=1;i--){
		auto S=s[c[i].rk];int trk=top_rk[S.rk],_l=min(S.x1,S.x2),_r=max(S.x1,S.x2);
		int l=lower_bound(b+1,b+m+1,_l)-b,r=lower_bound(b+1,b+m+1,_r)-b-1;
		if(c[i].op==type){
			int mrk=T.quert(1,m,1,l,r);
			if(mrk<trk)cmin(res,i);
		}
		T.update(1,m,1,l,r,trk);
	}
}
int main(){
	read(n);
	for(i=1;i<=n;i++)s[i].init();
	for(i=1;i<=n;i++)read(c[i].rk),read(c[i].op);
	sort(b+1,b+m+1);m=unique(b+1,b+m+1)-b-1;
	solve(1);
	for(i=1;i<=n;i++)s[i].y1=-s[i].y1,s[i].y2=-s[i].y2;
	solve(3);
	for(i=1;i<=n;i++)swap(s[i].x1,s[i].y1),swap(s[i].x2,s[i].y2);
	solve(2);
	for(i=1;i<=n;i++)s[i].y1=-s[i].y1,s[i].y2=-s[i].y2;
	solve(0);
	auto ans=new int[N];
	cout<<res<<endl;
	for(i=1;i<=n;i++)ans[top_rk[i]]=i;
	for(i=1;i<=n;i++)printf("%d 0\n",ans[i]);	
	return 0;
}
