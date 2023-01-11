#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=4e5+10,mod=998244353;
int i,j,k,n,s,t,m;
int a[N],p[N],invp[N],sum[N],f[N],inv[N],dp[N],pre[N][305];
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
int C(int n,int m)
{
	if(m>n||m<0||n<0)return 0; 
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
void Dec(int &x,const int &y){x-=y;if(x<0)x+=mod;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(t);f[0]=inv[0]=p[0]=invp[0]=1;
	for(i=1;i<=2*n;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<=2*n;i++)p[i]=p[i-1]*2%mod,invp[i]=quick(p[i],mod-2);
	
	sum[0]=p[n];
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+1ll*p[n-i]*C(i+n-1,n-1)%mod;
		sum[i]%=mod;
	}
	for(j=0;j<=300;j++)
	for(i=0;i<=2*n;i++)
	pre[i][j]=(pre[i-1][j]+1ll*p[2*n-i]*C(i-1-j,n-j-1))%mod;
	
	while(t--)
	{
		read(m);
		for(i=1;i<=m;i++)read(a[i]);
		int ans=0;
		if(m>n)
		{
			puts("0");
			continue;
		}
		a[++m]=2*n+1;
		for(i=1;i<=m;i++)
		{
			if(a[i]-i<n||a[i]==a[i-1]+1)continue;
			if(a[i-1]-i+1>=n)
			{
				int tmp=sum[a[i]-i-n]-sum[a[i-1]-i+1-n];tmp%=mod;
				int have=2*n-a[i]+i,need=2*n-a[i]+1;
				tmp=1ll*tmp*invp[have-need]%mod;
				ans+=tmp;ans%=mod;
			}
			else
			{
				int tmp=sum[a[i]-i-n];tmp%=mod;
				int have=2*n-a[i]+i,need=2*n-a[i]+1;
				tmp=1ll*tmp*invp[have-need]%mod;
				ans+=tmp;ans%=mod;
			}
		}	
		m--;
		if(a[m]!=2*n)
		{
			Dec(ans,C(2*n-m-1,n-1));
			Inc(ans,1ll*C(a[m]-m,n-m)*p[2*n-a[m]]%mod);
		}
		if(m>300)
		{
			for(i=a[m]+1;i<2*n;i++)
			Inc(ans,1ll*C(i-1-m,n-m-1)*p[2*n-i]%mod);
		}
		else
		{
			if(a[m]+1<=2*n-1)
			{
				Inc(ans,pre[2*n-1][m]);
				Dec(ans,pre[a[m]][m]);
			}
		}
		ans=(ans+mod)%mod;
		printf("%lld\n",2ll*ans*invp[n*2]%mod);
	}
	return 0;
}

