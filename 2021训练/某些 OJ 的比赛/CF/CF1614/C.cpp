#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=1e6+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int a[N],l[N],r[N],val[N],sum[N],f[N],inv[N],p[N]={1};
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)ret=ret*a%mod;
		s>>=1;a=a*a%mod;
	}
	return ret;
}
int C(int n,int m)
{
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	f[0]=inv[0]=1;
	for(i=1;i<N;i++)f[i]=f[i-1]*i%mod,inv[i]=quick(f[i],mod-2),p[i]=p[i-1]*2%mod;
	int tot=1;read(tot);
	while(tot--)
	{
		read(n),read(m);int ans=0;
		for(i=1;i<=m;i++)
		read(l[i]),read(r[i]),read(val[i]);
		for(s=30;s>=0;s--)
		{
			int cnt0=0,cnt1=0;
			for(i=1;i<=n;i++)sum[i]=0;

			for(i=1;i<=m;i++)
			{
				if((val[i]&(1<<s))==0)
				sum[l[i]]++,sum[r[i]+1]--;
			}
			for(i=1;i<=n;i++)
			sum[i]=sum[i-1]+sum[i];
				
			for(i=1;i<=n;i++)
			if(sum[i])cnt0++;
			else cnt1++;
			for(i=1;i<=cnt1;i+=2)
			ans+=C(cnt1,i)*p[cnt0]%mod*p[s]%mod;
		}
		cout<<ans%mod<<endl;
	}
	return 0;
}

