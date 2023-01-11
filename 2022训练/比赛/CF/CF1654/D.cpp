#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=400005,mod=998244353;
int i,j,k,n,s,t,m,cnt,ans;
struct edge{
	int v,x,y,next; 
}a[N];
int head[N],fa[N],sz[N],son[N],zs[N],pd[N];
map<int,int> mp[N];
void init(){
	for(i=2;i<N;i++){
		if(!pd[i])zs[++cnt]=i;
		for(j=1;j<=cnt&&zs[j]*i<N;j++){
			pd[zs[j]*i]=1;
		}
	}
}
void work(int aa,int bb,int x,int y){
	a[++k].next=head[aa];head[aa]=k;a[k].v=bb,a[k].x=x,a[k].y=y;
	a[++k].next=head[bb];head[bb]=k;a[k].v=aa,a[k].x=y,a[k].y=x;
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=ret*a%mod;
		a=a*a%mod;s>>=1;
	}
	return ret;
}
void predfs(int u){
	sz[u]=1;
	for(int i=head[u];i;i=a[i].next){
		int v=a[i].v;if(fa[u]==v)continue;
		fa[v]=u,predfs(v);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])son[u]=v;	
	}
}
void insert(map<int,int> &p,int x){
	int lim=sqrt(x+1);
	for(j=1;zs[j]<=lim;j++){
		int all=0;
		while(x%zs[j]==0){
			all++,x/=zs[j];
		}
		if(all==0)continue;
		if(p.find(zs[j])==p.end())p.insert(make_pair(zs[j],all));
		else p[zs[j]]+=all;
	}
	if(x!=1){
		int all=1;
		if(p.find(x)==p.end())p.insert(make_pair(x,all));
		else p[x]+=all;
	}
}
void erase(map<int,int> &p,int x){
	int lim=sqrt(x+1);
	for(j=1;zs[j]<=lim;j++){
		int all=0;
		while(x%zs[j]==0){
			all++,x/=zs[j];
		}
		if(all==0||p.find(zs[j])==p.end())continue;
		else cmin(p[zs[j]],max(p[zs[j]]-all,0ll));
	}
	if(x!=1){
		int all=1;
		if(all==0||p.find(x)==p.end())return ;
		else cmin(p[x],max(p[x]-all,0ll));
	}
}
void dfs(int u){
	for(int i=head[u];i;i=a[i].next){
		int v=a[i].v,x=a[i].x,y=a[i].y;
		if(v!=son[u]||v==fa[u])continue;	
		dfs(v);
		swap(mp[u],mp[v]);
		int lim=sqrt(x+1);
		erase(mp[u],y);
		insert(mp[u],x);
	}
	for(int i=head[u];i;i=a[i].next){
		int v=a[i].v,x=a[i].x,y=a[i].y;
		if(v==son[u]||v==fa[u])continue;	
		dfs(v);
		erase(mp[v],y);
		insert(mp[v],x);
		for(auto tar:mp[v]){
			int val=tar.first,tot=tar.second;
			if(mp[u].find(val)==mp[u].end())mp[u].insert(make_pair(val,tot));
			else cmax(mp[u][val],tot);
		}
	}
}
void redfs(int u,int now){
	ans+=now,ans%=mod;
	for(int i=head[u];i;i=a[i].next){
		int v=a[i].v,x=a[i].x,y=a[i].y;
		if(fa[u]==v)continue;
		redfs(v,now*quick(x,mod-2)%mod*y%mod);
	}
}
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(t);
	init();
	while(t--){
		read(n);k=0;
		for(i=1;i<n;i++){
			int u,v,x,y;read(u),read(v),read(x),read(y);
			int gc=gcd(x,y);x/=gc,y/=gc;
			work(u,v,x,y);
		}
		predfs(1);
		dfs(1);
		int ini=1;ans=0;
		for(auto tar:mp[1]){
			int val=tar.first,tot=tar.second;
			ini=ini*quick(val,tot)%mod;
		}
		redfs(1,ini);
		cout<<ans<<endl;
		for(i=1;i<=n;i++)son[i]=0,head[i]=0,sz[i]=0;
		for(i=0;i<=n;i++)mp[i].clear();
	}
	return 0;
}


