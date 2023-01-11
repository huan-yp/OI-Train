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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=2e5+10;
int a[N],b[N];
struct node{
	int sum,cnt;
	node(int x=0,int y=0)
	{
		sum=x,cnt=y;
	}
	friend node operator +(const node &a,const node &b)
	{
		return (node){a.sum+b.sum,a.cnt+b.cnt};
	}
};
struct Tree{
	node  a[N<<2];
	void push_up(int rt)
	{
		a[rt]=a[rt<<1]+a[rt<<1|1];
	}
	node quert(int l,int r,int rt,int x,int y)
	{
		if(x>y)return (node){0,0};
		if(x<=l&&y>=r)return a[rt];
		int mid=(l+r)/2;node ret;
		if(x<=mid)ret=ret+quert(l,mid,rt<<1,x,y);
		if(y>mid)ret=ret+quert(mid+1,r,rt<<1|1,x,y);
		return ret;
	}
	void updata(int l,int r,int rt,int x)
	{
		if(l==r)
		{
			a[rt].cnt++,a[rt].sum+=b[x];
			return ;
		}
		int mid=l+r>>1;
		if(x<=mid)updata(l,mid,rt<<1,x);
		else updata(mid+1,r,rt<<1|1,x);
		push_up(rt);
	}
};
int i,j,k,n,s,t,m,d,ans=1e18;
Tree T;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(d);
	for(i=1;i<=n;i++)
	read(a[i]),b[i]=a[i]-d,b[i+n]=a[i];
	sort(b+1,b+n*2+1);m=unique(b+1,b+n*2+1)-b-1;
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		T.updata(1,m,1,a[i]);
	}
	for(i=1;i<=m;i++)
	{
		int sum=0;
		for(j=1;j<=n;j++)
		{
			if(b[a[j]]<b[i])
			sum+=b[i]-b[a[j]];
			if(b[a[j]]>b[i]+d)
			sum+=b[a[j]]-b[i]-d;
		}
		cmin(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}

