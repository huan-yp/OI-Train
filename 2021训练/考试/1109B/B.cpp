#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9'))ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e6+10;
int i,j,k,m,n,s,t,top,q;
int fa[N<<1],c[N],cnt[N],sta[N],pre[N],ans[N],f[N];
set<int> st[N];
vector<int> e[N];
struct segment{
	int l,r,rk;
	friend bool operator <(segment a,segment b){if(a.l!=b.l)return a.l<b.l;return a.r>b.r;} 
}a[N];
struct operation{
	int op,x,rk,r;
	friend bool operator <(operation a,operation b)
	{
		if(a.x!=b.x)return a.x<b.x;
		if(a.op!=b.op)return a.op<b.op;
		return a.r>b.r;
	}
}op[N<<1];
struct Tree{
	int a[N<<2];
	void push_up(int rt){a[rt]=max(a[rt<<1],a[rt<<1|1]);}
	void build(int l,int r,int rt)
	{
		if(l==r){a[rt]=pre[l];return;}
		int mid=(l+r)/2;
		build(l,mid,rt<<1),build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,int c)
	{
		if(l==r){a[rt]=c;return ;}
		int mid=(l+r)/2;
		if(x<=mid)updata(l,mid,rt<<1,x,c);
		else updata(mid+1,r,rt<<1|1,x,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)/2,ret=0;
		if(x<=mid)cmax(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid) cmax(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
}T;
int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}
void change(int x,int y)
{
	auto it=st[c[x]].find(x);
	T.updata(0,n+1,1,*next(it),*prev(it));
	st[c[x]].erase(it);
	it=st[y].lower_bound(x);
	T.updata(0,n+1,1,x,*prev(it));
	T.updata(0,n+1,1,*it,x);
	c[x]=y;st[c[x]].insert(x);
}
void ask(int x)
{
	int u=find(x);if(u==0)return ;
	if(ans[a[u].rk]!=-1)return;
	if(T.quert(0,n+1,1,a[u].l,a[u].r)<a[u].l)
	{
		ans[a[u].rk]=i;cnt[f[u]]--;
		if(cnt[f[u]]==0)
		{
			for(int v:e[f[u]])
			fa[v]=f[u];
			ask(x);
		}
	}
}
int main()
{
	memset(ans,-1,sizeof(ans));
	read(n),read(m),read(q);
	for(i=1;i<=n;i++)st[i].insert(0),st[i].insert(n+1);
	for(i=1;i<=m+n;i++)fa[i]=i;
	for(i=1;i<=n;i++)
	{
		read(c[i]);
		auto it=st[c[i]].lower_bound(i);it--;
		pre[i]=*it;st[c[i]].insert(i);
	}
	T.build(0,n+1,1);
	for(i=1;i<=m;i++)read(a[i].l),read(a[i].r),a[i].rk=i;
	sort(a+1,a+m+1);
	for(i=1;i<=m;i++)
	{
		if(T.quert(0,n+1,1,a[i].l,a[i].r)<a[i].l)
		ans[a[i].rk]=0;
		else
		{
			op[++s]=(operation){2,a[i].l,i,a[i].r};//Ñ¯ÎÊ 
			op[++s]=(operation){1,a[i].r+1,i,0};//ÐÞ¸Ä 
		}
	}
	for(i=1;i<=n;i++)
	op[++s]=(operation){3,i,0,0};
	
	sta[top=1]=0;sort(op+1,op+s+1);cnt[0]=1;
	for(i=1;i<=s;i++)
	{
		if(op[i].op==1)
		top--;
		if(op[i].op==2)
		{
			e[sta[top]].push_back(op[i].rk);
			cnt[sta[top]]++;f[op[i].rk]=sta[top];
			sta[++top]=op[i].rk;
		}
		if(op[i].op==3)
		fa[op[i].x+m]=sta[top];
	}
	for(i=1;i<=q;i++)
	{
		int x,y;read(x),read(y);
		change(x,y);
		ask(x+m);
	}
	for(i=1;i<=m;i++)if(ans[i]==-1)ans[i]=i+m;

	int opt=0;
	for(i=1;i<=m;i++)
	opt^=ans[i];
	cout<<opt<<endl;
	return 0;
}
