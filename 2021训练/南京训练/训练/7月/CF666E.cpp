#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=2000005,M=2200005;
int i,j,k,n,t=1,m,lst=1;
int pos[N],T[N],fa[M][20],ans[N][2];
char ch[N];
struct SAM{
	int ch[27],fa,len;
}s[M];
struct node{
	int ls,rs,val,rk;
	friend node operator +(const node &a,const node &b)
	{
		node ret;
		if(a.val<b.val||(a.val==b.val&&a.rk>b.rk))
		ret.val=b.val,ret.rk=b.rk;
		else
		ret.val=a.val,ret.rk=a.rk;
		return ret;
	}
}a[M<<2];
struct ask{
	int l,r,rk,val;
};
vector<ask> q[N];
vector<int> e[N];
void push_up(int rt)
{
	if(a[a[rt].ls].val>a[a[rt].rs].val||(a[a[rt].ls].val==a[a[rt].rs].val&&a[a[rt].ls].rk<a[a[rt].rs].rk))
	a[rt].val=a[a[rt].ls].val,a[rt].rk=a[a[rt].ls].rk;
	else
	a[rt].val=a[a[rt].rs].val,a[rt].rk=a[a[rt].rs].rk;
}
int merge(int u,int v)
{ 
	if(u==0)return v;
	if(v==0)return u;
	if(a[u].ls==0&&a[v].ls==0&&a[u].rs==0&&a[v].rs==0)
	{
		a[u].val+=a[v].val;
		return u;
	}
	a[u].ls=merge(a[u].ls,a[v].ls);
	a[u].rs=merge(a[u].rs,a[v].rs);
	push_up(u);
	return u;
}
node quert(int l,int r,int rt,int x,int y)
{
	if((x<=l&&y>=r)||rt==0)
	return a[rt];
	node ret;ret.val=0;int mid=(l+r)/2;
	if(x<=mid)
	ret=ret+quert(l,mid,a[rt].ls,x,y);
	if(y>mid)
	ret=ret+quert(mid+1,r,a[rt].rs,x,y);
	return ret; 
}
void add(int c)
{
	int np=++t;s[np].len=s[lst].len+1;
	while(lst&&s[lst].ch[c]==0)
	s[lst].ch[c]=np,lst=s[lst].fa;
	if(lst==0)
	s[np].fa=1;
	else
	{
		int q=s[lst].ch[c];
		if(s[q].len==s[lst].len+1)
		s[np].fa=q;
		else
		{
			int nq=++t;s[nq]=s[q];
			s[nq].len=s[lst].len+1;
			s[np].fa=s[q].fa=nq;
			while(lst&&s[lst].ch[c]==q)
			s[lst].ch[c]=nq,lst=s[lst].fa;
		}
	}
	lst=np;
}
void dfs(int u)
{
	for(int i=1;i<=19;i++)
	fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:e[u])
	{
		if(v==fa[u][0])continue;
		fa[v][0]=u;
		dfs(v);
	}
}
void dfs(int u,int fa)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		T[u]=merge(T[u],T[v]);//v ºÏ²¢µ½ u 
	}
	for(ask v:q[u])
	{
		node tmp=quert(1,m,T[u],v.l,v.r);
		if(tmp.val)
		{
			ans[v.rk][0]=tmp.val;
			ans[v.rk][1]=tmp.rk;
		}
	}
}
void updata(int l,int r,int rt,int x)
{
	if(l==r)
	{
		a[rt].val++,a[rt].rk=x;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid)
	{
		a[rt].ls=++k;
		updata(l,mid,k,x);
	}
	else
	{
		a[rt].rs=++k;
		updata(mid+1,r,k,x);
	}
	push_up(rt);
}
int query(int now,int len)
{
	for(int i=19;i>=0;i--)
	if(s[fa[now][i]].len>=len)
	now=fa[now][i];
	return now;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s",ch+1),n=strlen(ch+1);
	for(i=1;i<=n;i++)
	add(ch[i]-'a'),pos[i]=lst;
	read(m);
	for(i=1;i<=m;i++)
	{
		add(26);
		scanf("%s",ch+1);
		n=strlen(ch+1);
		for(j=1;j<=n;j++)
		add(ch[j]-'a'),T[lst]=++k,updata(1,m,T[lst],i);
	}
	for(i=1;i<=t;i++)
	e[s[i].fa].push_back(i);
	
	dfs(1);
	read(n);
	for(i=1;i<=n;i++)
	{
		int l1,l2,r1,r2;
		read(l2),read(r2),read(l1),read(r1);
		int x=query(pos[r1],r1-l1+1);
		ans[i][1]=l2;
		q[x].push_back((ask){l2,r2,i});
	}
	dfs(1,0);
	for(i=1;i<=n;i++)
	printf("%d %d\n",ans[i][1],ans[i][0]);
	
	return 0;
}

