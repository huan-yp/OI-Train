#include<bits/stdc++.h>
#define INF 1000000000
#define int long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>void cmax(_type &a,_type b){a=max(a,b);}
const int N=255,mod=998244353;
int i,j,k,n,s,t,m;
int dp[N][N],C[N][N],sum[N];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
	if(x<0)x+=mod;
}
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=ret*a%mod;
		a=a*a%mod;s>>=1;
	}
	return ret;
}
int Sum(int l,int r){
	return (r-l+1)*(r+l)/2;
}
signed main()
{
 	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	read(n),read(k);
	for(i=0;i<N;i++)
	for(C[i][0]=1,j=1;j<=i;j++)
	C[i][j]=C[i-1][j],Inc(C[i][j],C[i-1][j-1]);
	
	dp[0][0]=1;
	for(i=0;i<n;i++){
		sum[0]=dp[i][0];
		for(j=1;j<=k;j++)sum[j]=sum[j-1]+dp[i][j],sum[j]%=mod;
		for(j=i+1;j<n;j++){
			for(s=1;s<=k;s++)
			Inc(dp[j][s],sum[s-1]*C[n-i-1][j-i]%mod*quick(k-s+1,Sum(i,j-1))%mod);
		}
	}
	int ans=0;
	for(i=1;i<=k;i++)Inc(ans,dp[n-1][i]);
	cout<<ans<<endl;
	return 0;
}


