#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int N=20005,M=1005;
int i,j,k,m,n,s,t,ans;
int a[N],sum[N][M];
int main()
{
//	freopen("bins.in","r",stdin);
//	freopen("bins.out","w",stdout);
	read(m),read(n);
	for(i=1;i<=n;i++)
	{
		read(a[i]);
		for(j=1;j<=m;j++)sum[i][j]=sum[i-1][j];
		sum[i][a[i]]++;
	}
	for(i=1;i*2<=n;i++)
	{
		int sum1=0,sum2=0,flag=1;
		for(j=m;j>=1;j--)
		{
			sum2+=sum[i][j];			
			if(sum2>sum1)flag=0;
			sum1+=sum[i*2][j]-sum[i][j];
		}
		if(flag)
		cmax(ans,i);
	}
	cout<<ans<<endl;
	return 0;
}

