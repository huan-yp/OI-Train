#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define LNF 1000000000000000000ll
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
const int N=2e5+10;
int i,j,k,n,s,t,m;
struct Segment_Tree{
	int a[N<<2],lazy[N<<2];
	Segment_Tree()
	{
		for(int i=0;i<N<<2;i++)
		a[i]=-LNF;
	}
	void push_up(int rt)
	{
		a[rt]=max(a[rt<<1],a[rt<<1|1]);
	}
	void push_down(int rt)
	{
		if(lazy[rt]==0)return;
		a[rt<<1]+=lazy[rt],a[rt<<1|1]+=lazy[rt];
		lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
	void updata(int l,int r,int rt,int x,int y,int c,int op)
	{
		if(x<=l&&y>=r)
		{
			if(op==1)
			a[rt]+=c,lazy[rt]+=c;
			else
			a[rt]=c;
			return;
		}
		push_down(rt);
		int mid=(l+r)/2;
		if(x<=mid)
		updata(l,mid,rt<<1,x,y,c,op);
		if(y>mid)
		updata(mid+1,r,rt<<1|1,x,y,c,op);
		push_up(rt);
	}
}T;
struct line{
	int l,r,val;
	friend bool operator <(line aa,line bb)
	{
		return aa.r<bb.r;
	}
}a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	read(a[i].l),read(a[i].r),read(a[i].val);

	sort(a+1,a+m+1);
	int now=1;
	for(i=1;i<=n;i++)
	{
		int val=max(T.a[1],0ll);
		T.updata(1,n,1,i,i,val,0);
		while(a[now].r==i)
		T.updata(1,n,1,a[now].l,i,a[now].val,1),now++;
	}
	int ans=0;
	ans=max(ans,T.a[1]);
	cout<<ans;
	return 0;
}
