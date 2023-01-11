#include<iostream>
#include<cstdio>
#include<algorithm>
#define Re register
#define In inline
using namespace std;
const int maxn=5e6+5;
//const long long Max=(1ll<<62)-1+(1ll<<62);
int n,m,l=1,r=0;
long long p,ans,sum;
struct que
{
	int id;
	long long num;
}qu[maxn];
struct monster
{
	long long t,b;
}s[maxn];
In void humqueue()
{
	for(Re int i=1;i<=n;i++)
	{
		while(r>=l&&qu[l].id<=i-m)
			l++;
		while(r>=l&&qu[r].num<=s[i].t)
			r--;
		qu[++r].id=i;
		qu[r].num=s[i].t;
		if(i<=m-1)
			continue;
		s[i-m+1].t=qu[l].num;
	}
	long long mx=0;
	for(Re int i=n;i>=n-m+1;i--)
	{
		mx=max(mx,s[i].t);
		s[i].t=mx;
	}
}
In bool cmp(monster x,monster y)
{
	return x.t*y.b<y.t*x.b;
}
int main()
{
	scanf("%d%lld%d",&n,&p,&m);
	for(Re int i=1;i<=n;i++)
		scanf("%lld",&s[i].t);
	for(Re int i=1;i<=n;i++)
		scanf("%lld",&s[i].b);
	humqueue();
	for(Re int i=1;i<=n;i++)
		s[i].t=(s[i].t-1)/p+1;
	sort(s+1,s+n+1,cmp);
	for(Re int i=1;i<=n;i++)
	{
		sum+=s[i].t;
		ans+=sum*s[i].b;
	}
	printf("%lld",ans);
	return 0;
}
