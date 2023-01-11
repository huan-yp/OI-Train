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
const int N=1<<18,mod=998244353;
int i,j,k,n,s,t,m;
int rk[N],tmp[N],cnt[N],fa[N],f[N];
vector<int> e[N];
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod,s>>=1;
	}
	return ret;
}
struct poly{
	vector<int> a;int size=0,len;
	void resize(int x)
	{
		len=x;size=0;
		while(1<<size<len)size++;
		a.resize(1<<size);
	}
	void NTT(int type)
	{
		for(int i=1;i<1<<size;i++)rk[i]=rk[i>>1]>>1|(i%2?1<<size-1:0);
		for(int i=0;i<1<<size;i++)tmp[i]=a[rk[i]];
		for(int i=0;i<1<<size;i++)a[i]=tmp[i];
		for(int len=1;len<=size;len++)
		{
			int wn=quick(3,mod-1>>len),w=1;
			if(type==-1)wn=quick(wn,mod-2);
			for(int j=0;j+(1<<len)<=1<<size;j+=1<<len,w=1)
			for(int k=j;k<j+(1<<len-1);k++,w=1ll*w*wn%mod)
			{
				int x=a[k],y=a[k+(1<<len-1)];
				a[k]=(x+1ll*w*y)%mod,a[k+(1<<len-1)]=(x-1ll*w*y)%mod;
			}
		}
	}
}a,b;
poly operator *(poly a,poly b)
{
	int len=a.len+b.len-1;a.resize(len),b.resize(len);
	a.NTT(1),b.NTT(1);
	for(i=0;i<1<<a.size;i++)
	a.a[i]=1ll*a.a[i]*b.a[i]%mod;
	a.NTT(-1);int inv=quick(1<<a.size,mod-2);
	for(i=0;i<1<<a.size;i++)
	a.a[i]=1ll*a.a[i]*inv%mod;
	
	return a;
}
void dfs(int u)
{
	for(int v:e[u])
	{
		if(v==fa[u])continue;
		fa[v]=u;dfs(v);cnt[u]++;
	}
}
poly solve(int l,int r)
{
	if(l==r)
	{
		poly ret;ret.resize(2);
		ret.a[0]=1,ret.a[1]=cnt[l];
		return ret;
	}
	int mid=(l+r)/2;
	return solve(l,mid)*solve(mid+1,r);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);f[0]=f[1]=1;
	for(i=1;i<n;i++)
	{
		f[i+1]=1ll*f[i]*(i+1)%mod;int x,y;
		read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	dfs(1);
	auto tmp=solve(1,n);int ans=0;
	for(i=0;i<=n;i++)
	{
		if(i%2==0)
		ans=(ans+1ll*tmp.a[i]*f[n-i])%mod;
		else
		ans=(ans-1ll*tmp.a[i]*f[n-i])%mod;
	}
	cout<<(ans+mod)%mod;
	return 0;
}

