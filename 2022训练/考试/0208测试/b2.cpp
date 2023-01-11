#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
#define low(x) ((x)&(-x))
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
const int N=4e5+10;
int i,j,k,n,s,m,lst=1,t=1;
int rak[N],size[N],son[N],dfn[N],dep[N],top[N],fa[N];
int ans[N],rk[N];
char ch[N];
struct node{
	int ch[26],fa,len;
}a[N];
struct BIT{
	//单点加前缀和 
	int c[N],b[N];
	void updata(int x,int cc){b[x]+=cc;for(;x<=n;x+=low(x))c[x]+=cc;}
	int quert(int x,int ret=0){for(;x;x-=low(x))ret+=c[x];return ret;}
}B;
vector<int> pre[N],e[N];
vector<pii> q[N];
stack<pii> st[N];
//stack 维护一条重链上所有的断点，有位置和颜色两个值 
void add(int x)
{
	int p=rk[i]=++t;a[p].len=a[lst].len+1;
	while(!a[lst].ch[x]&&lst)a[lst].ch[x]=p,lst=a[lst].fa;
	if(lst==0){a[lst=p].fa=1;return ;}
	int q=a[lst].ch[x];
	if(a[q].len==a[lst].len+1)a[p].fa=q;
	else
	{
		int np=++t;a[np]=a[q];a[np].len=a[lst].len+1;
		a[p].fa=a[q].fa=np;
		while(lst&&a[lst].ch[x]==q)a[lst].ch[x]=np,lst=a[lst].fa;
	}
	lst=p;
}
void predfs(int u)
{
	size[u]=1;
	for(int v:e[u])
	{
		fa[v]=u,predfs(v);size[u]+=size[v];
		if(size[v]>size[son[u]])son[u]=v;
	}
}
void redfs(int u)
{
	dfn[u]=++s,rak[s]=u;int sum=a[u].len-a[a[u].fa].len;
	if(son[fa[u]]==u)
	{
		int &v=top[u];v=top[fa[u]],dep[u]=dep[fa[u]]+1;
		pre[v].push_back(*pre[v].rbegin()+sum);
	}
	else pre[u].push_back(sum),dep[u]=0,top[u]=u;
	
	if(son[u])redfs(son[u]);
	for(int v:e[u])
	{
		if(son[u]==v)continue;
		redfs(v);
	}
}
void activate(int u)
{
	if(u==0)return ;int lst=-1,tp=top[u];auto &s=st[tp];
	for(;;)
	{
		if(s.empty())break;
		auto tmp=s.top();
		if(tmp.first>dep[u])
		{
			B.updata(tmp.second,(lst==-1?0:pre[tp][lst])-pre[tp][dep[u]]);
			break;
		}
		B.updata(tmp.second,(lst==-1?0:pre[tp][lst])-pre[tp][tmp.first]);
		lst=tmp.first;s.pop();
	}
	s.push(make_pair(dep[u],i));
	B.updata(i,pre[tp][dep[u]]);
	activate(fa[top[u]]);
}
signed main()
{
	//freopen("b.in","r",stdin);
	//freopen("b.out","w",stdout);
	scanf("%s",ch+1);n=strlen(ch+1);read(m);
	for(i=n;i>=1;i--)
	add(ch[i]-'a');
	
	for(i=1;i<=m;i++)
	{
		int l,r;read(l),read(r);
		q[l].push_back(make_pair(r,i));
	}
	for(i=1;i<=t;i++)e[a[i].fa].push_back(i);
	
	predfs(1),redfs(1);
	
	for(i=n;i>=1;i--)
	{
		activate(rk[i]);
 		for(auto tmp:q[i]) 
		{
			int l=tmp.first;
			ans[tmp.second]=B.quert(l);
		}
	}
	for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}

