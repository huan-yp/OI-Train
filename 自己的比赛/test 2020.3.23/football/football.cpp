#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e7+5;
long long k,n,a[maxn],sum[maxn],ans;
//long long read()
//{
//	char c;long long rt=0;
//	c=getchar();
//	while(c<'0'||c>'9')
//		c=getchar();
//	while(c>='0'&&c<='9')
//	{
//		rt=rt*10+c-'0';
//		c=getchar();
//	}
//	return rt;
//}
int main()
{
	freopen("football.in","r",stdin);
	freopen("football.out","w",stdout);
	scanf("%lld%lld",&k,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&sum[i]);
//		a[i]=read();sum[i]=read();
		sum[i]+=sum[i-1];
		a[i]+=a[i-1];
	}
	sum[n+1]=sum[n];
	int l,r=1;
	for(int l=1;l<=n;l++)
	{
		while(a[r]-a[l-1]<=k&&r<=n)
			r++;
		ans=ans>sum[r-1]-sum[l-1]?ans:sum[r-1]-sum[l-1];
	}
	printf("%lld",ans);
	return 0;
}

