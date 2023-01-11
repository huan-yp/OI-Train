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
const int N=1e6+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int f[N]={1},inv[N]={1};
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)
		ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
int C(int n,int m)
{
	if(m<0)return 0;
	if(m>n)return 0;
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	for(i=1;i<N;i++)
	f[i]=1ll*i*f[i-1]%mod,inv[i]=quick(f[i],mod-2);
	read(t);
	while(t--) 
	{
		int l,r,ans=0,d;
		read(n),read(l),read(r);
		for(d=min(r-1,n-l);d>=1;d--)
		{
			int c1=min(max(0,r-d),n),c2=min(max(0,n-d-l+1),n);
			if(c1==n&&c2==n)break;
			if(c2>c1)swap(c1,c2);
			if(n%2)
			{
				ans+=C(c1+c2-n,n/2-(n-c1));
				ans%=mod;
				ans+=C(c1+c2-n,n/2+1-(n-c1));
			}
			else
			{
				ans+=C(c1+c2-n,n/2-(n-c1));
			}
			ans%=mod;
		}
		if(n%2)
		ans+=2ll*d*C(n,n/2)%mod;
		else
		ans+=1ll*d*C(n,n/2)%mod;
		
		ans%=mod;
		printf("%d\n",ans);
	}
	return 0;
}

