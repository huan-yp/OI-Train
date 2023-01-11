#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=55,mod=998244353;
int i,j,k,n,s,t,m,q,a,b;
int dp[N][N],f[N*N],inv[N*N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
int C(int n,int m){
	if(m>n||n<0||m<0)return 0;
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//dp[n][m][a][b]=;
	memset(dp,0,sizeof(dp));
	f[0]=inv[0]=1;
	read(n),read(m),read(a),read(b);
	for(i=1;i<=n*m;i++)f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	
	//还有 i 行，j 列没放白色，白色剩下 k 个 
	//dp[i][j][k]
	for(i=0;i<=n;i++)
	for(j=0;j<=m;j++){
		for(int i1=0;i1<=i;i1++)
		for(int j1=0;j1<=j;j1++)
		dp[i][j]+=((i-i1+j-j1)&1?-1ll:1ll)*C(i,i1)*C(j,j1)%mod*C(i1*j1,a)%mod,dp[i][j]%=mod;
	}
	int ans=0;
	for(i=0;i<=n;i++)
	for(j=0;j<=m;j++){
		ans+=1ll*dp[i][j]*C(m,j)%mod*C(n,i)%mod*C((n-i)*(m-j),b)%mod;
		ans%=mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}

