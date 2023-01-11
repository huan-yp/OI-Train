#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
struct edge{
	int u,v,val;
	friend bool operator <(const edge &a,const edge &b){return a.val<b.val;}
};
struct query{
	int v,rk;
	friend bool operator <(const query &a,const query &b){if(a.v!=b.v)return a.v<b.v;return a.rk<b.rk;}
};
const int N=2e5+10;
int i,j,k,n,s,t,m,q;
int fa[N],siz[N],ans[N];
set<int> st[N];
set<query>op[N];
edge a[N];
int find(int x)
{
	if(fa[x]==x)return x;return fa[x]=find(fa[x]);
}
void merge(int u,int v,int val)
{
	u=find(u),v=find(v);if(u==v)return ;
	if(siz[v]>siz[u])swap(u,v);
	for(auto it=op[v].begin();it!=op[v].end();)
	{
		if(st[u].find(it->v)!=st[u].end())
		op[it->v].erase({v,it->rk}),ans[it->rk]=val,op[v].erase(it++);
		else
		{
			auto tmp=*(op[it->v].find({v,it->rk}));
			if(op[it->v].find(tmp)==op[it->v].end())printf("boom\n");
			op[it->v].erase(tmp);
			tmp.v=u;op[it->v].insert(tmp);
			op[u].insert(*it);it++;
		}
	}
	for(auto it=st[v].begin();it!=st[v].end();it++)
	{
		query search={u,-1};auto now=op[*it].upper_bound(search);
		while(now!=op[*it].end()&&now->v==u)
		{
			ans[now->rk]=val;op[*it].erase({u,now->rk});
			op[u].erase({*it,now->rk});
			now=op[*it].upper_bound(*now);
		}
		st[*it].erase(v);
		if(*it!=u)st[u].insert(*it),st[*it].insert(u);
	}
	fa[v]=u;siz[u]+=siz[v];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(ans,-1,sizeof(ans));
	read(n),read(m),read(q);
	for(i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(i=1;i<=m;i++)
	{
		read(a[i].u),read(a[i].v),read(a[i].val);
		st[a[i].u].insert(a[i].v),st[a[i].v].insert(a[i].u);
	}
	for(i=1;i<=q;i++)
	{
		int u,v;read(u),read(v);
		if(st[u].find(v)!=st[u].end())ans[i]=0;
		else op[u].insert({v,i}),op[v].insert({u,i});
	}
	sort(a+1,a+m+1);
	for(i=1;i<=m;i++)
	merge(a[i].u,a[i].v,a[i].val);
	
	for(i=1;i<=q;i++)
	printf("%d\n",ans[i]);
	return 0;
}

