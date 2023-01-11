#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e6+10;
int i,j,k,n,s,t,m,len;
int b[N];
struct oper{
	int op,l,r;
}a[N];
struct node{
	int res,len,l1,l0,t1,t0;
	node()
	{
		t0=t1=res=len=l1=l0=0;
	}
	friend node operator +(node aa,node bb)
	{
		node ret;
		ret.len=aa.len+bb.len;
		if(aa.l1)
		{
			if(aa.l1==aa.len)
			ret.l1=aa.l1+bb.l1;
			else
			ret.l1=aa.l1;
		}
		else
		{
			if(aa.l0==aa.len)
			ret.l0=aa.l0+bb.l0;
			else
			ret.l0=aa.l0;
		}
		return ret;
	}
	void reserve()
	{
		swap(l1,l0);
		res^=1;
	}
	void fill(int op)
	{
		if(op==0)
		l0=len,l1=0,t0=1,res=t1=0;
		else
		l1=len,l0=0,t1=1,res=t0=0;
	}
};
struct Segment_Tree{
	node a[N<<2];
	void push_up(int rt)
	{
		node tmp=a[rt];
		a[rt]=a[rt<<1]+a[rt<<1|1];	
	}	
	void push_down(int rt)
	{
		if(a[rt].t0)
		a[rt<<1].fill(0),a[rt<<1|1].fill(0);
		if(a[rt].t1)
		a[rt<<1].fill(1),a[rt<<1|1].fill(1);
		if(a[rt].res==0)return;
		a[rt<<1].reserve(),a[rt<<1|1].reserve();
		a[rt].t0=a[rt].t1=a[rt].res=0;
	}
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			a[rt].l0=1;
			a[rt].len=1;
			return;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,int y,int op)
	{
		if(x<=l&&y>=r)
		{
			if(op==1)
			a[rt].fill(1);
			if(op==2)
			a[rt].fill(0);
			if(op==3)
			a[rt].reserve();
			return;
		}
		push_down(rt);
		int mid=(l+r)/2;
		if(x<=mid)
		updata(l,mid,rt<<1,x,y,op);
		if(y>mid)
		updata(mid+1,r,rt<<1|1,x,y,op);
		push_up(rt);
		
	}
}T;
void add(int x)
{
	b[++t]=x;
	b[++t]=x+1;
	if(x-1)b[++t]=x-1;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	b[++t]=1;
	for(i=1;i<100;i++)
	b[++t]=i;
	for(i=1;i<=n;i++)
	{
		read(a[i].op),read(a[i].l),read(a[i].r);
		add(a[i].l),add(a[i].r);
	}
	sort(b+1,b+t+1);
	len=unique(b+1,b+t+1)-b-1;
	T.build(1,len,1);
	for(i=1;i<=n;i++)
	{
		a[i].l=lower_bound(b+1,b+len+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+len+1,a[i].r)-b;
		T.updata(1,len,1,a[i].l,a[i].r,a[i].op);
		printf("%lld\n",b[T.a[1].l1+1]);
	}
	return 0;
}
