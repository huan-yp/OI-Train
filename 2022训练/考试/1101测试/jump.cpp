#include<bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=5005,M=18,mod=1e9+7;
int i,j,k,m,n,s,t;
int f[N][N],g[N][N],w[N][N],pre[N],ans[N];
char ch[N];
void DP(){
	memset(g,0,sizeof(g));
	memset(w,0,sizeof(w));
	w[n+1][0]=g[n+1][0]=f[0][0]=1;
	for(i=n;i>=1;i--){
		if(ch[i]=='R')for(j=0;j<=n-i+1;j++){
			g[i][j]=(1ll*g[i+1][j]*j+1ll*g[i+1][j+1]*(pre[i-1]-j))%mod;
			w[i][j]=(1ll*w[i+1][j]*j+1ll*w[i+1][j+1]*(pre[i-1]-j-1))%mod;
		}
		else for(j=0;j<=n-i+1;j++){
			g[i][j]=(1ll*j*g[i+1][j-1]+1ll*g[i+1][j]*(pre[i-1]-j))%mod;
			w[i][j]=(1ll*j*w[i+1][j-1]+1ll*w[i+1][j]*(pre[i-1]-j-1))%mod;
		}
	}
} 
signed main(){
	read(n);
	scanf("%s",ch+1);
	w[n+1][0]=g[n+1][0]=f[0][0]=1;
	for(i=1;i<=n;i++){
		pre[i]=pre[i-1]+(ch[i]=='R');
		if(ch[i]=='R')for(j=1;j<=i;j++){
			f[i][j]=(1ll*f[i-1][j]*j+1ll*f[i-1][j-1]*(pre[i]-j+1))%mod;
		}
		else for(j=1;j<=i;j++){
			f[i][j]=(1ll*j*f[i-1][j+1]+1ll*f[i-1][j]*(pre[i]-j+1))%mod;
		}
	}
	DP();
	for(i=1;i<=n;i++){
		pre[i]++;
		if(ch[i]=='L')continue;
		for(j=0;j<=n;j++)ans[i]=(ans[i]+1ll*f[i-1][j]*(g[i+1][j]+w[i+1][j-1]))%mod;
	}
	DP();
	for(i=1;i<=n;i++){
		if(ch[i]=='R')continue;
		for(j=0;j<=i;j++)ans[i]=(ans[i]+1ll*f[i-1][j]*(g[i+1][j]+w[i+1][j-1]))%mod;
	}
	for(i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}

