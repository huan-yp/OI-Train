#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e7+5;
long long k,n,a[maxn],t[maxn],ans,sum,n95;
int main()
{
	freopen("football.in","r",stdin);
	freopen("football_2.out","w",stdout);
	scanf("%lld%lld",&k,&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&t[i]);
	int l,r=0;
	for(int l=1;l<=n;l++)
	{
		while(n95<=k&&r<=n)
		{
			r++;
			sum+=t[r];
			n95+=a[r];
		}
		ans=ans>sum-t[r]?ans:sum-t[r];
		n95-=a[l];
		sum-=t[l];
	}
	printf("%lld",ans);
	return 0;
}

