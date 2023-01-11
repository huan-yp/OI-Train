#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
using namespace std;
template<typename T>int read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
const int N=255,mod=1e9+7;
int i,j,k,m,n,s,t,A,B,T;
int C[N][N],p[7][N],ip[7][N];
LL dp[N][N][2],sum[N][N][2],ans[N][2];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;a=1ll*a*a%mod;
	}
	return ret;
}
void Inc(LL &x,LL y){x=(x+y)%mod;}
int calc(int t,int A,int i,int j){
	return 1ll*C[A-i][j-i]*ip[7-t][A-i]%mod*p[6-t][A-j]%mod;
}
signed main(){
//	freopen("dice.in","r",stdin);
//	freopen("dice.out","w",stdout);
	//freopen(".in","w",stdout);
	p[0][0]=ip[0][0]=1;
	for(j=1;j<=6;j++){
		p[j][0]=ip[j][0]=1;
		p[j][1]=j,ip[j][1]=quick(p[j][1],mod-2);
		for(i=2;i<N;i++)p[j][i]=1ll*p[j][i-1]*p[j][1]%mod,ip[j][i]=ip[j][i-1]*1ll*ip[j][1]%mod;
	}
	for(i=0;i<N;i++)
	for(C[i][0]=1,j=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	read(T),read(A),read(B);
	sum[0][0][0]=dp[0][0][0]=1;
	for(t=1;t<=6;t++){
		memset(dp,0,sizeof(dp));
		for(j=0;j<=B;j++){
			memset(ans,0,sizeof(ans));
			for(i=0;i<=A;i++){
				for(k=0;k<=j;k++){
					int tp=calc(t,B,k,j);
					ans[i][0]+=1ll*sum[i][k][0]*tp;
					ans[i][1]+=1ll*sum[i][k][1]*tp;
					if(k&8)ans[i][0]%=mod,ans[i][1]%=mod;
				}
				ans[i][0]%=mod,ans[i][1]%=mod;
				for(k=0;t<=T&&k<i;k++){
					if(j-(i-k)+1<0)continue;
					int tp=1ll*sum[k][j-(i-k)+1][0]*calc(t,B,j-(i-k)+1,j)%mod;
					Inc(ans[k][1],tp);
					Inc(ans[k][0],-tp);
				}
				for(k=0;k<=i;k++){
					int tp=calc(t,A,k,i);
					dp[i][j][0]+=1ll*ans[k][0]*tp;
					dp[i][j][1]+=1ll*ans[k][1]*tp;
					if(k&8)dp[i][j][0]%=mod,dp[i][j][1]%=mod;
				}
				dp[i][j][0]%=mod,dp[i][j][1]%=mod;
			}
		}
		memcpy(sum,dp,sizeof(dp));
	}	
	cout<<(dp[A][B][1]+mod)%mod<<endl;
	return 0;
}
