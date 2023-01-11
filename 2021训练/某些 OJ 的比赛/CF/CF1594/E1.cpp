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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=65,mod=1e9+7;
int i,j,k,n,s,t,m;
int dp[N][10];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=6;i++)
	dp[1][i]=1;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=6;j++)
		for(k=1;k<=6;k++)
		for(s=1;s<=6;s++)
		{
			if(j%3==k%3||j%3==s%3)continue;
			dp[i][j]+=1ll*dp[i-1][k]*dp[i-1][s]%mod;
			dp[i][j]%=mod;
		}
	}
	int ans=0;
	for(i=1;i<=6;i++)
	ans+=dp[n][i],ans%=mod;
	cout<<ans<<endl;

	return 0;
}

