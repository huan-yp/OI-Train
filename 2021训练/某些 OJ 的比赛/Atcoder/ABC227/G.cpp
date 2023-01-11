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
const int N=1e6+10,mod=998244353;
int i,j,k,n,s,t,m,ans=1;
int cnt[N],num[N],nnum[N],pd[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=1e6;i++)num[i]=i,nnum[i]=n-k+i;
	for(i=2;i<=1e6;i++)
	{
		if(num[i]==1||num[i]==0)continue;pd[i]=1;
		for(j=i;j<=1e6;j+=i)
		{
			while(num[j]%i==0)
			{
				num[j]/=i;
				if(j<=k)cnt[i]--;
			}
		}
	}
	for(i=2;i<=1e6;i++)
	{
		if(pd[i]==0)continue;
		for(j=((n-k)/i+1)*i;j<=n;j+=i)
		{
			while(nnum[j-n+k]%i==0)
			{
				nnum[j-n+k]/=i;
				cnt[i]++;
			}
		}
	}
	for(i=1;i<=k;i++)
	if(nnum[i]!=1)ans=ans*2%mod;
	for(i=1;i<=1e6;i++)
	ans=1ll*ans*(cnt[i]+1)%mod;

	cout<<ans<<endl;
	return 0;
}

