#include<bits/stdc++.h>
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
const int N=1e5+10;
int i,s,k,n,t,m,tp1,tp2,maxn;
int head[N],dep[N],d[N],c[N],fa[N][18],p[N][3],e[N][2];
struct edge{
	int v,next;
}a[N<<1];
void work(int aa,int bb){
	a[k].next=head[aa],a[k].v=bb,head[aa]=k++;
	a[k].next=head[bb],a[k].v=aa,head[bb]=k++;
}
void dfs(int u){
	for(int i=1;i<=17;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];~i;i=a[i].next){
		int v=a[i].v;if(v==fa[u][0])continue;
		fa[v][0]=u,dep[v]=dep[u]+1;dfs(v);
	}
}
int lca(int x,int y){
	if(dep[y]>dep[x])swap(x,y);
	int p=dep[x]-dep[y];
	for(int i=0;i<=17;i++)if(1<<i&p)
	x=fa[x][i];
	if(x==y)return x;
//	for(int i=0;i=17;i++)if(fa[x][i]!=fa[y][i])
//	x=fa[x][i],y=fa[y][i];
	for(int i=17;i>=0;i--)if(fa[x][i]!=fa[y][i])
	x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
namespace dsu{
	int fa[N];
	void init(){
		for(i=1;i<=n;i++)fa[i]=i,p[i][0]=p[i][1]=i,p[i][2]=0;
	}
	int find(int x){
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	void merge(int u,int v){
		int ru=find(u),rv=find(v);
		if(p[rv][2]>p[ru][2])swap(ru,rv),swap(u,v);
		fa[rv]=ru;d[p[rv][2]]--;
		int d00=dis(p[ru][0],u),d01=dis(p[ru][1],u);
		int d10=dis(p[rv][0],v),d11=dis(p[rv][1],v);
		if(d01>d00)swap(p[ru][0],p[ru][1]),swap(d01,d00);
		if(d11>d10)swap(p[rv][0],p[rv][1]),swap(d10,d11);
		if(d10+d00+1<=p[ru][2])return ;
		d[p[ru][2]]--;p[ru][2]=d10+d00+1;
		p[ru][1]=p[rv][0];d[p[ru][2]]++;
		cmax(maxn,p[ru][2]);
	}
}
int merge(int v1,int v2){
	return max(max(v1,v2),(v1+1)/2+(v2+1)/2+1);
}
int solve(int maxn){
	int tmp[15],cnt=0;
	for(int i=maxn;i>=maxn-2&&i>=0;i--)c[i]=d[i];
	for(int i=maxn;i>=maxn-2&&i>=0;i--){
		while(c[i]--&&cnt<5)
		tmp[++cnt]=i;
	}
	for(int i=2;i<=cnt;i++)
	tmp[1]=merge(tmp[1],tmp[i]);
	return tmp[1];
}
signed main()
{
	read(t);
	while(t--){
		read(n),read(m);k=0;maxn=0;
		memset(head,-1,sizeof(int)*(n+5));
		memset(fa,0,sizeof(fa));
		memset(d,0,sizeof(int)*(n+5));d[0]=n;
		for(i=1;i<=m;i++){
			read(e[i][0]),read(e[i][1]);
			work(e[i][0],e[i][1]);
		}
		for(i=1;i<=n;i++){
			if(fa[i][0])continue;
			dep[i]=1;dfs(i);
		}
		dsu::init();
		for(i=1;i<=m;i++){
			if(s==1410){
				s=s;
			}
			dsu::merge(e[i][0],e[i][1]);
			printf("%d\n",solve(maxn));
		}
	}
	return 0;
}
