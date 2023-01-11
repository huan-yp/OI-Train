#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t;
const int N=2e5+10;
int sum[N<<2],lazy1[N<<2],lazy2[N<<2];
int p[N];
void push_down(int rt)
{
	if(lazy2[rt]==1)
	{
		lazy1[rt<<1]=lazy1[rt<<1|1]=lazy1[rt];
		lazy2[rt<<1]=lazy2[rt<<1|1]=lazy2[rt];
		sum[rt<<1]=sum[rt<<1|1]=lazy1[rt]%2;
	}
	if(lazy2[rt]==2)
	{
		lazy1[rt<<1]=lazy1[rt<<1|1]=lazy1[rt];
		lazy2[rt<<1]=lazy2[rt<<1|1]=lazy2[rt];
		sum[rt<<1]=sum[rt<<1|1]=(lazy1[rt]+1)%2;
	}
	if(lazy2[rt]==0)
	{
		sum[rt<<1]=sum[rt<<1]+lazy1[rt];
		sum[rt<<1|1]=sum[rt<<1|1]+lazy1[rt];
		sum[rt<<1]%=2;
		sum[rt<<1|1]%=2;
		lazy1[rt<<1]+=lazy1[rt];
		lazy1[rt<<1|1]+=lazy1[rt];
	}
	lazy2[rt]=0;
	lazy1[rt]=0;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
	p[l]=sum[rt]%2;
	if(p[l]==1)
	k=1;
	return;
	}
	int mid=(l+r)/2;
	push_down(rt);
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
}
void add1(int l,int r,int rt,int x,int y)
{
	if(x<=l&&y>=r)
	{
		sum[rt]=(sum[rt]+1)%2;
		lazy1[rt]++;
		return;
	}
	push_down(rt);
	int mid=(l+r)/2;
	if(x<=mid)
	add1(l,mid,rt<<1,x,y);
	if(y>=mid+1)
	add1(mid+1,r,rt<<1|1,x,y);
}
void add2(int l,int r,int rt,int c,int x,int y) 
{
	if(x<=l&&y>=r)
	{
		sum[rt]=c-1;
		lazy2[rt]=c;
		lazy1[rt]=0;
		return;
	}
	push_down(rt);
	int mid=(l+r)/2;
	if(x<=mid)
	add2(l,mid,rt<<1,c,x,y);
	if(y>=mid+1)
	add2(mid+1,r,rt<<1|1,c,x,y);
} 
int main()
{
	char op,ch1,ch2,ch;
	int l,r;
	while(cin>>op)
	{
		//if(op=='a')
		//break; 
		cin>>ch1>>l>>ch>>r>>ch2;
		int ln,rn;
		if(ch1=='(')
		ln=2*l+2;
		if(ch1=='[')
		ln=2*l+1;
		if(ch2==')')
		rn=r*2;
		if(ch2==']')
		rn=r*2+1;
		if(op=='U')
		{
			add2(1,N-7,1,2,ln,rn); 
		}
		if(op=='I')
		{
			if(ln-1!=0) 
			add2(1,N-7,1,1,1,ln-1);
			add2(1,N-7,1,1,rn+1,N-7);
		}
		if(op=='D')
		{
			add2(1,N-7,1,1,ln,rn);
		}
		if(op=='C')
		{
			if(ln-1!=0)
			add2(1,N-7,1,1,1,ln-1);
			add2(1,N-7,1,1,rn+1,N-7);
			add1(1,N-7,1,ln,rn);
		}
		if(op=='S')
		{
			add1(1,N-7,1,ln,rn);
		}
	}
		build(1,N-7,1);
		i=1;
		while(i<=N-7)
		{
		while(p[i]!=1&&i<=N-7)
		i++;
		if(i%2==0&&i!=N-6)
		cout<<'('<<(i-2)/2<<',';
		else
		if(i!=N-6)
		cout<<'['<<(i-1)/2<<',';	
		while(p[i]==1&&i<=N-6)
		i++;
		if((i-1)%2==0&&i!=N-6)
		cout<<(i-1)/2<<')'<<' ';
		else
		if(i!=N-6)
		cout<<(i-2)/2<<']'<<' ';
	} 
	if(k==0)
	cout<<"empty set";
	return 0;
} 
