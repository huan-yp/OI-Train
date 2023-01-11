#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
int i,j,k,n,s,t,m;
int suf[N],pre[N],sufmax[N],preval[N];
char ch[N];
struct node{
	int a,ab,abc,bc,b,c;
	friend node operator +(const node &a,const node &b)
	{
		node ret;
		ret.a=a.a+b.a,ret.b=a.b+b.b,ret.c=a.c+b.c;
		ret.ab=min(a.a+b.ab,b.b+a.ab),ret.bc=min(a.b+b.bc,a.bc+b.c);
		ret.abc=min(a.a+b.abc,a.abc+b.c);
		cmin(ret.abc,a.ab+b.bc);
		return ret;
	}
};
struct Tree{
	node a[N<<2];
	void push_up(int rt){a[rt]=a[rt<<1]+a[rt<<1|1];}
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			if(ch[l]=='a')a[rt].a=1;
			if(ch[l]=='b')a[rt].b=1;
			if(ch[l]=='c')a[rt].c=1;
			return ;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		push_up(rt);
	}
	void updata(int l,int r,int rt,int x,char ch)
	{
		if(l==r)
		{
			a[rt].a=a[rt].b=a[rt].c=0;
			if(ch=='a')a[rt].a=1;
			if(ch=='b')a[rt].b=1;
			if(ch=='c')a[rt].c=1;
			return ;
		}
		int mid=(l+r)/2;
		if(x<=mid)updata(l,mid,rt<<1,x,ch);
		else updata(mid+1,r,rt<<1|1,x,ch);
		push_up(rt);
	}
}T;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	scanf("%s",ch+1);
	T.build(1,n,1);
	for(int ii=1;ii<=m;ii++)
	{
		int x;read(x);char cha;cin>>cha;
		T.updata(1,n,1,x,cha);
		printf("%d\n",T.a[1].abc);
	}
	return 0;
}

