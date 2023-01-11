#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,k,n,s,t,m;
const int N=2e3+10;
int dp[N][N][2],a[N],sum[N],p[N]={1000000},be[N];
priority_queue <int> q[2];
struct oper{
	int op,x;//1先 2后 
}op[N];
signed main()
{
//	freopen("move.in","r",stdin);
//	freopen("move.out","w",stdout);
//freopen(".ans","w",sdtout);
//错误原因：没有分析到留下较小的后可以再给出去 
	read(n),read(m);
	for(i=1;i<=n;i++)
	read(a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++)
	read(p[i]);
	for(i=1;i<=m;i++)
	op[i].op=i%2,op[i].x=p[i]-p[i+1];
	for(i=1;i<=p[1];i++)
	q[0].push(i);
	for(i=2;i<=m;i++)
	{
		for(j=1;j<=p[i]&&!q[i%2].empty();j++)
		q[i%2^1].push(q[i%2].top()),q[i%2].pop();	
	}
	for(i=0;i<=1;i++)
	while(!q[i].empty())
	{
		be[q[i].top()]=i;
		q[i].pop();
	}
	for(i=p[1];i>=1;i--)
	{
		int m1=-2e9-10,m2;
		for(j=n-(p[1]-i);j>=1;j--)
		{
			if(dp[i+1][j+1][0]>m1||(dp[i+1][j+1][0]==m1&&dp[i+1][j+1][1]>m2))
			m1=dp[i+1][j+1][0],m2=dp[i+1][j+1][1];
			if(be[i]==1)
			{
				dp[i][j][0]=m1-a[j];
				dp[i][j][1]=m2+a[j];
			}
			else
			{
				dp[i][j][0]=m1+a[j];
				dp[i][j][1]=m2+a[j];
			}
		}
	}
	int a1=-2e9-10,a2;
	for(i=1;i<=n-p[1]+1;i++)
	{
		if(dp[1][i][0]>a1||(a1==dp[1][i][0]&&dp[1][i][1]>a2))
		a1=dp[1][i][0],a2=dp[1][i][1];
	}
	printf("%lld %lld",((long long)a2-a1)/2,((long long)a1+a2)/2);
	return 0;
}
