#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=(1<<21)+10,mod=998244353;
int i,j,k,n,s,t,m,ans;
int a[N],b[N],f[21][N],g[N],val[N],c[N],fun[N],inv[N],eat[N],ok[N];
int C(int n,int m){
	return 1ll*fun[n]*inv[m]%mod*inv[n-m]%mod;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	fun[0]=inv[0]=1;
	for(i=1;i<N;i++)fun[i]=1ll*fun[i-1]*i%mod,inv[i]=quick(fun[i],mod-2);
	read(n),read(m);
	
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=m;i++)read(b[i]);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	read(s),val[j]|=s<<i-1;
	
	for(i=1;i<=m;i++)f[n][val[i]]+=b[i];
	
	for(i=n-1;i>=0;i--)
	for(int mask=0;mask<1<<n;mask++){
		f[i][mask]=f[i+1][mask];
		if(1<<i&mask)f[i][mask]+=f[i+1][mask^(1<<i)];
	}
	for(int mask=0;mask<1<<n;mask++)
	for(i=1;i<=n;i++)
	if(1<<i-1&mask)g[mask]+=a[i];
	
	int minu=INF,all=1<<n;all--;
	for(int mask=0;mask<1<<n;mask++)if(f[0][mask])cmin(minu,eat[mask]=g[mask]-f[0][mask]+1);
	
	if(minu<=0){
		printf("0 1\n");
		return 0;
	}
	printf("%d ",minu);
	//f[mask]=
	//f'[mask]=
	//f[mask]=f'[mask]-\sum
	
	for(int mask=0;mask<1<<n;mask++)f[n][mask]=C(g[mask],minu);
	for(i=n-1;i>=0;i--)
		for(int mask=0;mask<1<<n;mask++){
		f[i][mask]=f[i+1][mask];
		if(1<<i&mask)f[i][mask]-=f[i+1][mask^(1<<i)],f[i][mask]%=mod;	
	}
	for(int mask=(1<<n)-1;mask;mask--){
		if(eat[mask]==minu)ok[mask]=1;
		for(i=1;i<=n;i++)
		if((1<<i-1)&mask)ok[mask^(1<<i-1)]|=ok[mask];
	}
	for(int mask=0;mask<1<<n;mask++)
	if(ok[mask])ans+=f[0][mask],ans%=mod;
	
	cout<<(ans+mod)%mod<<endl;
	
	return 0;
}

