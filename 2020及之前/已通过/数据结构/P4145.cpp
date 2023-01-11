#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long i,j,k,m,n,s,t,sum[N<<2],ans[N<<2]; 
void push_up(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	ans[rt]=max(ans[rt<<1],ans[rt<<1|1]);
} 
void build(int l,int r,int rt)
{
	if(l==r)
	{
	scanf("%lld",&sum[rt]);
	ans[rt]=sum[rt];
	return;
	}
	long long mid=(l+r)/2;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	push_up(rt);
}
void add(long long l,long long r,long long rt,long long x,long long y)
{
	if(l==r)
	{
		sum[rt]=ans[rt]=sqrt(sum[rt]);
		return;
	}
	long long mid=(l+r)/2;
	if(x<=mid&&ans[rt<<1]>1)
	add(l,mid,rt<<1,x,y);
	if(y>=mid+1&&ans[rt<<1|1]>1)
	add(mid+1,r,rt<<1|1,x,y);
	push_up(rt);
}
long long quert(long long l,long long r,long long rt,long long x,long long y) 
{
	if(l>=x&&r<=y)
	return sum[rt];
	long long ret=0;
	long long mid=(l+r)/2;
	if(x<=mid)
	ret+=quert(l,mid,rt<<1,x,y);
	if(y>=mid+1)
	ret+=quert(mid+1,r,rt<<1|1,x,y);
	return ret;
}
int main()
{
	scanf("%lld",&n);
	build(1,n,1);
	cin>>m;
	long long op,l,r;
	for(i=1;i<=m;i++)
	{
	scanf("%lld%lld%lld",&op,&l,&r);
	if(l>r)
	swap(l,r);
	if(op==0)
	add(1,n,1,l,r);
	else
	printf("%lld\n",quert(1,n,1,l,r)); 
	}
	return 0;
}

