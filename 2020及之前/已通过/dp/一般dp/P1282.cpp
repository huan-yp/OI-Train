#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
const int N=1e3+10;
int dp1[N][N<<3],dp2[N][N<<3];
int a[N],b[N]; 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	cin>>n;
	for(i=1;i<=n;i++)
	scanf("%d%d",&a[i],&b[i]);
	for(i=0;i<=n;i++)
	for(j=0;j<=n<<3;j++)
	dp1[i][j]=dp2[i][j]=1e9;
	if(a[1]>b[1])
	dp1[1][a[1]-b[1]]=0,dp2[1][a[1]-b[1]]=1;
	if(a[1]<b[1])
	dp1[1][b[1]-a[1]]=1,dp2[1][b[1]-a[1]]=0;
	if(a[1]==b[1])
	dp1[1][0]=dp2[1][0]=0;
	for(i=1;i<=n-1;i++)
	{
		dp1[i][0]=min(dp1[i][0],dp2[i][0]);
		dp2[i][0]=dp1[i][0];
		for(j=0;j<=n*5;j++)
		{
			if(a[i+1]>b[i+1])
			{
				dp2[i+1][j+a[i+1]-b[i+1]]=min(dp2[i][j]+1,dp2[i+1][j+a[i+1]-b[i+1]]);
				dp1[i+1][j+a[i+1]-b[i+1]]=min(dp1[i][j],dp1[i+1][j+a[i+1]-b[i+1]]);
				if(j<=a[i+1]-b[i+1])	
				dp1[i+1][a[i+1]-b[i+1]-j]=min(dp2[i][j],dp1[i+1][a[i+1]-b[i+1]-j]);
				else
				dp2[i+1][j-a[i+1]+b[i+1]]=min(dp2[i][j],dp2[i+1][j-a[i+1]+b[i+1]]); 
				if(a[i+1]-b[i+1]>=j)
				dp2[i+1][a[i+1]-b[i+1]-j]=min(dp1[i][j]+1,dp2[i+1][a[i+1]-b[i+1]-j]);
				else
				dp1[i+1][j-a[i+1]+b[i+1]]=min(dp1[i][j]+1,dp1[i+1][j-a[i+1]+b[i+1]]);
			}
			if(a[i+1]==b[i+1])
			{
				dp1[i+1][j]=min(dp1[i+1][j],dp1[i][j]);
				dp2[i+1][j]=min(dp2[i+1][j],dp2[i][j]);
			}
			if(a[i+1]<b[i+1])
			{
				dp2[i+1][j+b[i+1]-a[i+1]]=min(dp2[i][j],dp2[i+1][j+b[i+1]-a[i+1]]);
				dp1[i+1][j+b[i+1]-a[i+1]]=min(dp1[i][j]+1,dp1[i+1][j+b[i+1]-a[i+1]]);
				if(j<=b[i+1]-a[i+1])	
				dp1[i+1][b[i+1]-a[i+1]-j]=min(dp2[i][j]+1,dp1[i+1][b[i+1]-a[i+1]-j]);
				else
				dp2[i+1][j-b[i+1]+a[i+1]]=min(dp2[i][j]+1,dp2[i+1][j-b[i+1]+a[i+1]]);
				if(b[i+1]-a[i+1]>=j)
				dp2[i+1][b[i+1]-a[i+1]-j]=min(dp1[i][j],dp2[i+1][b[i+1]-a[i+1]-j]);
				else
				dp1[i+1][j-b[i+1]+a[i+1]]=min(dp1[i][j],dp1[i+1][j-b[i+1]+a[i+1]]);
			}
		}
	}
	for(i=0;i<=n<<3;i++)
	{
		if(dp1[n][i]!=1e9||dp2[n][i]!=1e9)
		{
			cout<<min(dp1[n][i],dp2[n][i]);
			return 0;	
		}	
	} 
	return 0;
}

