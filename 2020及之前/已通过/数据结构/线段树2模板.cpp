#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long i,j,k,m,n,s,t,mod;
long long a[N<<2],lazy1[N<<2],lazy2[N<<2];//lazy表示未操作,先乘再加 ,1加2乘 
void getright(long long rt,long long l,long long r)
{
	a[rt]*=lazy2[rt];
	a[rt]+=lazy1[rt]*(r-l+1);
	a[rt]%=mod;
}
void push_down(long long rt)
{
	lazy1[rt<<1]*=lazy2[rt];
	lazy2[rt<<1]*=lazy2[rt];
	lazy1[rt*2+1]*=lazy2[rt];
	lazy2[rt*2+1]*=lazy2[rt]; 
	lazy1[rt<<1]+=lazy1[rt];
	lazy1[rt*2+1]+=lazy1[rt];
	lazy1[rt]=0;
	lazy2[rt]=1; 
	lazy1[rt<<1]%=mod; 
	lazy2[rt<<1]%=mod; 
	lazy1[rt<<1|1]%=mod; 
	lazy2[rt<<1|1]%=mod; 
}
void push_up(long long rt)
{
	a[rt]=(a[rt<<1]+a[rt*2+1])%mod;
}
void getnow(long long l,long long r,long long rt)
{
	getright(rt,l,r);
	if(l!=r)
	push_down(rt);
	else
	{
		lazy1[rt]=0;
		lazy2[rt]=1;
	 } 
} 
void build(long long l,long long r,long long rt)
{
	if(l==r)
	{
	scanf("%lld",&a[rt]);
	return;
	}
	long long mid=(l+r)/2;
	build(l,mid,rt<<1);
	build(mid+1,r,rt*2+1);
	push_up(rt);
} 
void add1(long long l,long long  r,long long rt,long long c,long long x,long long y)
{
	getnow(l,r,rt);
	if(x<=l&&y>=r)
	{
		lazy1[rt]+=c;
		getnow(l,r,rt);
		return;
	}
	long long mid=(l+r)/2;
	if(x<=mid)
	add1(l,mid,rt<<1,c,x,y);
	if(y>=mid+1)
	add1(mid+1,r,rt<<1|1,c,x,y);
	getnow(l,mid,rt<<1); 
	getnow(mid+1,r,rt<<1|1); 
	push_up(rt);
}
void add2(long long l,long long  r,long long rt,long long c,long long x,long long y)
{
	getnow(l,r,rt);
	if(x<=l&&y>=r)
	{
		lazy2[rt]*=c;
		getnow(l,r,rt);
		return;
	}
	long long mid=(l+r)/2;
	if(x<=mid)
	add2(l,mid,rt<<1,c,x,y);
	if(y>=mid+1)
	add2(mid+1,r,rt<<1|1,c,x,y);
	getnow(l,mid,rt<<1); 
	getnow(mid+1,r,rt<<1|1);
	push_up(rt);
}
long long quert(long long l,long long r,long long rt,long long x,long long y)
{
	getnow(l,r,rt);
	if(l>=x&&r<=y)
	return a[rt];
	long long mid=(l+r)/2;
	long long ret=0;
	if(x<=mid)
	ret+=quert(l,mid,rt<<1,x,y);
	if(y>=mid+1)
	ret+=quert(mid+1,r,rt<<1|1,x,y);
	ret%=mod;
	return ret;
} 
int main()
{ 

	cin>>n>>mod;
	for(i=1;i<=(N<<2)-1;i++)
	lazy2[i]=1;
	build(1,n,1);
	long long p,x,y,c;
	cin>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&p,&x,&y);
		if(p!=3)
		scanf("%lld",&c);
		if(p==3)
		printf("%lld\n",quert(1,n,1,x,y));
		if(p==1)
		add2(1,n,1,c,x,y);
		if(p==2)
		add1(1,n,1,c,x,y);
	}
	return 0;
 } 
