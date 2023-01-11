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
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
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
	for(int i=1;i<=cnt;i++)
		for(int l=1;l+i-1<=cnt;l++)
		{
			int r=l+i-1,ans=0,id;
			dp[l][r]=inf;
			for(int j=1;j<=n;j++)
				if(pe[j].a>=l&&pe[j].b<=r&&pe[j].d>ans)
				{
					ans=pe[j].d;
					id=j;
				}
			if(ans==0)
				dp[l][r]=0;
			for(int j=pe[id].a;j<=pe[id].b;j++)
				dp[l][r]=min(dp[l][r],dp[l][j-1]+dp[j+1][r]+ans);
		}
	printf("%d",dp[1][cnt]);
	return 0;
}
