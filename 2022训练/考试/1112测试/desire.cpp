#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename T>
inline int read(T &x){
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*=f;
}
template<typename T1,typename T2>void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2>void cmax(T1 &a,const T2 &b){if(a<b)a=b;}
const int N=758;
int n,m;
int dp[N][N],a[N],sum[N];
void ___solve(){
	int i,j;
	read(n);
	if(n==1)return void(puts("0"));
	for(i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1,[](const int &a,const int &b){return a>b;});
	for(i=n;i>=1;i--)sum[i]=sum[i+1]+a[i];
	memset(dp,0x6f,sizeof(dp));
	dp[1][1]=sum[1];
	for(i=0;i<n;i++){
		auto f=dp;
		for(int k=0;k<=n-i;k++)
		for(j=0;j+k<=n-i;j++)
		cmin(f[j+k][k],f[k][j]+sum[i+1]);
		for(int k=0;k<=n-i;k++)
		memcpy(dp[k],dp[k+1],sizeof(dp[k+1]));
	}
	int ans=2e9+10;
	for(j=0;j<=n;j++)for(int k=0;k<=n;k++)
	cmin(ans,dp[j][k]);
	cout<<ans<<endl;
}
signed main()
{
	freopen("desire.in","r",stdin);
	freopen("desire.out","w",stdout);
//	freopen(".in","w",stdout);
	int tot=1;
//	read(tot);
	while(tot--){
		___solve();
	}
	return 0;
}


