#include<bits/stdc++.h>
#define int long long 
using namespace std;
int i,j,k,m,n,s,t;
const int N=1e6+10;
int mod=998244353;
int quick(int aa,int ss)
{
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=ret*aa%mod;
		aa=aa*aa%mod;
		ss=ss>>1;
	}
	return ret;
}
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
int gcd(int aa,int bb)
{
	return bb==0?aa:gcd(bb,aa%bb);
}
struct fraction 
{
	int fz , fm ;
	fraction()
	{
		fm=100,fz=0;
	}
	fraction friend operator + ( fraction aa , fraction bb )
	{
		fraction ret;
		ret.fm = aa.fm * bb.fm % mod;
		ret.fz = ( aa.fz * bb.fm + aa.fm * bb.fz ) % mod; 
//		int tmp=gcd(ret.fz,ret.fm);
//		ret.fz/=tmp;
//		ret.fm/=tmp;
		return ret;
	}
	fraction friend operator - ( fraction aa , fraction bb )
	{
		fraction ret;
		ret.fm = aa.fm * bb.fm % mod;
		ret.fz = ( aa.fz * bb.fm - aa.fm * bb.fz ) % mod; 
//		int tmp=gcd(ret.fz,ret.fm);
//		ret.fz/=tmp;
//		ret.fm/=tmp;
		return ret;
	}  
	fraction friend operator * ( fraction aa , fraction bb )
	{
		fraction ret;
		ret.fm = aa.fm * bb.fm % mod;
		ret.fz = aa.fz * bb.fz % mod; 
//		int tmp=gcd(ret.fz,ret.fm);
//		ret.fz/=tmp;
//		ret.fm/=tmp;
		return ret;
	} 
};
fraction E;
struct fu{
	int v,next;
	fraction val;
}a[N];
fraction dp[N][2];
int pd[N],head[N],c[N];
void work(int aa,int bb,int cc)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].val.fz=100-cc;
	a[k].v=bb;
} 
void dfs(int u)
{
	dp[u][1].fz=1;
	dp[u][1].fm=1;
	if(pd[u]==0)
	dp[u][0].fz=1;
	dp[u][0].fm=1;
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		dfs(v);
//		if(pd[v])
//		{
//			dp[u][1]=dp[u][1]*dp[v][1]*a[i].val;
//			dp[u][0]=dp[u][0]*dp[v][1]*(E-a[i].val); 
//		}
//		else
//		{
			dp[u][1]=((dp[u][1]*dp[v][1])*a[i].val)+((dp[u][1]*dp[v][0])*(E-a[i].val)); 
			dp[u][0]=((dp[u][0]*dp[v][1])*(E-a[i].val))+((dp[u][0]*dp[v][0])*a[i].val);		
//		}
	}
} 
signed main()
{
	E.fz=1,E.fm=1;
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	scanf("%lld",&c[(i-1)*m+j]);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		int x;
		scanf("%lld",&x);
		if(i==1&&j==1)
		continue;
		if(i==n||i==1||j==1||j==m)
		pd[(i-1)*m+j]=1;
		if(c[(i-1)*m+j]==1)
		work((i-1)*m+j-1,(i-1)*m+j,x);
		else
		work((i-2)*m+j,(i-1)*m+j,x);
	} 
	dfs(1);
	printf("%lld",dp[1][1].fz*quick(dp[1][1].fm,mod-2)%mod);
	return 0;
}
