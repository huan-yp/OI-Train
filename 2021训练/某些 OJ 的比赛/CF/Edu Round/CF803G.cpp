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
const int N=1e6+10,M=1e5+10;
int i,j,k,n,s,t,m;
int st[M][20],lo[M];
int ask(int l,int r)
{
	int len=lo[r-l+1];
	return min(st[l][len],st[r-(1<<len)+1][len]);	
} 
struct node{
	int l,r,lazy,minu,ls,rs;
	node()
	{
		lazy=0;
	}
	friend node operator +(node aa,node bb)
	{
		node ret;
		ret.l=aa.l,ret.r=bb.r;
		ret.minu=min(aa.minu,bb.minu);
		return ret;
	}
	void construct()
	{
		if((r-1)/n==(l-1)/n)
		minu=ask((l-1)%n+1,(r-1)%n+1);
		else
		{
			if(r-l+1>=n)
			minu=ask(1,n);
			else
			minu=min(ask((l-1)%n+1,n),ask(1,(r-1)%n+1));
		}
	} 
	void get(int x)
	{
		minu=lazy=x;	
	}
};
struct Segment_Tree{
	node a[N<<4];
	void push_down(int rt)
	{
		int mid=(a[rt].l+a[rt].r)/2;
		if(a[rt].ls==0)a[rt].ls=++t,a[t].l=a[rt].l,a[t].r=mid+0,a[t].construct();
		if(a[rt].rs==0)a[rt].rs=++t,a[t].l=mid+1,a[t].r=a[rt].r,a[t].construct();
		if(a[rt].lazy==0)return;
		a[a[rt].ls].get(a[rt].lazy),a[a[rt].rs].get(a[rt].lazy);
		a[rt].lazy=0;
	}
	void push_up(int rt)
	{
		node tmp=a[rt];
		a[rt]=a[a[rt].ls]+a[a[rt].rs];	
		a[rt].ls=tmp.ls,a[rt].rs=tmp.rs;
	} 
	void updata(int l,int r,int rt,int x,int y,int c)
	{
		if(x<=l&&y>=r)
		{
			a[rt].get(c);
			return;
		}
		int mid=(l+r)/2;
		push_down(rt);
		if(x<=mid)
		updata(l,mid,a[rt].ls,x,y,c);
		if(y>mid)
		updata(mid+1,r,a[rt].rs,x,y,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)
		return a[rt].minu;
		int mid=(l+r)/2,ret=INF;
		push_down(rt);
		if(x<=mid)
		ret=min(ret,quert(l,mid,a[rt].ls,x,y));
		if(y>mid)
		ret=min(ret,quert(mid+1,r,a[rt].rs,x,y));
		return ret;
	}
}T;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)
	read(st[i][0]);
	
	for(i=1;i<=19;i++)
	for(j=1;j+(1<<i)-1<=n;j++)
	st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
	node &to =(T.a[++t]);
	to.l=1,to.r=n*k,to.minu=ask(1,n);
	for(i=1;i<=n;i++)
	lo[i]=log2(i);
	
	read(m);
	for(i=1;i<=m;i++)
	{
		int op,l,r,x;
		read(op),read(l),read(r);
		if(op==1)
		{
			read(x);
			T.updata(1,n*k,1,l,r,x);
		}
		else
		printf("%d\n",T.quert(1,n*k,1,l,r));
	}
	return 0;
}
