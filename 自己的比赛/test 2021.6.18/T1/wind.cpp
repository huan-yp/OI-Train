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
const int mod=998244353; 
const int N=3e7+10; 
int i,j,k,n,s,t,m,lst=1;
int dp[N];
signed main()
{
	freopen("wind.in","r",stdin);
	freopen("wind.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n); 
	for(i=1;i<=n;i++)
	lst=1ll*lst*i%mod;
	
	dp[1]=0,dp[2]=1;
	for(i=3;i<=n;i++)
	dp[i]=1ll*(i-1)*(dp[i-1]+dp[i-2])%mod;
	
	printf("%d",1ll*lst*dp[n]%mod);
	return 0;
}


