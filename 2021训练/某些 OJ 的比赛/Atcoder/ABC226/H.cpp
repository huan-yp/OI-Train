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
const int N=105,mod=998244353;
int i,j,k,n,s,t,m,ans;
int dp[N][N][N],l[N],r[N],inv[N];
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
void Inc(int &x,const int y){x+=y;if(x>=mod)x-=mod;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=100;i++)inv[i]=quick(i,mod-2);
	for(i=1;i<=n;i++)
	read(l[i]),read(r[i]);
	for(int A=0;A<=99;A++)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1;
		for(i=0;i<n;i++)
		for(int c1=0;c1<=i;c1++)
		for(int c2=0;c1+c2<=i;c2++)
		{
			int il=inv[r[i+1]-l[i+1]];
			if(l[i+1]<=A)Inc(dp[i+1][c1+1][c2],1ll*dp[i][c1][c2]*il%mod*(min(A,r[i+1])-l[i+1])%mod);
			if(r[i+1]>=A+1)Inc(dp[i+1][c1][c2+1],1ll*dp[i][c1][c2]*il%mod*(r[i+1]-max(A+1,l[i+1]))%mod);
			if(A>=l[i+1]&&A+1<=r[i+1])Inc(dp[i+1][c1][c2],1ll*dp[i][c1][c2]*il%mod);
		}
		for(i=0;i<k;i++)
		for(j=0;j<=n-i-1;j++)
		{
			int lst=n-i-j,rk=k-i;
			if(lst>=rk)
			Inc(ans,1ll*dp[n][j][i]*(A+1ll*(lst+1-rk)*inv[lst+1]%mod)%mod);
		}
	}
	cout<<ans<<endl;
	return 0;
}

