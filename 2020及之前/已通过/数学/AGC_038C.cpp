#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
const int N=1e6+10; 
long long mod=998244353,js;
long long sum[N],c[N],pre[N],zs[N],mu[N];
int pd[N];
long long quick(int ss)
{
	long long ret=1;
	long long a=2;
	while(ss)
	{
		if(ss&1)
		ret=ret*a%mod;
		a=a*a%mod;
		ss=ss>>1;	
	}	
	return ret;
} 
void init()
{
	mu[1]=1;
	pd[1]=1; 
	for(i=2;i<N;i++)
	{
		if(!pd[i])
		zs[++js]=i,mu[i]=-1;
		for(j=1;j<=js&&zs[j]*i<N;j++)
		{
			pd[zs[j]*i]=1;
			if(i%zs[j]==0)
			break;
			mu[zs[j]*i]=-mu[i];
		}
	}
	for(i=1;i<N;i++)
	for(j=1;i*j<N;j++)
	sum[i*j]=(sum[i*j]+mu[i]*i*i*j%mod)%mod; 
	for(i=1;i<N;i++)
	for(j=1;i*j<N;j++)
	pre[i]=(pre[i]+c[i*j]*j)%mod;
} 
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		c[t]++;
	}
	init();
	long long ans=0;
	for(i=1;i<N;i++)
	ans=(ans+sum[i]*pre[i]%mod*pre[i])%mod;
	for(i=1;i<N;i++)
	ans=(ans-c[i]*i)%mod;
	ans=ans*quick(mod-2)%mod;
	printf("%lld",(ans+mod)%mod);
	return 0;
}

