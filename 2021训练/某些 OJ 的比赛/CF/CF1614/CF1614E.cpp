#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define lson a[a[rt].ls]
#define rson a[a[rt].rs]
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
const int N=2e5+10,mod=1e9+2;
int i,j,k,n,s,t=1,m,ans;
struct node{
	int ls,rs,maxn,minu,lazy;
};
struct Tree{
	node a[N<<7];
	void push_up(int rt)
	{
		a[rt].maxn=rson.maxn,a[rt].minu=lson.minu;
	}
	void build(int l,int r,int rt)
	{
		int mid=(l+r)/2;
		if(a[rt].ls==0)a[rt].ls=++t,a[t].maxn=mid,a[t].minu=l;
		if(a[rt].rs==0)a[rt].rs=++t,a[t].maxn=r,a[t].minu=mid+1;
	}
	void push_down(int rt)
	{
		if(a[rt].lazy==0)return ;
		lson.lazy+=a[rt].lazy,rson.lazy+=a[rt].lazy;
		lson.maxn+=a[rt].lazy,rson.maxn+=a[rt].lazy;
		lson.minu+=a[rt].lazy,rson.minu+=a[rt].lazy;
		a[rt].lazy=0;
	}
	int find(int l,int r,int rt,int x,int op)
	{
		if(l==r)
		{
			if(op==1&&a[rt].maxn>=x)return -1;
			return l;
		}
		int mid=(l+r)/2;
		build(l,r,rt);
		push_down(rt);
		if(op==1)//最大的小于 
		{
			if(rson.minu>=x)return find(l,mid,a[rt].ls,x,op);
			else return find(mid+1,r,a[rt].rs,x,op);
		}
		else//
		{
			if(lson.maxn>x)return find(l,mid,a[rt].ls,x,op);
			else return find(mid+1,r,a[rt].rs,x,op);
		}
	}
	int quert(int l,int r,int rt,int x)
	{
		if(l==r)return a[rt].maxn;
		build(l,r,rt);push_down(rt);
		int mid=(l+r)/2;
		if(x<=mid)return quert(l,mid,a[rt].ls,x);
		else return quert(mid+1,r,a[rt].rs,x);
	}
	void updata(int l,int r,int rt,int x,int y,int c)
	{
		if(x>y)return ;
		if(x<=l&&y>=r)
		{
			a[rt].maxn+=c,a[rt].minu+=c,a[rt].lazy+=c;
			return ;
		}
		build(l,r,rt),push_down(rt);
		int mid=(l+r)/2;
		if(x<=mid)updata(l,mid,a[rt].ls,x,y,c);
		if(y>mid)updata(mid+1,r,a[rt].rs,x,y,c);
		push_up(rt);
	}
}T;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	T.a[1].minu=0,T.a[1].maxn=mod;
	for(int ii=1;ii<=n;ii++)
	{
		int x;read(x);
		read(k);
		int pos1=T.find(0,mod,1,x,1);
		int pos2=T.find(0,mod,1,x,0);
		T.updata(0,mod,1,0,pos1,1);
		T.updata(0,mod,1,pos2,mod-1,-1);
		for(i=1;i<=k;i++)
		{
			read(x);x=(x+ans)%(mod-1);ans=T.quert(0,mod,1,x);
			printf("%d\n",ans);
		}
	}
	return 0;
}
