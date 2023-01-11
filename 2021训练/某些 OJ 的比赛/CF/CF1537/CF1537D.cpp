#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
int dp[50001];
int solve(int x)
{
	if(dp[x]!=-1)return dp[x];
	dp[x]=0;
	for(int i=2;i<x;i++)
	{
		if(x%i)continue;
		if(solve(x-i)==0)
		dp[x]=1;
	}
	return dp[x];
}
int low(int x)
{
	return x&(-x);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
//	memset(dp,-1,sizeof(dp));
//	for(i=1;i<=10000;i++)
//	{
//		if(((i)&(-i))==i)
//		printf("%d:%d\n ",i,solve(i));
////		if(i%10==0)
//	//	printf("\n");
//	}
	read(t);
	while(t--)
	{
		read(n);
		if(n%2)
		{
			printf("Bob\n");
			continue;
		}
		if(low(n)==n&&__builtin_ctz(n)%2)
		printf("Bob\n");
		else
		printf("Alice\n");	
	}
	return 0;
}


