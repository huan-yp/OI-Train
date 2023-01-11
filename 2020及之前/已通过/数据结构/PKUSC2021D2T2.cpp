#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define int long long
#define low(x) (x)&(-x)
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
const int N=3e5+10;
int i,j,k,n,s,t,m,gap,q,sum,pos,add,cost,suf,djq;
int val[N];
struct Node{
	int sum,min,rval,lazy,sum2;
};
struct Segment_Tree{
	Node a[N<<2];
	void push_up(int rt)
	{
		a[rt].min=min(a[rt<<1].min,a[rt<<1|1].min); 
		a[rt].rval=a[rt<<1|1].rval;
		a[rt].sum=a[rt<<1].sum+a[rt<<1|1].sum;
		a[rt].sum2=a[rt<<1].sum2+a[rt<<1|1].sum2;
	}
	void push_down(int rt)
	{
		if(a[rt].lazy==0)return;
		a[rt<<1].rval+=a[rt].lazy,a[rt<<1|1].rval+=a[rt].lazy;
		a[rt<<1].lazy+=a[rt].lazy,a[rt<<1|1].lazy+=a[rt].lazy;
		a[rt<<1].min +=a[rt].lazy,a[rt<<1|1].min +=a[rt].lazy;
		a[rt].lazy=0;
	}
	void updata(int l,int r,int rt,int x,int val)
	{
		if(l==r)
		{
			a[rt].rval-=val%gap,a[rt].rval+=val/gap;
			a[rt].sum+=val;
			a[rt].min-=val%gap;
			a[rt].sum2+=val/gap;
			return ;
		}
		push_down(rt);
		int mid=(l+r)/2;
		if(x<=mid)
		{
			a[rt<<1|1].min-=val%gap-val/gap,a[rt<<1|1].rval-=val%gap-val/gap;
			a[rt<<1|1].lazy-=val%gap-val/gap;
			updata(l,mid,rt<<1,x,val);
		}
		else
		updata(mid+1,r,rt<<1|1,x,val);
		push_up(rt);
	}
	void quert(int l,int r,int rt,int val,int all,int all2)
	{
		if(l==r)
		{
			pos=l,suf=sum-all-a[rt].sum,djq=a[rt].rval-min(val,a[rt].min),cost=suf+all2+a[rt].sum2-djq;
			return ;
		}
		push_down(rt);
		int mid=(l+r)/2;
		if(a[rt<<1].rval-min(val,a[rt<<1].min)>=sum-all-a[rt<<1].sum)
		quert(l,mid,rt<<1,val,all,all2);
		else
		quert(mid+1,r,rt<<1|1,min(val,a[rt<<1].min),all+a[rt<<1].sum,all2+a[rt<<1].sum2);
	}
	//先借了足够的代金券  
}T;
int check(int x)
{
	int all=(val[pos]/gap*gap-x)/gap+djq;//已经付了零头 
	int cot=suf+x;
	return all>=cot; 
}
void solve()
{
	T.quert(1,n,1,0,0,0);
	djq-=val[pos]/gap;
	int l=0,r=djq;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check(mid))
		l=mid+1,add=mid;
		else
		r=mid-1;
	}
	printf("%lld\n",sum-add-cost);
}
signed main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(q),read(gap);
	for(i=1;i<=n;i++)
	{
		read(val[i]);
		sum+=val[i];
		T.updata(1,n,1,i,val[i]);
	}
	solve();
	for(i=1;i<=q;i++)
	{
		int x,y;
		read(x),read(y);
		T.updata(1,n,1,x,-val[x]);sum-=val[x];
		val[x]=y;
		T.updata(1,n,1,x,val[x]);sum+=val[x];
		solve();
	}
	return 0;
}
