#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int N=305,M=N*N,mod=998244353;
int i,j,k,m,n,s,t;
int a[N],dp[2][2*M];
void read(int &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	t=1;
	while(t--){
		read(n);
		for(i=1;i<=n;i++)read(a[i]);
		dp[0][M+a[2]]=1;
		for(i=2;i<n;i++){
			memset(dp[i+1&1],0,sizeof(dp[0]));
			for(j=M-300*i;j<=M+300*i;j++)if(dp[i&1][j]){
				int val=j-M;
				dp[i+1&1][M+(a[i+1]-val)]=(dp[i+1&1][M+(a[i+1]-val)]+dp[i&1][j])%mod;
				if(val!=0)dp[i+1&1][M+(a[i+1]+val)]=(dp[i+1&1][M+(a[i+1]+val)]+dp[i&1][j])%mod;
			}
		}
		int ans=0;
		for(i=1;i<2*M;i++)ans=(ans+dp[n&1][i])%mod;
		cout<<ans<<endl;
	}
	return 0;
} 
