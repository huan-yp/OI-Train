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
const int N=5e5+10,mod=998244353;
int i,j,k,n,s,t,m,ans;
int w[N],fa[N],vis[N],f[N]={1},inv[N]={1},r[N];
vector<int> e[N];
void dfs(int u)
{
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
	}
}
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)
		ret=1ll*ret*a%mod;
		s>>=1;
		a=1ll*a*a%mod;
	}bf
	return ret;
}
int C(int n,int m)
{
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
void init()
{
	for(i=1;i<=max(sqrt(n)*3,100.0);i++)
	{
		for(k=1;k<=i;k++)
		{
			r[i]+=1ll*C(i-1,k-1)*C(i,k)%mod*f[i-k]%mod;
			r[i]%=mod;
		}
	}
}
void calc(int x,int dis)
{
	if(x==0)return;
	ans+=1ll*r[dis]*w[x]%mod*C(n,dis)%mod*f[n-dis]%mod;
	ans%=mod;
	calc(fa[x],dis+1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(i=1;i<=n;i++)read(w[i]);
	
	for(i=1;i<N;i++)
	f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);;
	
	dfs(1);
	init();
	for(i=1;i<=n;i++)
	calc(i,1),ans+=1ll*f[n]*w[i]%mod,ans%=mod;
	
	printf("%d\n",ans);
	return 0;
}

