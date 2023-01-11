#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Num
{
	int _a[255],*a;
	Num(int x=0)
	{
		a=_a+125;
		memset(_a,0,sizeof(_a));
		a[0]=x;
		int now=0;
		while(a[now]>=10)
		{
			a[now+1]=a[now]/10;
			a[now]%=10;
			now++;
		}
	}
	Num&operator=(Num x)
	{
		a=_a+125;
		x.a=x._a+125;
		for(int i=0;i<255;i++)_a[i]=x._a[i];
		return*this;
	}
	Num&operator=(int x)
	{
		a=_a+125;
		memset(_a,0,sizeof(_a));
		a[0]=x;
		return*this;
	}
	Num operator+(Num x)
	{
		a=_a+125;
		x.a=x._a+125;
		Num ans;
		for(int i=-100;i<=100;i++)
		{
			ans.a[i]+=a[i]+x.a[i];
			if(ans.a[i]>=10)ans.a[i]-=10,ans.a[i+1]++;
		}
		return ans;
	}
	Num operator+(int x)
	{
		return *this+Num(x);
	}
	Num operator/(int x)
	{
		a=_a+125;
		Num ans;
		for(int i=100;i>=-100;i--)
		{
			ans.a[i]+=a[i];
			ans.a[i-1]+=ans.a[i]%x*10;
			ans.a[i]/=x;
		}
		return ans;
	}
}l;
ll n;
int t;
char s[255];
void input()
{
	scanf("%s",s+1);
	int m=(int)strlen(s+1);
	int p=1;
	while(p<=m&&s[p]!='.')p++;
	if(p>m)
	{
		for(int i=0;i<m;i++)
		  l.a[i]=s[m-i]-'0';
	}
	else
	{
		for(int i=0;i<p-1;i++)
		  l.a[i]=s[p-i-1]-'0';
		for(int i=p+1;i<=m;i++)
		  l.a[-(i-p)]=s[i]-'0';
	}
}
void print(Num x)
{
	x.a=x._a+125;
	bool flag=0;
	for(int i=100;i>=0;i--)
	{
		if(x.a[i])flag=1;
		if(flag)printf("%d",x.a[i]);
	}
	if(!flag)printf("0");
	printf(".");
	for(int i=-1;i>=-100;i--)printf("%d",x.a[i]);
}
Num calc(Num l,Num r,ll k,ll x)
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
	input();
	while(t--)
	{
		scanf("%lld",&n);
		solve(n);
	}
	return 0;
}
