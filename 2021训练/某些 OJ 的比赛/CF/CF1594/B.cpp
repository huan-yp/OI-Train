#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
using namespace std;
inline void read(long long &x)
{
	x=0;long long f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
void cmin(long long &a,long long b){a=min(a,b);}
void cmax(long long &a,long long b){a=max(a,b);}
long long i,j,k,n,s,t,m;
long long p[1005]={1};
const long long mod=1e9+7;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(k);
		for(i=1;i<=31;i++)
		p[i]=p[i-1]*n%mod;
		long long ans=0;
		for(i=0;i<=31;i++)
		{
			if(1<<i&k)
			{
				ans+=p[i];
				ans%=mod;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}

