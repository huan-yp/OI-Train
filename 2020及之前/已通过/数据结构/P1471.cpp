#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t;
const int N=1e5+10;
double sum1[N<<2],sum2[N<<2],lazy[N<<2]; 
void push_up(int rt)
{
	sum1[rt]=sum1[rt<<1]+sum1[rt<<1|1];
	sum2[rt]=sum2[rt<<1]+sum2[rt<<1|1]; 
}
void push_down(int l,int r,int rt)
{
	int mid=(l+r)/2;
	sum2[rt<<1]+=(mid-l+1)*lazy[rt]*lazy[rt]+2*lazy[rt]*sum1[rt<<1];
	sum1[rt<<1]+=(mid-l+1)*lazy[rt];
	sum2[rt<<1|1]+=(r-mid)*lazy[rt]*lazy[rt]+2*lazy[rt]*sum1[rt<<1|1];
	sum1[rt<<1|1]+=(r-mid)*lazy[rt];
	lazy[rt<<1]+=lazy[rt];
	lazy[rt<<1|1]+=lazy[rt];
	lazy[rt]=0;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		scanf("%lf",&sum1[rt]);
		sum2[rt]=sum1[rt]*sum1[rt];
		return;
	}	
	int mid=(l+r)/2;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	push_up(rt);
}
double quert1(int l,int r,int rt,int x,int y)
{
	if(x<=l&&y>=r)
	return sum1[rt];
	int mid=(l+r)/2;
	push_down(l,r,rt);
	double ret=0;
	if(x<=mid)
	ret+=quert1(l,mid,rt<<1,x,y);
	if(y>=mid+1)
	ret+=quert1(mid+1,r,rt<<1|1,x,y);
	return ret;
}
double quert2(int l,int r,int rt,int x,int y)
{
	if(x<=l&&y>=r)
	return sum2[rt];
	int mid=(l+r)/2;
	push_down(l,r,rt);
	double ret=0;
	if(x<=mid)
	ret+=quert2(l,mid,rt<<1,x,y);
	if(y>=mid+1)
	ret+=quert2(mid+1,r,rt<<1|1,x,y);
	return ret;
}
void add(int l,int r,int rt,double c,int x,int y)
{
	if(x<=l&&y>=r)
	{
		sum2[rt]+=(r-l+1)*c*c+2*c*sum1[rt];
		sum1[rt]+=(r-l+1)*c;
		lazy[rt]+=c;
		return;
	}
	int mid=(l+r)/2;
	push_down(l,r,rt);
	if(x<=mid)
	add(l,mid,rt<<1,c,x,y);
	if(y>=mid+1)
	add(mid+1,r,rt<<1|1,c,x,y);
	push_up(rt);
}
int main()
{
	scanf("%d%d",&n,&m);	
	build(1,n,1);
	int op,l,r;
	double x;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%lf",&x);
			add(1,n,1,x,l,r);
		}
		if(op==2)
		printf("%0.4lf\n",quert1(1,n,1,l,r)/(r-l+1));
		if(op==3)
		{
			double a_sum=quert1(1,n,1,l,r);
			double a_=a_sum/(r-l+1);
			printf("%0.4lf\n",a_*a_+(quert2(1,n,1,l,r)-2*a_*a_sum)/(r-l+1));
		}
	}
	return 0;
} 
