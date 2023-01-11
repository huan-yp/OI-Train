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
const int N=505,mod=998244353;
int i,j,k,n,s,t,m,x;
int dp[N][N],f[N]={1},inv[N]={1};
void Inc(int &x,int y)
{
	x+=y;if(x>=mod)x-=mod;
}
void Dec(int &x,int y)
{
	x-=y;if(x<0)x+=mod;
}
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=ret*a%mod;
		a=a*a%mod;s>>=1;
	}
	return ret;
}
//x0 ¸ö >n x1 ¸ö  
int C(int n,int m)
{
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
int solve(int now,int maxn)
{
	if(dp[now][maxn]!=-1)return dp[now][maxn];
	int ret=(now==n);
	for(int i=now+(now==1);i<=n;i++)
	{
		if(maxn+i-1>x)continue;
		ret+=C(n-now,i-now)*quick(i-1,i-now)%mod*solve(i,maxn+i-1)%mod;
		ret%=mod;
	}
	return dp[now][maxn]=ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=1;i<N;i++)f[i]=f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	memset(dp,-1,sizeof(dp));
	read(n),read(x);
	int ans=0;
	for(i=1;i<=x;i++)
	Inc(ans,n*solve(1,i)%mod);
	cout<<(quick(x,n)-ans+mod)%mod<<endl;

	return 0;
}

