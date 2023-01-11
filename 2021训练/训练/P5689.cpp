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
const int N=3e5+10,mod=1e9+7;
int i,j,k,n,s,t,m,ans;
int size[N],dp[N],fa[N],f[N]={1},inv[N]={1};
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int C(int n,int m)
{
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)ret=ret*a%mod;
		a=a*a%mod;
		s>>=1;
	}
	return ret;
}
void merge(int u,int v)
//mrege v to u
{
	u=find(u),v=find(v);
	fa[v]=u;size[u]+=size[v];
	dp[u]=C(size[u]-1,size[v])*dp[v]%mod*dp[u]%mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=0;i<n;i++)
	fa[i]=i,dp[i]=size[i]=1;
	
	for(i=1;i<=n;i++)
	f[i]=f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<=m;i++)
	{
		int x,y,op;
		read(op);
		if(op==1)
		{
			read(x),read(y),x+=ans,y+=ans;x%=n,y%=n;
			merge(y,x);
		}
		else
		{
			read(x),x+=ans;x%=n;
			printf("%lld\n",ans=dp[find(x)]);
		}
	}
	return 0;
}

