#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<class _type1,class _type2>void cmax(_type1 &a,const _type2 &b){if(b>a)a=b;}
template<class _type1,class _type2>void cmin(_type1 &a,const _type2 &b){if(b<a)a=b;}
const int N=2000005; 
void read(int &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
int i,j,k,m,n,s,t,rt,two;
LL ans;
int fa[N],sz[N],cnt[N],maxn[N],head[N];
struct {
	int next,v;
}a[N<<1];
void work(int aa,int bb){
	a[++k].next=head[aa],head[aa]=k,a[k].v=bb;
	a[++k].next=head[bb],head[bb]=k,a[k].v=aa;
}
void predfs(int u){
	sz[u]=1;
	for(int i=head[u];i;i=a[i].next){
		int v=a[i].v;if(v==fa[u])continue;
		fa[v]=u,predfs(v);sz[u]+=sz[v];	
		cmax(maxn[u],sz[v]);
	}
	cmax(maxn[u],n-sz[u]);
	if(maxn[u]<maxn[rt])rt=u;
}
void dfs(int u,int op=1){
	sz[u]=1;
	for(int i=head[u];i;i=a[i].next){
		int v=a[i].v;
		if(v==fa[u])continue;
		fa[v]=u,dfs(v,op);sz[u]+=sz[v];
	}	
	cnt[sz[u]]+=op;
}
void redfs(int u){
	for(int i=head[u];i;i=a[i].next){
		int v=a[i].v;
		if(fa[u]==v)continue;
		redfs(v);
	}	
	if(n%2)ans+=1ll*sz[u]*(n-sz[u]);
	else ans+=1ll*sz[u]*(n-sz[u]-cnt[n/2-sz[u]]*(n/2-sz[u]));
}
void calc(int u){
	for(int i=head[u];i;i=a[i].next){
		int v=a[i].v;
		if(fa[u]==v)continue;
		calc(v);
	}
	if(u!=rt&&u!=fa[rt])ans+=1ll*sz[u]*(n/2-cnt[n/2-sz[u]]*(n/2-sz[u]));
}
int main(){
	//freopen("lcc.in","r",stdin);
	//freopen("lcc.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n);
	maxn[0]=INF;
	for(i=1;i<n;i++){
		int x,y;read(x),read(y);
		work(x,y);
	}
	predfs(1);if(sz[rt]==n/2&&n%2==0)two=1;
	if(!two){
		fa[rt]=0;dfs(rt);
		for(int i=head[rt];i;i=a[i].next){
			int x=a[i].v;
			dfs(x,-1);
			redfs(x);
			dfs(x,1);
		}
	}
	else{
		fa[fa[rt]]=rt;
		dfs(fa[rt]);calc(rt);
		memset(cnt,0,sizeof(cnt));
		dfs(rt);calc(fa[rt]);
	}
	cout<<ans<<endl;
	return 0;
}

