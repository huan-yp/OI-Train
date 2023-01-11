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
const int N=1005,mod=998244353;
int i,j,k,n,s,t,m,ans;
int p[N],q[N],a[N],pos[N],f[N]={1},inv[N]={1};
int sumpos[N],sumval[N],C[N][N];
int c[N/2][N/2][N/2],dp[N][N];
void Inc(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)ret=1ll*ret*a;
		s>>=1,a=1ll*a*a%mod;
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	
	read(n);C[0][0]=1;
	for(i=1;i<=n;i++)read(p[i]),pos[p[i]]=i;
	for(i=1;i<=n;i++)read(q[i]);
	for(i=1;i<=n;i++)a[i]=q[pos[i]];
	for(i=1;i<N;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<N;i++)
	{
		C[i][0]=1;
		for(j=1;j<=i;j++)
		C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(i=1;i<=n;i++)
	{
		sumpos[i]=sumpos[i-1]+(a[i]==0);
		if(a[i])sumval[a[i]]=1;
	}
	for(i=1;i<=n;i++)sumval[i]+=sumval[i-1];
	for(i=1;i<=n;i++)sumval[i]=i-sumval[i];
	//dp[i][k]*C(a,d)*C(b,d)->dp[j][k+d]
	dp[0][0]=1;a[0]=-1,a[n+1]=n+1;
	sumpos[n+1]=sumpos[n],sumval[n+1]=sumval[n];
	for(i=0;i<=n;i++)
	for(j=i+1;j<=n+1;j++)
	{
		if(a[i]>a[j]||a[i]==0||a[j]==0)continue;
		int aval=sumpos[j]-sumpos[i-1],bval=sumval[a[j]]-sumval[a[i]-1];
		for(k=0;k<=sumval[n];k++)
		for(int d=k;d<=sumval[n];d++)
		{
			int cho=d-k;if(cho>aval||cho>bval)continue;
			Inc(dp[j][d],1ll*dp[i][k]*C[aval][cho]%mod*C[bval][cho]%mod);
		}
	}
	for(i=0;i<=sumval[n];i++)
	Inc(ans,1ll*dp[n+1][i]*f[sumval[n]-i]%mod);
	
	cout<<ans<<endl;
	return 0;
}

