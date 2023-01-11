#include<bits/stdc++.h>
using namespace std;
long long n,m,a1,a2,a3,b1,b2,b3,x,y,z;
long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
long long abbs(long long x)
{
	return x<0?-x:x;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	a1=m-n;b1=2*m;
	a2=m+n;b2=2*m;
	a3=m-n;b3=m+n;
	x=gcd(a1,b1);
	y=gcd(a2,b2);
	z=gcd(a3,b3);
	a1/=x;b1/=x;
	a2/=y;b2/=y;
	a3/=z;b3/=z;
	a1=abbs(a1);
	b3=abbs(b3);
	b2=abbs(b2);
	b1=abbs(b1);
	a2=abbs(a2);
	a3=abbs(a3);
	printf("%lld %lld\n",a1,b1);
	printf("%lld %lld\n",a2,b2);
	printf("%lld %lld",a3,b3);
	return 0;
}
