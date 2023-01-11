#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long dp[N],now[N],h[N],r;
int i,j,k,m,n,s,t;
long long tail,head,q[N];
double solve(double k1,double b1,double k2,double b2)
{
	if(k1-k2==0)
	return 1e18;
	return (b2-b1)/(k1-k2);
}
int main()
{
	freopen("fist.in","r",stdin); 
	freopen("fist.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	scanf("%lld",&h[i]);
	head=tail=1;
	if(n>10000)
	{
		for(i=1;i<=n;i++)
		{
			dp[i]=dp[i-1];	
			while(solve(h[q[tail-2]],(-q[tail-2]+1)*h[q[tail-2]],h[q[tail-1]],(-q[tail-1]+1)*h[q[tail-1]])>solve(h[i],(-i+1)*h[i],h[q[tail-2]],(-q[tail-2]+1)*h[q[tail-2]])&&tail-2>=head)
			tail--;
			q[tail++]=i;
			while((i-q[head+1]+1)*h[q[head+1]]>(i-q[head]+1)*h[q[head]]&&head+1!=tail)
			head++;
			dp[i]=max(dp[i],(i-q[head]+1)*h[q[head]]);
			printf("%lld ",dp[i]);
		}
		return 0;
	}
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(h[i]>=h[j])
			now[j]++;
			else
			now[j]=0;
		}
		dp[i]=dp[i-1];
		for(j=1;j<=i;j++)
		dp[i]=max(dp[i],now[j]*h[j]);
	}
	for(i=1;i<=n;i++)
	printf("%lld ",dp[i]);
	return 0;
}
