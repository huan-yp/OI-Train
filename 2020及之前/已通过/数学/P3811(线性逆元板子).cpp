#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m,p;
const int N=5e6+10;
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
int quick(int aa,int ss)
{
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=(long long)ret*aa%p;
		aa=(long long)aa*aa%p;
		ss>>=1;
	}
	return ret;
}
int f[N],inv[N],pw[N],a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d%d%d",&n,&p,&s);
	f[0]=1;
	int ans=0;
	pw[0]=1;
	for(i=1;i<=n;i++)
	a[i]=read(),pw[i]=(long long)pw[i-1]*s%p;
	a[n+1]=1;
	for(i=1;i<=n+1;i++)
	f[i]=(long long)f[i-1]*a[i]%p;
	inv[n+1]=quick(f[n+1],p-2);
	for(i=n;i>=1;i--)
	inv[i]=(long long)inv[i+1]*(a[i+1])%p;
	for(i=1;i<=n;i++)
	ans=((long long)ans+(long long)pw[i]*inv[i]%p*f[i-1]%p)%p;
	printf("%d\n",ans);
	return 0;
}

