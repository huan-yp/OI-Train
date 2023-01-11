#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
const int mod=998244353,N=55,M=30;
int dp[2][N][200][M];
int g[N][M][N],C[N][N];
int n,m,K,s,t,k;
void solve(){
	int i,j,ans=0;
	for(i=0;i<N;i++)
	for(C[i][0]=1,j=1;j<=i;j++)
	C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	read(n),read(m),read(K);
	dp[1][1][1][1]=1;
	for(j=1;j<=n;j++)for(s=1;s*2<=j+1;s++)for(t=s;j+t<=n;t++){
		int val[]={1,mod-1},tar=0;
		for(i=0;i<=s;i++){
			g[j][s][t]=(g[j][s][t]+1ll*val[tar]
			*C[s][i]%mod*C[j+1-i*2][t])%mod;
			tar^=1;
		}
	}
	for(i=1;i<K;i++){
		memset(dp[(i+1)&1],0,sizeof(dp[0]));
		for(j=i;j<n;j++){
			auto dp=::dp[i&1];
			for(k=1;k+i+1<=m;k++)for(s=1;s*2<=j+1;s++){
				if(dp[j][k][s]==0)continue;
				for(t=s;j+t<=n&&k+t+j<=m;t++){
					int &tar=::dp[i+1&1][j+t][k+t+j][t];
					tar=(tar+1ll*dp[j][k][s]*g[j][s][t])%mod;
				}	
				int size=k+i+1,leaf=j+1,height=i+1;
				ans=(ans+1ll*(min(m-size,K-height)+1)*dp[j][k][s])%mod;
			}
		}
	}
	ans+=min(K,m),ans%=mod;
	cout<<ans<<endl;
}
int main()
{
	solve();
	return 0;
}


