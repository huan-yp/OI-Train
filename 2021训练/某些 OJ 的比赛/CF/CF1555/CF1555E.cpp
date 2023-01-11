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
const int N=1e6+10;
struct segmentTree{
	int a[N<<2],lazy[N<<2];
	void push_up(int rt)
	{
		a[rt]=min(a[rt<<1],a[rt<<1|1]);
	}
	void push_down(int rt)
	{
		if(lazy[rt]==0)return;
		a[rt<<1]+=lazy[rt];
		a[rt<<1|1]+=lazy[rt];
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
	void updata(int l,int r,int rt,int x,int y,int c)
	{
		if(x<=l&&y>=r)
		{
			a[rt]+=c;
			lazy[rt]+=c;
			return ;
		}
		push_down(rt);
		int mid=(l+r)/2;
		if(x<=mid)
		updata(l,mid,rt<<1,x,y,c);
		if(y>mid)
		updata(mid+1,r,rt<<1|1,x,y,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)
		return a[rt];
		
		int ret=INF;int mid=(l+r)/2;	
		push_down(rt);
		if(x<=mid)
		cmin(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid)
		cmin(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
}T;
struct segment{
	int l,r,w;
	friend bool operator <(segment a,segment b)
	{
		return a.w<b.w;
	}
}a[N];
int i,j,k,n,s,t,m,ans=INF;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		read(a[i].l),read(a[i].r);
		read(a[i].w);
	}
	sort(a+1,a+n+1);
	j=0;
	for(i=1;i<=n;i++)
	{
		if(i!=1)T.updata(2,m,1,a[i-1].l+1,a[i-1].r,-1);
		while(T.a[1]==0&&j<n)
		{
			j++;
			T.updata(2,m,1,a[j].l+1,a[j].r,1);
		}
		if(T.a[1]==0)break;	
		cmin(ans,a[j].w-a[i].w);
	}
	printf("%d\n",ans);
	return 0;
}

