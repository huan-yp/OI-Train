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
const int N=205,mod=1e9+7;
int i,j,k,n,s,t,m,cnt;
int dp[N][N],f[N]={1},inv[N]={1};
char ch1[N],ch2[N];
int C(int n,int m)
{
	if(m>n||m<0)return 0; 
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;
		a=1ll*a*a%mod;
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k),read(m);
	for(i=1;i<=n;i++)
	f[i]=1ll*i*f[i-1]%mod,inv[i]=quick(f[i],mod-2);
	scanf("%s%s",ch1+1,ch2+1);
	for(i=1;i<=n;i++)
	{
		if(ch1[i]!=ch2[i])
		cnt++;
	}
	dp[0][cnt]=1;
	for(s=0;s<k;s++)
	for(i=0;i<=n;i++)
	for(j=0;j<=i&&j<=m;j++)
	{
		dp[s+1][i+m-j*2]+=1ll*dp[s][i]*C(i,j)%mod*C(n-i,m-j)%mod;
		dp[s+1][i+m-j*2]%=mod;
	}
	cout<<dp[k][0]<<endl;
	return 0;
}

