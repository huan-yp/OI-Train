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
const int N=55,mod=998244353;
int cnt[N],f[N],C[N][N],inv[N],in[N];
int i,j,k,n,s,t,m,ans;
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
int gcd(int x,int y)
{
	x=abs(x),y=abs(y);
	if(y>x)swap(x,y);
	if(y==0)return x;
	return gcd(y,x%y);
}
int lcm(int x,int y)
{
	return x/gcd(x,y)*y;
}
void dfs(int dep,int now)
{
	if(now==0)
	{
		int gc=1,sum=1,s=n;
		for(int i=1;i<=50;i++)
		{
			if(cnt[i]==0)continue;
			gc=lcm(gc,i);
			for(int j=1;j<=cnt[i];j++)
			sum=1ll*sum*C[s][i]%mod*f[i]%mod*in[i]%mod,s-=i;
			sum=1ll*sum*inv[cnt[i]]%mod;
		}
		ans+=1ll*sum*quick(gc,k)%mod;
		t+=sum;t%=mod;
		ans%=mod;
		return ;
	}	
	if(dep>now)return ;
	for(int i=0;i*dep<=now;i++)
	{
		cnt[dep]=i;
		dfs(dep+1,now-i*dep);
		cnt[dep]=0;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	C[0][0]=1;
	for(i=1;i<=50;i++)
	{
		C[i][0]=1;
		for(j=1;j<=50;j++)
		C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	read(n),read(k);f[0]=1;
	for(i=1;i<=n;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2),in[i]=quick(i,mod-2);
	
	dfs(1,n);
	cout<<ans<<endl;
//	cout<<t<<' '<<f[n]<<endl;
	return 0;
}

