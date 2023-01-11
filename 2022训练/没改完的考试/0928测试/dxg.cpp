#include<bits/stdc++.h>
#define digit(x,y) ((x)/p[(y)-1]%6)
using namespace std;
template<typename T>
int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=1.2e7,M=15,T=1e5+10,mod=998244353;
int i,j,k,m,n,s,t,ans;
int dp[N],cnt[T],p[M],f[T],inv[T];
char ch[T];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod,s>>=1;
	}
	return ret;
}
int legal(int x){
	while(x){if(x%6==1)return 0;x/=6;}return 1;
}
int C(int n,int m){
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int solve(int m,int x){
	if(x==0)return m==0;
	return C(m+x-1,x-1);
}
int main(){
//	freopen("dxg.in","r",stdin);
//	freopen("dxg.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n);f[0]=inv[0]=p[0]=1;
	scanf("%s",ch+1);
	for(i=1;i<=n;i++)f[i]=1ll*i*f[i-1]%mod,inv[i]=quick(f[i],mod-2);
	for(i=1;i<=n;i++){
		if(ch[i]=='?')m++;
		else cnt[ch[i]-'0']++;
	}
	for(i=1;i<=9;i++)p[i]=p[i-1]*6;
	for(int mask=0;mask<p[9];mask++){
		int rm=m,flag=0,all=0;
		for(i=1;i<=9;i++){
			int d=digit(mask,i);
			if(d<5){
				flag|=cnt[i]>d;	
				rm-=d-cnt[i];
			}
			else{
				if(cnt[i]<=5)rm-=5-cnt[i];
				all++;	
			}
		}
		if(legal(mask))dp[mask]=1;
		else{
			for(i=2;i<=8;i++)
			if(min(digit(mask,i),min(digit(mask,i-1),digit(mask,i+1)))==1)
			dp[mask]|=dp[mask-p[i-1]-p[i-2]-p[i]];
		}	
		if(flag||rm<0)continue;	
		if(dp[mask])
		ans+=solve(rm,all),ans%=mod;
		
	}
	cout<<ans<<endl;
	return 0;
}

