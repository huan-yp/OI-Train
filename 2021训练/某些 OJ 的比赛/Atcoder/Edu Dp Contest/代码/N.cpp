#include<cstdio>
#include<iostream>
#define int long long
using namespace std;
const int N=8e2+10;
int i,j,k,m,n,s,t,dpi[N][N],dpa[N][N];
int a[N],sum[N];
signed main()
{
	for(i=1;i<N;i++)
	for(j=1;j<N;j++)
	dpi[i][j]=1e18;
	cin>>n;
	for(i=1;i<=n;i++)
	{	
	scanf("%lld",&a[i]);
	a[i+n]=a[i];
	}
	for(i=1;i<=2*n-1;i++)
	sum[i]=sum[i-1]+a[i];
	for(i=1;i<=2*n-1;i++)
	dpa[i][i]=dpi[i][i]=0;
	for(i=2;i<=n;i++)
	for(j=1;j<=2*n-i;j++)
	for(k=j;k<=j+i-2;k++)
	{
		dpi[j][j+i-1]=min(dpi[j][j+i-1],dpi[j][k]+dpi[k+1][j+i-1]+sum[j+i-1]-sum[j-1]);
		dpa[j][j+i-1]=max(dpa[j][j+i-1],dpa[j][k]+dpa[k+1][j+i-1]+sum[j+i-1]-sum[j-1]);
	}
	int maax=0,miin=1e18;
	for(i=1;i<=1;i++)
	{
		maax=max(maax,dpa[i][i+n-1]);
		miin=min(miin,dpi[i][i+n-1]);
	}
	cout<<miin;
	return 0;
}
