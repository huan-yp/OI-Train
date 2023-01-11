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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int mod=998244353;
const int N=5e4+10;
int b[N],cnt[N],a[N],f[N]={1},invf[N]={1},pnt[N],c[N];
int i,j,k,n,s,t,m;
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)
		ret=1ll*a*ret%mod;
		s>>=1;
		a=1ll*a*a%mod;
	}
	return ret;
}
int inv(int x)
{
	return quick(x,mod-2);
}
int calc(int k,int n,int s)
{
	if(k+s>n)return 0;
	return 1ll*invf[n]*f[n-k]%mod*f[n-s]%mod*invf[n-s-k]%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<N;i++)
	{
		f[i]=1ll*f[i-1]*i%mod;
		invf[i]=inv(f[i]);
	}
	for(i=1;i<=n;i++)
	read(a[i]),b[i]=a[i];

	sort(b+1,b+n+1),m=unique(b+1,b+1+n)-b-1;
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
		cnt[a[i]]++;
	}
	for(i=1;i<=m;i++)
	pnt[cnt[i]]++;
	
	//pnt[i]:cnt为 i 的个数  
	for(i=1;i<=n;i++)
	{
		if(pnt[i]==0)continue;
		b[++t]=i;
	}
	for(i=1;i<=n;i++)
	{
		int ans=0;
		for(j=1;j<=t;j++)
		{
			ans+=1ll*pnt[b[j]]*(1-calc(i,n,b[j]))%mod;
			ans%=mod;
		}
		cout<<(ans+mod)%mod<<endl;
	}
	return 0;
}

