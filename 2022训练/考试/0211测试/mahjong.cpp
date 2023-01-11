#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL unsigned long long
#define pii pair<int,int>
//为啥子要出卡常题 
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=501,mod=1e9+7;
int i,j,k,n,s,t,m;
int C[N][N],sum[N][N][N],p[N<<1]={1};
LL dp[7][N][N];
template<typename _type>
void Inc(_type &x,const int &y){x+=y;if(x>=mod)x-=mod;}
void Dec(int &x,const int &y){x-=y;if(x<0)x+=mod;}
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
signed main()
{
	read(t),read(n),read(m);
	double time1=0,time2=0;
	for(i=1;i<=n+m;i++)p[i]=6ll*p[i-1]%mod;
	for(i=0;i<N;i++)
	for(C[i][0]=1,j=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	
	dp[0][0][0]=1;
	for(int i1=0;i1<=n;i1++)
	for(int i2=0;i2<=m;i2++)
	for(int j1=0;j1<=0;j1++)
	for(int j2=0;j2<=0;j2++)
	if(1>t||i1-j1<=i2-j2) 
	Inc(dp[1][i1][i2],1ll*dp[0][j1][j2]*C[n-j1][i1-j1]%mod*C[m-j2][i2-j2]%mod);
	
	for(i=2;i<=min(t,5);i++)
	{
		auto time = clock();
		for(int j1=0;j1<=n;j1++)
		for(int i2=0;i2<=m;i2++)
		{
			sum[j1][i2][0]=1ll*dp[i-1][j1][0]%mod*C[m][i2]%mod;
			int *p=&sum[j1][i2][1];
			for(int j2=1;j2<=i2;j2++)
			{
				if(dp[i-1][j1][j2]>=mod)dp[i-1][j1][j2]%=mod;
				*p=*(p-1);
				Inc(*p++,1ll*dp[i-1][j1][j2]*C[m-j2][i2-j2]%mod);
			}
		}
		for(int i1=0;i1<=n;i1++)
		for(int j1=0;j1<=i1;j1++)
		for(int i2=max(0,i1-j1);i2<=m;i2++)
		{
			dp[i][i1][i2]+=1ll*C[n-j1][i1-j1]*sum[j1][i2][i2+j1-i1];
			if(dp[i][i1][i2]>>62)dp[i][i1][i2]%=mod;
		}
	}
	if(t==6)
	{
		for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
		Inc(dp[6][n][m],(n-i<=m-j)*dp[5][i][j]%mod);
		
		printf("%lld\n",((quick(6,n+m)-dp[6][n][m]%mod)+mod)%mod);
	}
	else
	{
		int all=0;
		for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
		Inc(all,1ll*dp[t][i][j]%mod*quick(6-t,n+m-i-j)%mod);
		
		printf("%d\n",((quick(6,n+m)-all)+mod)%mod);
	}
	return 0;
}

