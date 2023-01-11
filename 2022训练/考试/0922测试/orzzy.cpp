#include<bits/stdc++.h>
#define INF 1000000000
#define y1 y3647
#define int long long
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch>'9'||ch<'0')&&ch!=45)ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
const int N=305,mod=998244353;
int dp[N][N],sum[N][N],a[N];
int i,j,k,m,n,s,t;
signed main(){
	read(n),read(k);
	for(i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	dp[0][0]=1;a[n+1]=2*INF;
	for(i=n;i>=1;i--){
		for(s=0;s<=k;s++)sum[0][s]=dp[0][s];
		
		for(j=1;j<=k;j++)
		for(s=0;s<=k;s++)
		sum[j][s]=(sum[j-1][s]+dp[j][s])%mod;
		
		memset(dp,0,sizeof(dp));
		for(j=0;j<=k;j++)
		for(s=j;s<=k;s++){
			int lst=j+a[i]-a[i+1];
			if(lst<=0)
			dp[j][s]=sum[s-j][s-j];
			else
			dp[j][s]=sum[s-j][s-j]-sum[lst-1][s-j];
			
			dp[j][s]%=mod;
		}
	}
	int ans=0;
	for(i=0;i<=k;i++)ans=(ans+dp[i][k])%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}

