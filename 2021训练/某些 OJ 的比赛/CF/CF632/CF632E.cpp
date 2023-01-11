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
const int N=1e6+10;
int dp[N],a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);

	memset(dp,1,sizeof(dp));
	dp[0]=0;
	read(n),read(k);//不能陷入 bitset 的笼子，5s 完全可以考虑 n^3 ，利用好 dp 值本身。
	for(i=1;i<=n;i++)
	read(a[i]);
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)
	a[i]-=a[1];
	for(i=2;i<=n;i++)
	for(j=a[i];j<N;j++) 
	dp[j]=min(dp[j],dp[j-a[i]]+1);

	for(i=0;i<N;i++)
	if(dp[i]<=k)
	printf("%d ",i+a[1]*k);
	return 0;
}


