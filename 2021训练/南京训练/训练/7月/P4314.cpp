#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define int long long
#define inf 10000000000ll
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
const int N=1e5+10;
int i,j,k,n,s,t,m;
struct tg{
	int x,y;
	tg()
	{
		y=-inf;
	}//相当于定义了一种新的标记，可以支持最大值操作 
	friend tg operator +(const tg &aa,const tg &bb)
	{
		tg ret;
		ret.x=aa.x+bb.x;
		ret.y=max(aa.y+bb.x,bb.y);
		return ret;
	}
	friend int operator +(const int &aa,const tg &bb)
	{
		int ret;
		ret=max(aa+bb.x,bb.y);
		return ret;
	}
}Z;
struct node{
	int hist,maxn;
	tg h,n;
	node()
	{
		hist=maxn=-inf;
	}
	friend node operator +(const node &aa,const node &bb)
	{
		node ret;
		ret.hist=max(aa.hist,bb.hist);
		ret.maxn=max(aa.maxn,bb.maxn);
		return ret;
	}
};
struct segment_tree{
	node a[N<<2];
	tg mx(const tg &aa,const tg &bb)
	{
		tg ret;
		ret.x=max(aa.x,bb.x);
		ret.y=max(aa.y,bb.y);
		return ret;
	}
	void push_up(int rt)
	{
		a[rt].maxn=max(a[rt<<1].maxn,a[rt<<1|1].maxn);
		a[rt].hist=max(a[rt<<1].hist,a[rt<<1|1].hist);
	}
	void push_down(int rt)
	{
		a[rt<<1|0].h=mx(a[rt<<1|0].h,a[rt<<1|0].n+a[rt].h);
		a[rt<<1|1].h=mx(a[rt<<1|1].h,a[rt<<1|1].n+a[rt].h);//顺序  
		a[rt<<1].n=a[rt<<1].n+a[rt].n,a[rt<<1|1].n=a[rt<<1|1].n+a[rt].n;
		a[rt<<1|0].hist=max(a[rt<<1|0].hist,a[rt<<1|0].maxn+a[rt].h);
		a[rt<<1|1].hist=max(a[rt<<1|1].hist,a[rt<<1|1].maxn+a[rt].h);
		a[rt<<1].maxn=a[rt<<1].maxn+a[rt].n,a[rt<<1|1].maxn=a[rt<<1|1].maxn+a[rt].n;
		a[rt].h=a[rt].n=Z;
	}
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			read(a[rt].maxn);
			a[rt].hist=a[rt].maxn;
			return;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,int y,tg lazy)
	{
		if(x<=l&&y>=r)
		{
			if(lazy.x==-inf)
			{
				a[rt].hist=max(a[rt].hist,a[rt].maxn+lazy);
				a[rt].maxn=a[rt].maxn+lazy;//顺序 
				a[rt].h=mx(a[rt].h,a[rt].n+lazy);
				a[rt].n=a[rt].n+lazy;
			}
			else
			{
				a[rt].hist=max(a[rt].hist,a[rt].maxn+lazy);
				a[rt].maxn+=lazy.x;
				a[rt].h=mx(a[rt].h,a[rt].n+lazy);
				a[rt].n=a[rt].n+lazy;
			}
			return;
		}
		int mid=(l+r)/2;
		push_down(rt);
		if(x<=mid)
		updata(l,mid,rt<<1,x,y,lazy);
		if(y>mid)
		updata(mid+1,r,rt<<1|1,x,y,lazy);
		push_up(rt);
	}
	node quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)
		return a[rt];
		int mid=(l+r)/2;
		push_down(rt);
		node ret;
		if(x<=mid)
		ret=ret+quert(l,mid,rt<<1,x,y);
		if(y>mid)
		ret=ret+quert(mid+1,r,rt<<1|1,x,y);
		return ret;
	}
}T;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	Z.y=-inf;
	read(n);
	T.build(1,n,1);
	read(m);
	for(i=1;i<=m;i++)
	{
		char op[10];
		int l,r,c;
		scanf("%s",op+1);
		read(l),read(r);
		if(op[1]=='A')
		printf("%d\n",T.quert(1,n,1,l,r).hist);
		if(op[1]=='Q')
		printf("%d\n",T.quert(1,n,1,l,r).maxn);
		if(op[1]=='P')
		{
			read(c);
			tg chan;chan.x=c;
			T.updata(1,n,1,l,r,chan);
		}
		if(op[1]=='C')
		{
			read(c);
			tg chan;chan.y=c,chan.x=-inf;
			T.updata(1,n,1,l,r,chan);
		}
	}
	return 0;
}
