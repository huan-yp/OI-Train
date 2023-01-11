#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1e4+10,M=25,mod=1e9+7;
int i,j,k,m,n,s,t,ans;
int dp[N][M],pw[M][N],C[M][M],pa[M][M],a[N],f[N];
char ch[N];
int* get_des_pow(int start,int k){
	int* a=new int[M];memset(a,0,sizeof(int)*M);a[0]=1;
	for(int i=1;i<=k;i++,start--){
		for(int j=i;j>=1;j--)
		a[j]=(a[j-1]+1ll*a[j]*start)%mod;
		a[0]=1ll*a[0]*start%mod;
	}
	return a;
}
int solve(int* a,int* x){
	int pre=0,prod=1,ret=0;
	int *ans=new int[M];memcpy(ans,dp[n+3],sizeof(int)*M);
	for(i=n+3;i>=1;i--){
		int *w=new int[M];memset(w,0,sizeof(int)*M);
		for(s=0;s<=a[i]-1;s++)
		for(int p=1,j=0;j<=k;j++){
			w[j]=(w[j]+1ll*max(s,1)*p%mod)%mod;
			p=1ll*p*((pre*10ll%mod+s)*pw[10][i-1]%mod)%mod;
		}
		for(j=0;j<=k;j++)w[j]=1ll*w[j]*prod%mod;
		for(j=0;j<=k&&a[i];j++)
		for(s=0;s<=j;s++)	
		ans[j]=(ans[j]-1ll*C[j][s]*w[j-s]%mod*dp[i-1][s])%mod;
		
		prod=1ll*prod*max(1,a[i])%mod,pre=(10ll*pre+a[i])%mod;
	}
	for(i=0;i<k;i++)ret=(ret+1ll*ans[i]*x[i])%mod;	
	return ret;
}
void init(){
	f[0]=1;scanf("%s",ch+1);n=strlen(ch+1);
	for(i=1;i<=n;i++)a[i]=ch[n-i+1]-'0';
	for(i=1;i<N;i++)f[i]=1ll*f[i-1]*i%mod;
	for(i=0;i<=10;i++)for(pw[i][0]=1,j=1;j<N;j++)
	pw[i][j]=1ll*pw[i][j-1]*i%mod;
	for(i=0;i<M;i++)
	for(C[i][0]=1,j=1;j<M;j++)
	C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	
	pa[0][0]=1;
	for(i=1;i<=9;i++)
	for(j=0;j<M;j++)
	pa[i][j]=(pa[i-1][j]+1ll*pw[i][j]*i)%mod;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
signed main(){
//	freopen("ke.in","r",stdin);
//	freopen("ke.out","w",stdout);
	cin>>k;
	int* b=new int[N];
	init();dp[0][0]=1;
	memcpy(b,a,sizeof(a));
	for(i=1;i<=n+3;i++){
		for(j=0;j<=k;j++)
		for(s=0;s<=j;s++)
		dp[i][j]=(dp[i][j]+1ll*dp[i-1][s]*C[j][s]%mod*pw[10][s]%mod*pa[9][j-s])%mod;
	}
	memset(a,0,sizeof(a));
	for(int i=0;i<=k;i++){
		int val=0;
		for(int i=n+3;i>=1;i--)val=(val*10ll+a[i])%mod;
		int ret=solve(a,get_des_pow(k-1-val,k-1));
		ans=(ans+ret*(i%2?-1ll:1ll)*C[k][i])%mod;a[1]++;
		for(int i=1;i<=n+3;i++)a[i]=a[i]+b[i],a[i+1]+=a[i]/10,a[i]%=10;
	}
	cout<<1ll*(ans+mod)%mod*quick(f[k-1],mod-2)%mod<<endl;
	return 0;
}

