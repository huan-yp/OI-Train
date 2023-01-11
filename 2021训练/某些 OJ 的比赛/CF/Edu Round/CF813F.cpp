#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=4e6+10,M=1e5+10;
int i,j,k,n,s,t,m;
int size[M],fa[M],w[M];
struct oper{
	int u,fa,v,size;
}op[N];
struct edge{
	int u,v;
	friend bool operator <(const edge &aa,const edge &bb)
	{
		if(aa.u!=bb.u)
		return aa.u<bb.u;
		return aa.v<bb.v;
	}
};
vector<edge> a[M<<2];
map <edge,int> mp;
void updata(int l,int r,int rt,int x,int y,edge e)
{
	if(x<=l&&y>=r)
	{
		a[rt].push_back(e);
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid)
	updata(l,mid,rt<<1,x,y,e);
	if(y> mid)
	updata(mid+1,r,rt<<1|1,x,y,e);
}
int find(int x)
{
	if(fa[x]==x)return x;
	return find(fa[x]);
}
int find_dis(int x)
{
	if(fa[x]==x)return 0;
	return find_dis(fa[x])+w[x];
}
int merge(int u,int v)
{
	if(find(u)==find(v)) 
	{	
		int res=(find_dis(u)+find_dis(v))%2;
		return res;
	}
	int dis=find_dis(v)+find_dis(u);
	u=find(u),v=find(v);
	if(size[u]>size[v])swap(u,v);
	op[++t]=(oper){u,fa[u],v,size[v]};
	size[v]+=size[u],fa[u]=v,w[u]=(dis%2==0);//并查集维护距离 
	return 1;	
}
void cancel(int ed)
{
	while(t>ed)
	{
		oper now=op[t--];
		fa[now.u]=now.fa;
		size[now.v]=now.size;
	}
}
void visit(int l,int r,int rt,int ok)
{
	int tmp=t;
	for(edge v:a[rt])
	{
		ok&=merge(v.u,v.v);
	}
	if(l==r)
	{
		if(ok)
		printf("YES\n");
		else
		printf("NO\n");
		cancel(tmp);
		return;	
	}
	int mid=(l+r)/2;
	visit(l,mid,rt<<1,ok);
	visit(mid+1,r,rt<<1|1,ok);
	cancel(tmp);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	fa[i]=i,size[i]=1;
	for(i=1;i<=m;i++)
	{
		edge e;
		read(e.u),read(e.v);
		if(mp.find(e)==mp.end())
		mp.insert(make_pair(e,i));
		else
		{
			updata(1,m,1,mp[e],i-1,e);
			mp.earse(mp.find(e));
		}
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	updata(1,m,1,it->second,m,it->first);
	
	visit(1,m,1,1);
	return 0;
}
