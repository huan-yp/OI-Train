#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long i,j,k,m,n,s,t,lazy[N<<2],sum[N<<2],js;
long long a[N]; 
void push_up(long long rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void push_down(long long l,long long r,long long rt)
{
	if(lazy[rt]!=0&&l!=r)
	{
		long long mid=(l+r)/2;
		sum[rt<<1]+=(mid-l+1)*lazy[rt];
		sum[rt<<1|1]+=(r-mid)*lazy[rt]; 
	}
	if(lazy[rt]!=0&&l!=r)
	{
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
	}
	lazy[rt]=0;
} 
void build(long long l,long long r,long long rt)
{
	if(l==r)
	{
		sum[rt]=a[l]-a[l-1]; 
		return;
	}
	long long mid=(l+r)/2;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1); 
	push_up(rt);
}
void add(long long l,long long r,long long rt,long long c,long long x,long long y)
{
	if(l>=x&&r<=y)
	{
		sum[rt]+=c*(r-l+1);
		lazy[rt]+=c;
		return;
	}
	long long mid=(l+r)/2;
	push_down(l,r,rt); 
	if(x<=mid)
	add(l,mid,rt<<1,c,x,y);
	if(y>=mid+1)
	add(mid+1,r,rt<<1|1,c,x,y);
	push_up(rt);
}
long long quert(long long l,long long r,long long rt,long long x,long long y)
{
	if(l>=x&&r<=y)
	return sum[rt];
	long long mid=(l+r)/2;
	push_down(l,r,rt);
	long long ret=0;
	if(x<=mid)
	ret+=quert(l,mid,rt<<1,x,y);
	if(y>=mid+1)
	ret+=quert(mid+1,r,rt<<1|1,x,y);
	return ret;
}
int main()
{
//	freopen("P1438_1.in","r",stdin);
//	freopen("P1438_1.ans","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	build(1,n,1);
	long long op;
	for(i=1;i<=m;i++)
	{
		long long l,r;
		scanf("%lld",&op);
		if(op==1)
		{
		long long d;
		scanf("%lld%lld%lld%lld",&l,&r,&k,&d);
		add(1,n,1,k,l,l);
		if(l!=r&&l!=n)
		add(1,n,1,d,l+1,r);
		if(r!=n)
		add(1,n,1,-k-(r-l)*d,r+1,r+1);//因为分的时候x,y必须在l,r内，所以有上面的if 
		}
		else
		{
			js++;			
		scanf("%lld",&l);
		printf("%lld\n",quert(1,n,1,1,l)); 
		}
	}
	return 0;
 } 
