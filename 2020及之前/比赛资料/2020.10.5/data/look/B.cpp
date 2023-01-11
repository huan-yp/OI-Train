#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,m,s[405];
ll f[405][405][405];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d",&s[i]);
	f[0][0][0]=1;
	for(int i=0;i<=2*n-m;i++)
	for(int j=0;j<=m;j++)
	for(int k=0;k<=n;k++)
	{
		if(!f[i][j][k])continue;
		f[i][j][k]%=MOD;
		if(j<m&&s[j+1]==0)f[i][j+1][k+1]+=f[i][j][k];
		else f[i+1][j][k+1]+=f[i][j][k];
		if(k>0)
		{
			if(j<m&&s[j+1]==1)f[i][j+1][k-1]+=f[i][j][k];
			else f[i+1][j][k-1]+=f[i][j][k];
		}
	}
	printf("%lld\n",f[2*n-m][m][0]%MOD);
	return 0;
}
