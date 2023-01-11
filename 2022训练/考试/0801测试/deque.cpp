#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type1,typename _type2>void cmin(_type1 &a,const _type2 b){if(a>b)a=b;}
template<typename _type1,typename _type2>void cmax(_type1 &a,const _type2 b){if(a<b)a=b;}
const int N=207+10,mod=1e9+7;
int i,j,k,n,s,t,m,tp1,tp2,ans;
int f[N],inv[N],p[N],dp[N][N];
int quick(int a,int s,int ret=1){
	while(s){
		if(s&1)ret=1ll*ret*a%mod;
		s>>=1;a=1ll*a*a%mod;
	}
	return ret;
}
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
}
int C(int n,int m){
	if(m<0||n<0||m>n)return 0;
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
// 	freopen("deque.in","r",stdin);
//	freopen("deque.out","w",stdout);
//	freopen(".in","w",stdout);

	read(n);f[0]=inv[0]=1,p[0]=1;
	for(i=1;i<=2*n+1;i++)f[i]=1ll*i*f[i-1]%mod,p[i]=2ll*p[i-1]%mod;
	inv[n+1]=quick(f[n+1],mod-2);
	for(i=n;i>=1;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	if(n<=2){
		printf("%d\n",1ll*f[n*2-2]*inv[n-1]%mod*inv[n-1]%mod);
		return 0;
	}
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	for(j=i;j<=n;j++){
		for(k=j;k>=i-1;k--)
		Inc(dp[i][j],dp[i-1][k]);
	}
	Inc(ans,dp[n-1][n-1]);
	for(i=1;i<n;i++){
		int sum=0;
//		Inc(ans,1ll*C(n-1,i)*C()%mod);
		for(j=n;j>=n-i+2;j--){
			Inc(sum,1ll*C(j-2,(i-1)-(n-j))*C(i-1,n-j));
		}
		j=n-i+1;
		Inc(sum,1ll*C(j-2,(i-1)-(n-j))*dp[n-j][n-j]);
		Inc(ans,1ll*sum*p[max(n-i-1,0)]%mod);
	}

	cout<<ans<<endl;
	return 0;
}
//1 2 6 20 70
//1
//1 2
//1 2 1
//1 3 3 1
//1 4 6 4 1
//1 5 10 10 5 1
//1 6 15 20 15 6 1


