#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e5+10;
int i,j,k,n,s,t,m,q,ans,base;
int a[N],b[N];
struct Tree{
	int a[N<<2],sum[N<<2],lazy[N<<2];
	void push_up(int rt)
	{
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
		a[rt]=min(a[rt<<1],a[rt<<1|1]);
	}
	void push_down(int l,int r,int rt)
	{
		if(lazy[rt]==0)return ;
		int mid=(l+r)/2;
		lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
		a[rt<<1]+=lazy[rt],a[rt<<1|1]+=lazy[rt];
		sum[rt<<1]+=lazy[rt]*(mid-l+1),sum[rt<<1|1]+=lazy[rt]*(r-mid);
		lazy[rt]=0;
	}
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			a[rt]=sum[rt]=b[r]-b[r-1];
			return ;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,int y,int c)
	{
		if(x<=l&&y>=r)
		{
			sum[rt]+=c*(r-l+1),lazy[rt]+=c,a[rt]+=c;
			return ;
		}
		int mid=(l+r)/2;
		push_down(l,r,rt);
		if(x<=mid)updata(l,mid,rt<<1,x,y,c);
		if(y>mid)updata(mid+1,r,rt<<1|1,x,y,c);
		push_up(rt);
	}
	int quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)return sum[rt];
		int mid=(l+r)/2,ret=0;push_down(l,r,rt);
		if(x<=mid)ret+=quert(l,mid,rt<<1,x,y);
		if(y>mid)ret+=quert(mid+1,r,rt<<1|1,x,y);
		return ret;
	}
	int find(int l,int r,int rt,int x)
	{
		if(l==r)return l;
		int mid=(l+r)/2;push_down(l,r,rt);
		if(a[rt<<1|1]>x)return find(l,mid,rt<<1,x);
		else return find(mid+1,r,rt<<1|1,x);
	}
}T;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(q);
	for(i=1;i<=n;i++)read(a[i]);base+=a[1]*(n+m-1);
	for(j=1;j<=m;j++)read(b[j]);base+=b[1]*(n+m-1);
	b[0]=b[1];a[0]=a[1];
	for(i=n;i>=1;i--)a[i]=a[i]-a[i-1];
	T.build(1,m,1);
	for(i=1;i<=m;i++)base+=(b[i]-b[i-1])*(m-i+1);
	for(int ii=1;ii<=q;ii++)
	{
		int type,d,k,ans=0;
		read(type),read(k),read(d);
		if(type==1)
		{
			for(i=n-k+1;i<=n;i++)a[i]+=d;
			if(k==n)base+=d*(n+m-1);
		}
		else
		{
			T.updata(1,m,1,m-k+1,m,d);
			base+=d*k*(k+1)/2;
		}
		for(i=2;i<=n;i++)
		{
			int pos=T.find(1,m,1,a[i])+1;	
			ans+=((m-pos+1)+n-i+1)*a[i]+T.quert(1,m,1,1,pos-1);
		}
		cout<<ans+base<<endl;
	}
	return 0;
}

