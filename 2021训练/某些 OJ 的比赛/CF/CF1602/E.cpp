#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define low(x) ((x)&(-x))
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
const int N=2e6+10;
int i,j,k,n,s,t,m,len;
int d[N],a[N],b[N],c[N];
struct point{
	int rk,val;
	friend bool operator <(point a,point b)
	{
		return a.val<b.val;
	}
}p[N];
struct segmentTree{
	int a[N<<2],lazy[N<<2];
	void build(int l,int r,int rt)
	{
		a[rt]=lazy[rt]=0;
		if(l==r)
		{
			a[rt]=l-1;
			return ;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void push_up(int rt)
	{
		a[rt]=min(a[rt<<1],a[rt<<1|1]);
	}
	void push_down(int rt)
	{
		if(lazy[rt]==0)return ;
		a[rt<<1]+=lazy[rt],a[rt<<1|1]+=lazy[rt];
		lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt],lazy[rt]=0;
	}
	void updata(int l,int r,int rt,int x,int y,int c)
	{
		if(x<=l&&y>=r)
		{
			a[rt]+=c;lazy[rt]+=c;
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
}T;
int quert(int x,int ret=0){for(;x>=1;x-=low(x))ret+=c[x];return ret;}
void updata(int x,int cc){for(;x<=len;x+=low(x))c[x]+=cc;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	while(tot--)
	{
		long long ans=0;
		read(n),read(m);
		for(i=1;i<=n;i++)
		read(a[i]),d[i]=a[i];
		for(i=1;i<=m;i++)
		read(b[i]),d[i+n]=b[i];
		sort(d+1,d+n+m+1),len=unique(d+1,d+n+m+1)-d-1;
		for(i=1;i<=n;i++)
		a[i]=lower_bound(d+1,d+len+1,a[i])-d,p[i].val=a[i],p[i].rk=i;
		for(i=1;i<=m;i++)
		b[i]=lower_bound(d+1,d+len+1,b[i])-d;
		for(i=1;i<=n;i++)
		{
			ans+=i-1-quert(a[i]);
			updata(a[i],1);
		}
		T.build(1,n+1,1);
		sort(p+1,p+n+1);int now=1;
		
		sort(b+1,b+m+1);
		for(i=1;i<=m;i++)
		{
			vector<int> tmp;tmp.clear();
			while(p[now].val<b[i]&&now<=n)
			{
				T.updata(1,n+1,1,p[now].rk+1,n+1,-1);
				T.updata(1,n+1,1,1,p[now].rk,1);
				now++;
			}
			while(p[now].val==b[i]&&now<=n)
			{
				T.updata(1,n+1,1,p[now].rk+1,n+1,-1);
				tmp.push_back(p[now].rk);
				now++;
			}
			ans+=T.a[1];
			while(b[i]==b[i+1]&&i<m)
			ans+=T.a[1],i++;
			for(int v:tmp)
			T.updata(1,n+1,1,1,v,1);
		}
		cout<<ans<<endl;
		for(i=1;i<=n;i++)
		updata(a[i],-1);
	}
	return 0;
}

