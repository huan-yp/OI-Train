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
int i,j,k,n,s,m,root=1,lst=1,t=1,top=0;
int ans[N],rk[N],st[N];
char ch[N];
struct node{
	int ch[26],fa,len;
}a[N];
struct LCT{
	int son[2],fa,mx,sum,val;	
}T[N];
struct BIT{
	//单点加前缀和 
	int c[N],b[N];
	void updata(int x,int cc){b[x]+=cc;for(;x<=n;x+=low(x))c[x]+=cc;}
	int quert(int x,int ret=0){for(;x;x-=low(x))ret+=c[x];return ret;}
}B;
vector<pii> q[N];
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
void push_up(int rt){T[rt].sum=T[rt].val+T[T[rt].son[0]].sum+T[T[rt].son[1]].sum;}
void push_down(int rt){T[T[rt].son[0]].mx=T[T[rt].son[1]].mx=T[rt].mx;}
bool isroot(int rt){return T[T[rt].fa].son[0]!=rt&&T[T[rt].fa].son[1]!=rt;}
void rotate(int x)
{
	int y=T[x].fa,z=T[y].fa,o=T[y].son[1]==x,b=T[x].son[o^1];
	if(!isroot(y))T[z].son[T[z].son[1]==y]=x;
	T[y].fa=x;T[x].son[o^1]=y;T[x].fa=z,T[y].son[o]=b,T[b].fa=y;
	push_up(y),push_up(x);
}
void splay(int x)
{
	int u=x;st[++top]=u;
	while(!isroot(u))u=T[u].fa,st[++top]=u;
	while(top)push_down(st[top--]);
	
	for(int y=T[x].fa;!isroot(x);y=T[x].fa)
	{
		if(!isroot(y))rotate((T[T[y].fa].son[1]==y)==(T[y].son[1]==x)?y:x);
		rotate(x);
	}
}
void access(int x,int y=0)
{
	for(;x;y=x,x=T[x].fa)
	{
		splay(x);T[x].son[1]=y;
		push_up(x);
		B.updata(T[x].mx,-T[x].sum+(y?T[y].sum:0));
	}
	B.updata(T[y].mx=i,T[y].sum);
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
	for(i=1;i<=t;i++)
	T[i].fa=a[i].fa,T[i].mx=n+1,T[i].val=a[i].len-a[a[i].fa].len;

	for(i=n;i>=1;i--)
	{
		access(rk[i]);
 		for(auto tmp:q[i]) 
		{
			int l=tmp.first;
			ans[tmp.second]=B.quert(l);
		}
	}
	for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}

