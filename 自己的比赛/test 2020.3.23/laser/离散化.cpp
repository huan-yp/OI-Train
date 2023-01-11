#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=605,inf=0x3f3f3f3f;
int n,cnt,dp[maxn][maxn];
struct ple
{
	int a,b,d;
}pe[maxn];
struct in
{
	int nm,id,p;
}a[maxn];
bool cmp(in x,in y)
{
	return x.nm<y.nm;
}
int main()
{
	freopen("10-Î´ÀëÉ¢»¯.in","r",stdin);
	freopen("10.in","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[2*i-1].nm,&a[2*i].nm,&pe[i].d);
		a[2*i-1].id=a[2*i].id=i;
		a[2*i-1].p=0,a[2*i].p=1;
	}
	sort(a+1,a+2*n+1,cmp);
	for(int i=1;i<=2*n;i++)
	{
		if(a[i].nm!=a[i-1].nm)
			cnt++;
		if(!a[i].p)
			pe[a[i].id].a=cnt;
		else
			pe[a[i].id].b=cnt;
	}
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
	{
		printf("%d %d %d\n",pe[i].a,pe[i].b,pe[i].d);
	}
	return 0;
}
