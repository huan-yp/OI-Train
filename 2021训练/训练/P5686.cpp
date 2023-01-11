#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=500005,mod=1e9+7;
int i,j,k,n,s,t,m,ans;
int a[N],b[N],suma[N],sumb[N];
//(suma[r]-suma[l-1])*(sumb[r]-sumb[l-1])
//suma[r]*sumb[r]+suma[l-1]*sumb[l-1]-suma[r]*sumb[l-1]-sumb[r]*suma[l-1];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]),suma[i]=suma[i-1]+a[i],suma[i]%=mod;
	for(i=1;i<=n;i++)
	read(b[i]),sumb[i]=sumb[i-1]+b[i],sumb[i]%=mod;

	int prea=0,preb=0;
	for(i=1;i<=n;i++)
	{
		ans-=1ll*prea*sumb[i]%mod;ans%=mod;
		ans-=1ll*preb*suma[i]%mod;ans%=mod;
		prea+=suma[i],preb+=sumb[i];
		prea%=mod,preb%=mod;
		ans+=1ll*i*suma[i]%mod*sumb[i]%mod;ans%=mod;
		ans+=1ll*suma[i-1]*sumb[i-1]%mod*(n-i+1)%mod;ans%=mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}

