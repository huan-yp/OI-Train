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
const int N=1e7+10,mod=998244353;
int i,j,k,n,s,t,m,x,y,M,ans,lc=1;
int a[N],dp[128],p[105]={1},tmp[N],dp2[128];
int gcd(int x,int y){if(y==0)return x;return gcd(y,x%y);}
int lcm(int x,int y){return x/gcd(x,y)*y;}
void Dec(int &x,const int y){x-=y;if(x<0)x+=mod;}
void Inc(int &x,const int y){x+=y;if(x>=mod)x-=mod;}
signed main()
{
	read(n),read(a[0]),read(x),read(y),read(k),read(M);
	for(i=1;i<n;i++)a[i]=(1ll*a[i-1]*x%M+y)%M;
	for(i=1;i<=k;i++)p[i]=1ll*p[i-1]*n%mod;
	for(i=1;i<k;i++)lc=lcm(lc,i);
	for(i=0;i<lc/(k==17?2:1);i++)
	{
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		int maxn=0;dp[0]=1;
		for(j=1;j<=k-(k==17)*2;j++)
		{
			int lstmaxn=maxn;
			for(s=lstmaxn;s>=0;s--)
			{
				if(dp[s]==0)continue;
				int inc=(i-s)%j,tmp1=dp[s];
				Inc(tmp[i],1ll*p[k-j]*(i-s)%mod*dp[s]%mod);
				dp[s]=1ll*dp[s]*(n-1)%mod;
				Inc(dp[inc+s],tmp1);
				cmax(maxn,inc+s);
			}
		}
		if(k==17)
		{
			int lasmaxn=maxn,lstmaxn=maxn;j=16;
			Inc(tmp[i+lc/2],tmp[i]);
			Inc(tmp[i+lc/2],1ll*lc/2*p[j]%mod*(j-1)%mod);
			for(s=lstmaxn;s>=0;s--)
			{
				int inc=(i-s)%j,inc2=(i-s+lc/2)%j,tmp1=dp[s];
				dp[s]=1ll*dp[s]*(n-1)%mod;
				Inc(tmp[i],1ll*p[k-j]*(i-s)%mod*tmp1%mod);
				Inc(dp2[s],1ll*tmp1*(n-1)%mod);
				Inc(dp2[inc2+s],tmp1);
				Inc(tmp[i+lc/2],1ll*p[k-j]*(i+lc/2-s)%mod*tmp1%mod);
				cmax(lasmaxn,inc2+s);	
				Inc(dp[inc+s],tmp1);
				cmax(maxn,inc+s);
			}
			for(s=0;s<=maxn;s++)
			Inc(tmp[i],1ll*(i-s)*dp[s]%mod);
			for(s=0;s<=lasmaxn;s++)
			Inc(tmp[i+lc/2],1ll*(i-s+lc/2)*dp2[s]%mod);
		}
	}
	const int cnt=1ll*p[k-1]*k%mod;
	for(i=0;i<n;i++)
	{
		int base=a[i]/lc;
		Inc(ans,tmp[a[i]%lc]);
		Inc(ans,1ll*base*lc*cnt%mod);
	}
	cout<<ans<<endl;
	return 0;
}
