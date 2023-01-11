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
const int N=4e5+10;
struct ball {
	int l,r;
	friend bool operator <(const ball &a,const ball &b)
	{
		return a.r<b.r;
	}
}a[N];
int i,j,k,n,s,t,m,lst;
int b[N];
struct segment_tree{
	int a[N<<2],lazy[N<<2];
	void push_up(int rt)
	{
		a[rt]=min(a[rt<<1],a[rt<<1|1]);	
	}
	void build(int l,int r,int rt)
	{
		lazy[rt]=0;
		if(l==r)
		{
			a[rt]=-b[l];
			return;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void push_down(int rt)
	{
		a[rt<<1]+=lazy[rt];lazy[rt<<1]+=lazy[rt];
		a[rt<<1|1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
	void updata(int l,int r,int rt,int x,int y,int c)
	{
		if(x>y)return;
		if(x<=l&&y>=r)
		{
			a[rt]+=c,lazy[rt]+=c;
			return;
		}
		int mid=(l+r)/2;
		push_down(rt);
		if(x<=mid)
		updata(l,mid,rt<<1,x,y,c);
		if(y>mid)
		updata(mid+1,r,rt<<1|1,x,y,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y)
	{
		int ret=2*INF,mid=(l+r)/2;
		if(x<=l&&y>=r)return a[rt];
		push_down(rt);
		if(x<=mid)
		cmin(ret,quert(l,mid,rt<<1,x,y));
		if(y>mid)
		cmin(ret,quert(mid+1,r,rt<<1|1,x,y));
		return ret;
	}
}T;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot;read(tot);
	while(tot--)
	{
		read(n);t=0;int all=0;
		for(i=1;i<=n;i++)
		{
			read(a[i].l),read(a[i].r);
			b[++t]=a[i].l,b[++t]=a[i].r;
		}
		sort(b+1,b+t+1),m=unique(b+1,b+t+1)-b-1;
		for(i=1;i<=n;i++)
		{
			a[i].l=lower_bound(b+1,b+m+1,a[i].l)-b;
			a[i].r=lower_bound(b+1,b+m+1,a[i].r)-b;
		}
		//b[j]~b[i] all-pre[j]>b[i]-b[j]+1
		//all-pre[j]>=b[i]-b[j]+2;
		//all-b[i]>=pre[j]-b[j]+2
		sort(a+1,a+n+1);
		T.build(1,m,1);
		int flag=0,now=1;
		
		for(i=1;i<=m;i++)
		{
			while(a[now].r==i&&now<=n)
			{
				all++;
				T.updata(1,m,1,a[now].l+1,m,1);
				now++;
			}
			int maxn=T.quert(1,m,1,1,i);
			if(all-b[i]>=maxn+2)flag=1;
		}
		if(flag)
		puts("No");
		else
		puts("Yes");
	}
	return 0;
}

