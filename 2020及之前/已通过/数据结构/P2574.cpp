#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int i,j,k,m,n,s,t,lazy[N<<2],sum[N<<2],js;
char a[N]; 
void push_up(int rt)
{
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void push_down(int l,int r,int rt)
{
	lazy[rt]%=2;
	if(lazy[rt]==1)
	{
		int mid=(l+r)/2;
		sum[rt<<1]=(mid-l+1)-sum[rt<<1];
		sum[rt<<1|1]=(r-mid)-sum[rt<<1|1]; 
	}
	if(lazy[rt]==1&&l!=r)
	{
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		lazy[rt<<1]%=2;
		lazy[rt<<1|1]%=2; 
	}
	lazy[rt]=0;
} 
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=a[js++]-'0';
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1); 
	push_up(rt);
}
void add(int l,int r,int rt,int x,int y)
{
	if(l>=x&&r<=y)
	{
		sum[rt]=r-l+1-sum[rt];
		lazy[rt]++;
		return;
	}
	int mid=(l+r)/2;
	push_down(l,r,rt); 
	if(x<=mid)
	add(l,mid,rt<<1,x,y);
	if(y>=mid+1)
	add(mid+1,r,rt<<1|1,x,y);
	push_up(rt);
}
int quert(int l,int r,int rt,int x,int y)
{
	if(l>=x&&r<=y)
	return sum[rt];
	int mid=(l+r)/2;
	push_down(l,r,rt);
	int ret=0;
	if(x<=mid)
	ret+=quert(l,mid,rt<<1,x,y);
	if(y>=mid+1)
	ret+=quert(mid+1,r,rt<<1|1,x,y);
	return ret;
}
int main()
{
//	freopen("P2574_1.in","r",stdin);
//	freopen("P2574_1.ans","w",stdout);
	cin>>n>>m;
	cin>>a; 
	build(1,n,1);
	int op;
	for(i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==0)
		add(1,n,1,l,r);
		else
		printf("%d\n",quert(1,n,1,l,r)); 
	}
	return 0;
 } 
