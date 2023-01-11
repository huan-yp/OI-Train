#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define int long long
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
const int N=105,M=N*N,mod=998244353;
int i,j,k,m,n,s,t;
int dp[2][N][M],fr[N]={1},sum[M*2];
struct Bag{
	int f[2][N][M],a[N];
	void init(int ay[]){
		memcpy(a,ay,sizeof(a));
		f[0][0][0]=1;
		for(int i=0;i<n;i++){
			memset(f[(i+1)&1],0,sizeof(f[(i+1)&1]));
			for(int j=0;j<=i;j++)
			for(int k=0;k<=i*N;k++){
				(f[(i+1)&1][j][k]+=f[(i&1)][j][k])%=mod;
				(f[(i+1)&1][j+1][k+a[i+1]]+=f[(i&1)][j][k])%=mod;
			}
		}
	}
	void erase(int val,int res[N][M]){
		memcpy(res,f[n&1],sizeof(f[n&1]));
		for(int j=1;j<=n;j++)
		for(int k=val;k<=n*N;k++)
		(res[j][k]-=res[j-1][k-val])%=mod;
	}
	void get_result(int res[N][M]){
		memcpy(res,f[n&1],sizeof(f[n&1]));
	}
}B1,B2;
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int a[N],b[N];
	read(n),read(s);int ans=0;
	for(i=1;i<=n;i++)fr[i]=1ll*fr[i-1]*i%mod;
	for(i=1;i<=n;i++)read(a[i]);
	for(i=1;i<=n;i++)read(b[i]);
	B1.init(a),B2.init(b);
	B1.get_result(dp[0]);
	for(i=1;i<=n;i++){
		B2.erase(b[i],dp[1]);
		for(j=1;j<=n;j++){
			memset(sum,0,sizeof(sum));
			int tp=1ll*fr[j]*fr[n-j]%mod*fr[n-j]%mod*fr[j-1]%mod;
			//When calculate prefix sum,consider whehter or not it will access greater index 
			for(k=1;k<M*2;k++)sum[k]=sum[k-1]+dp[0][j][k],sum[k]%=mod;
			for(k=0;k<=(j-1)*N;k++){
				int maxn=s-k-1,minu=s-k-1-b[i];
				int val=(maxn>=0?sum[maxn]:0)-(minu>=0?sum[minu]:0);
				ans=(ans+1ll*dp[1][j-1][k]*tp%mod*val)%mod;
			}
		}
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}

