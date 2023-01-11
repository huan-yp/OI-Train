#include<bits/stdc++.h>
#define y1 y3647
#define INF ((1<<30)+5)
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
const int N=1e5+10,D=30,Q=15;
int n,m;
long long time_con;
int fa[N][2],in[N];
vector<pii> e[N];
struct Trie01{
	int a[N<<5][2],tot=1;
	vector<int> v;
	void add(int x,int dep=D,int u=1){
		while(dep){
			int o=bool(1<<--dep&x);
			if(!a[u][o])a[u][o]=++tot;
			u=a[u][o];
		}
		a[u][0]=x;
		v.push_back(x);
	}
	int lower_bound(int x,int val,int dep=D,int u=1){
		int last=0,ld=0;
		while(dep&&u){
			int o=bool(1<<--dep&x),l=bool(1<<dep&val);
			if(!l&&a[u][o^1])last=a[u][o^1],ld=dep;
			u=a[u][o^l];
		}	
		if(u!=0)return a[u][0]^x;
		if(last==0)return INF;u=last;
		
		while(ld){
			if(a[u][bool(1<<--ld&x)])u=a[u][bool(1<<ld&x)];
			else u=a[u][bool(1<<ld&x)^1];
		}
		return a[u][0]^x;
	}
	void clear(){memset(a,0,sizeof(int)*(tot+5)*2);tot=1;v.clear();}
}T;
struct Query{
	int l,r,x,y,mid,ans,rk;
	bool operator <(const Query &a) const{
		return mid<a.mid;
	}
}q[Q];
void _dfs(int u){
	for(auto [v,w]:e[u]){
		if(v==*fa[u])continue;
		fa[v][0]=u,fa[v][1]=w;_dfs(v);
	}
}
void dfs(int u,vector<int>& res,int val,int f=0){
	res.push_back(val);
	for(auto [v,w]:e[u]){
		if(v==f||v==*fa[u])continue;
		dfs(v,res,val^w);
	}
}
bool check0(int l,int r){
	T.clear();vector<int> ve;
	if(l==0)return true;
	int minu=INF;T.add(0);
	for(auto [v,w]:e[0]){
		dfs(v,ve,w);
		for(auto w:ve){
			cmin(minu,T.lower_bound(w,l));
			if(minu<=r)return 1;
		}
		for(auto w:ve)T.add(w);
	}
	return minu<=r;
}
int jump(int u,int &s,int &t,int &xs){
	if(in[u])return 1;
	int ini=u,f=0;
	while(!in[u])
	f=u,in[u]=1,xs^=fa[u][1],u=*fa[u];					
	if(u!=s&&u!=t)return -1;
	if(u==s)s=ini;
	else t=ini;
	return f;
}
void ___solve(){
	int i,j;
	read(n),read(m);
	for(i=1;i<n;i++){
		int x,y,z;read(x),read(y),read(z);
		e[x].emplace_back(y,z),e[y].emplace_back(x,z);
	}
	_dfs(0);
	for(i=1;i<=m;i++){
		read(q[i].x),read(q[i].y),q[i].rk=i;
		if(check0(q[i].x,q[i].y))
		q[i].l=2,q[i].r=n;
		else
		q[i].l=1,q[i].r=0;
	}
	for(int check=0;check<=18;check++){
		memset(in,0,sizeof(in));in[0]=1;
		for(i=1;i<=m;i++)q[i].mid=(q[i].l+q[i].r)/2;
		sort(q+1,q+m+1);
		int lst=2,s=0,t=0,xs=0,f=jump(1,s,t,xs),flag=0;
		for(i=1;i<=m;i++){
			if(q[i].l>q[i].r)continue;
			T.clear();int minu=INF;
			while(lst<q[i].mid&&!flag){
				if(jump(lst++,s,t,xs)==-1)flag=1;
			}
			if(flag){
				q[i].r=q[i].mid-1;
				continue;	
			}
			vector<int> v1,v2;
			dfs(s,v1,0,f),dfs(t,v2,0,f);
			for(auto w:v1)T.add(w);
			for(auto w:v2)cmin(minu,T.lower_bound(xs^w,q[i].x));
			if(minu<=q[i].y)q[i].ans=q[i].mid,q[i].l=q[i].mid+1;
			else q[i].r=q[i].mid-1;
		}
	}
	sort(q+1,q+m+1,[](const Query &a,const Query &b){return a.rk<b.rk;});
	for(i=1;i<=m;i++)cout<<q[i].ans<<endl;
}
signed main()
{
	int tot=1;
	while(tot--){
		___solve();
	}
	return 0;
}

