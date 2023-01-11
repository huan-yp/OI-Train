#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define low(x) ((x)&(-x))
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
const int mod = 1e9+7,N=100005;
int i,j,k,n,s,t,m;
map<int,int>f,g,h,H,G,F,F2,G2;
int inv[1005];
int quick(int a,int s)
{
	int ret=1;a%=mod;
	while(s)
	{
		if(s&1)ret=ret*a%mod;
		a=a*a%mod;
		s>>=1;
	}
	return ret;
}
int B(int x)
{
	x%=mod;
	return x*(x+1)%mod*(2*x+1)%mod*inv[6]%mod;
}
int T(int x)
{
	x%=mod;
	return x*(x+1)%mod*inv[2]%mod;
}
int solve(int x)
{
	if(x==0)return 0;
	if(x==1)return H[x]=h[x]=1;
	if(h[x]!=0)return h[x];
	int r=x>>1,l=x-r;
	int ret=(solve(l)+solve(r))%mod;
	solve(l-1);
	int fx,Fx,gx,Gx,Hx,F2x,G2x;
	int fl=f[l],fr=f[r],gl=g[l],gr=g[r];
	int Fl=F[l],Fr=F[r],Gl=G[l],Gr=G[r];
	int F2l=F2[l],F2r=F2[r],G2l=G2[l],G2r=G2[r];
	int Hl=H[l],Hr=H[r],hl=h[l];
	fx=fl+fr+l,gx=gl+gr+r;
	fx%=mod,gx%=mod;
	Fx=2*Fr+2*Fl+T(l)+T(r)-fl-1;Fx%=mod;
	F2x=4*F2r+2*B(r)+4*F2l+2*B(l)-T(l)-2*Fl-1-(2*(l%mod)-1)*fl+2*Fl-2*fl;F2x%=mod;
	G2x=4*G2r+2*B(r)+4*G2l+2*B(l)-2*Gl+l-3*T(l)-gl*(2*(l%mod)-1)+2*Gl-2*gl;G2x%=mod;
	Gx=2*Gl+2*Gr+T(r)+T(l-1)-gl;Gx%=mod;
	Hx=2*Hl+2*Hr+G2r+F2r-Fl+F2l+G2l+Gl-hl+T(x-1)-gl-gl*(l%mod);Hx%=mod;
	f[x]=fx,F[x]=Fx,g[x]=gx,G[x]=Gx,H[x]=Hx,F2[x]=F2x,G2[x]=G2x;
	ret+=fl*(r%mod)%mod;ret%=mod;
	ret+=gr*(l%mod)%mod;ret%=mod;
	ret+=x-1;ret%=mod;
	return h[x]=ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=1;i<=10;i++)
	inv[i]=quick(i,mod-2);
	read(t);
	while(t--)
	{
		int l,r;read(l),read(r);
		solve(r),solve(l-1);
		printf("%lld\n",(H[r]-H[l-1]+3*mod)%mod);
	}
	return 0;
}
