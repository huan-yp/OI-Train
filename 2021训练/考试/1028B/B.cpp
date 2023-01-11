#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;;char ch=getchar();
	while((ch>'9'||ch<'0'))ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
}
void cmax(int &a,const int b){if(b>a)a=b;}
inline void cmin(int &a,int *b){if(*b<a)a=*b;}
inline void cmin(int &a,int b){if(b<a)a=b;}
inline int* mymax(int *a,int *b){if(*a>*b)return a;return b;}
const int N=4096;
int i,j,k,m,n,s,t;
int cost[N][N],cnt[N][N];
bitset<N> dp[N];
int check(int x)
{
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;i++)
	dp[i][i-1]=1;
	for(int l=n-1;l>=1;l--)
	{
		for(int r=l+1;r<=n;r+=2)
		{
			if(cost[l][r]<=x&&dp[l+1][r-1])
			dp[l][r]=1;
			if(dp[l][r])dp[l]|=dp[r+1];
		}
	}
	//进行区间 dp 的另一种方式 
	int ret=dp[1][n];
//	cout<<dp[1][n];
	return ret;
}
int main()
{
	read(n);
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j+=2)
	read(cost[i][j]);
	int l=1,r=n*n/4,ans=0;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check(mid))
		ans=mid,r=mid-1;
		else
		l=mid+1;
	}
	cout<<ans<<endl;
//	printf("all time cost:%d\n",time(NULL)-st);
	return 0;
}

