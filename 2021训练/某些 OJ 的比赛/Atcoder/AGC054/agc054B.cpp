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
/*
考虑两个人各拿哪些物品
发现确定好每个人拿的物品的序列后
合并的方式是唯一存在的 
*/
const int N=105,mod=998244353; 
int i,j,k,n,s,t,m;
int dp[N*N][N],a[N],f[N]={1};
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]),f[i]=1ll*f[i-1]*i%mod,s+=a[i];
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	for(j=n*100;j>=a[i];j--)
	for(k=1;k<=i;k++)
	dp[j][k]+=dp[j-a[i]][k-1],dp[j][k]%=mod;
	
	if(s&1)
	{
		printf("0");
		return 0;
	}
	int ans=0;
	for(i=0;i<=n;i++)
	ans+=1ll*f[i]*f[n-i]%mod*dp[s/2][i]%mod,ans%=mod;
	cout<<ans;
	return 0;
}

