#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
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
int i,j,k,n,s,t,m,last;
struct node{
	int y1,y2,a,b;
	signed ls,rs;
	int calc(int x)
	{
		return a*x+b+y1+y2;
	}
	friend node operator +(const node &aa,const node &bb)
	{
		node ret;
		ret.a=aa.a+bb.a,ret.b=aa.b+bb.b;
		ret.y1=aa.y1+bb.y1,ret.y2=aa.y2+bb.y2;
		return ret;
	}
}Z;
struct Segment_Tree{
	node a[N*120];
	void updata(int l,int r,int rt1,int rt2,int x,int y,int op,int c,int b=0)
	{
		if(x<=l&&y>=r)
		{	
			if(op==1)
			a[rt2].y1+=c;
			if(op==2)
			a[rt2].a+=c,a[rt2].b+=b;
			if(op==3)
			a[rt2].y2+=c;
			return ;
		}
		int mid=(l+r)/2;
		if(x<=mid)
		{
			if(a[rt2].ls==a[rt1].ls)
			a[rt2].ls=++t,a[t]=a[a[rt1].ls];
			updata(l,mid,a[rt1].ls,a[rt2].ls,x,y,op,c,b);
		}
		if(y>mid)
		{
			if(a[rt2].rs==a[rt1].rs)
			a[rt2].rs=++t,a[t]=a[a[rt1].rs];
			updata(mid+1,r,a[rt1].rs,a[rt2].rs,x,y,op,c,b);
		}
	}
	int quert(int l,int r,int rt,int x,node now)
	{
		if(l==r)
		return (now+a[rt]).calc(x);
		int mid=(l+r)/2;
		if(x<=mid)
		return quert(l,mid,a[rt].ls,x,now+a[rt]);
		else
		return quert(mid+1,r,a[rt].rs,x,now+a[rt]);
	}
}T;
int rk[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		int x1,x2,y1,a,b,y2;
		read(x1),read(x2),read(y1);
		read(a),read(b),read(y2);
		rk[i]=++t,T.a[rk[i]]=T.a[rk[i-1]];
		T.updata(0,INF,rk[i-1],rk[i],0,x1,1,y1);
		T.updata(0,INF,rk[i-1],rk[i],x1+1,x2,2,a,b);
		T.updata(0,INF,rk[i-1],rk[i],x2+1,INF,3,y2);
	}
	read(m);
	for(i=1;i<=m;i++)
	{
		int l,r,x;
		read(l),read(r),read(x);
		x=(last+x)%INF;
		int val=T.quert(0,INF,rk[r],x,Z);
		val-=T.quert(0,INF,rk[l-1],x,Z);
		printf("%lld\n",last=val);
	}
	return 0;
}
