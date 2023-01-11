#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
double l;
ll n;
int t;
char s[255];
void print(double x)
{
	printf("%lf ",x);
}
double calc(double l,double r,ll k,ll x)
{
	if(x==0)return l;
	if(x==k)return r;
	if(x<=k/2)return calc(l,(l+r)/2,k/2,x);
	else return calc((l+r)/2,r,k/2,x-k/2);
}
double calc2(double l,double r,ll k,ll x)
{
	if(x==0)return l;
	if(x==k)return r;
	if(x<=k/2)return calc2(l,(l+r)/2,k/2,x);
	else return calc2((l+r)/2,r,k/2,x-k/2);
}
void solve(ll n)
{
	if(n==1)
	{
		printf("0 0\n");
		return;
	}
	if(n==2)
	{
		print(l);
		printf(" ");
		print(l);
		printf("\n");
		return;
	}
	if(n==3)
	{
		printf("0 ");
		print(l);
		printf("\n");
		return;
	}
	if(n==4)
	{
		print(l);
		printf(" 0\n");
		return;
	}
	n-=4;
	ll cur=2;
	bool flag=1;
	while(1)
	{
		if(flag)
		{
			if(n<=(cur-1)*(cur-1))break;
			n-=(cur-1)*(cur-1);
		}
		else
		{
			if(n<=(2*cur-1)*(2*cur-1)-cur*cur-(cur-1)*(cur-1))break;
			n-=(2*cur-1)*(2*cur-1)-cur*cur-(cur-1)*(cur-1);
			cur=2*cur-1;
		}
		flag^=1;
	}
	if(flag)
	{
		ll x=(n-1)/(cur-1)+1,y=(n-1)%(cur-1)+1;
		x=2*x-1,y=2*y-1;
//		printf("(%lld,%lld)\n",x,y);
		print(calc(0,l,2*cur-2,x));
		printf(" ");
		print(calc(0,l,2*cur-2,y));
		printf("\n");
	}
	else
	{
		ll x=(n-1)/(2*cur-1)+1,y=(n-1)%(2*cur-1)+1;
		if(y<=cur-1)
		{
			x=2*x-2;
			y=2*y-1;
		}
		else
		{
			y-=cur-1;
			x=2*x-1;
			y=2*y-2;
		}
//		printf("(%lld,%lld)\n",x,y);
		print(calc(0,l,2*cur-2,x));
		printf(" ");
		print(calc(0,l,2*cur-2,y));
		printf("\n");
	}
}
int main()
{
	scanf("%lld%d",&n,&t);
	scanf("%lf",&l);
	while(t--)
	{
		scanf("%lld",&n);
		solve(n);
	}
	return 0;
}
