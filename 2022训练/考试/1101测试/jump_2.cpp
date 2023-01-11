#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005,mod=1e9+7;
int n,f[N][N],g[N][N],ans;
char a[N];
int main()
{
	scanf("%d%s",&n,a+1);f[0][0]=g[n][1]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='L')for(int j=1;j<=i;j++)
		f[i][j]=(ll)j*(f[i-1][j]+f[i-1][j+1])%mod;
		else for(int j=1;j<=i;j++)
		f[i][j]=(ll)j*(f[i-1][j]+f[i-1][j-1])%mod;
		
	}
	for(int i=n-1;i>=1;i--)
	{
		if(a[i+1]=='L')for(int j=1;j<=i;j++)
		g[i][j]=((ll)j*g[i+1][j]+(ll)(j-1)*g[i+1][j-1])%mod;
		else for(int j=1;j<=i;j++)
		g[i][j]=((ll)j*g[i+1][j+1]+(ll)(j-1)*g[i+1][j])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=1;j<=i;j++) ans=(ans+(ll)(f[i-1][j]+f[i-1][j-1])*g[i][j])%mod;
		printf("%d ",ans);
	}
	return 0;
}
