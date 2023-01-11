#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) (x)&(-x)
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=2e5+10;
struct edge{
	int u,v,val;
	edge(int a=0,int b=0,int c=0)
	{
		u=a,v=b,val=c;
	}
	friend bool operator <(const edge &a,const edge &b)
	{
		if(a.val!=b.val)return a.val<b.val;
		if(a.v!=b.v)return a.v<b.v;
		return a.u<b.u;
	}
};
int i,j,k,n,s,t,m,ans=1e18;
int fa[N],size[N],c[N],dfn[N],rak[N],val[N];
edge a[N<<1];
set<edge> st,e[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int quert(int x,int ret=0)
{
	for(;x>=1;x-=low(x))
	ret+=c[x];
	return ret;
}
void updata(int x,int cc)
{
	for(;x<=n;x+=low(x))
	c[x]+=cc;
}
void dfs(int u)
{
	dfn[u]=++t;size[u]=1;
	updata(dfn[u],val[u]);
	for(auto tmp:e[u])
	{
		int v=tmp.v;
		if(fa[u]==v)continue;
		fa[v]=u;dfs(v);
		size[u]+=size[v];
	}
}
void earse(int u,int fa)
{
	updata(dfn[u],-val[u]);
	for(auto tmp:e[u])
	{
		st.erase(tmp);
		int v=tmp.v;
		if(fa==v)continue;
		earse(v,u);
	}
}
void kru()
{
	for(i=1;i<=n;i++)
	fa[i]=i;
	sort(a+1,a+m+1);
	for(i=m;i>=1;i--)
	{
		int u=find(a[i].u),v=find(a[i].v);
		if(u==v)continue;
		fa[v]=u;
		e[a[i].u].insert(edge(a[i].u,a[i].v,a[i].val));
		e[a[i].v].insert(edge(a[i].v,a[i].u,a[i].val));
		st.insert(edge(a[i].u,a[i].v,a[i].val));
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	read(val[i]);
	for(i=1;i<=m;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		a[i]=(edge){x,y,z};
	}
	kru();
	fa[1]=0;dfs(1);int now=0;
	while(!st.empty())
	{
		auto it=st.begin();
		int u=it->u,v=it->v;
		if(fa[u]==v)swap(u,v);//u is father
		int val1=quert(dfn[v]+size[v]-1)-quert(dfn[v]-1),val2=quert(n)-val1;
		if(val1>val2)swap(u,v),val1=val2;//erase v
		now+=val1;cmin(ans,(it->val)-now);
		e[u].erase((edge){u,v,it->val});
		st.erase(it);earse(v,u);
	}
	if(ans<=0)
	printf("-1\n");
	else
	printf("%lld\n",ans);
	return 0;
}
