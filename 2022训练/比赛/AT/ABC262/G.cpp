#include<bits/stdc++.h>
#define y1 y3647
#define INF 1000000000
#define LL long long
#define elif else if
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
const int N=55;
int i,j,k,n,s,t,m,tp1,tp2,ans;
int dp[2][N][N][N][N],a[N];
signed main()
{
// 	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen(".in","w",stdout);
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	memset(dp,191,sizeof(dp));
	dp[0][0][0][0][0]=0;
	for(i=0;i<=n;i++){
		memset(dp[i+1&1],191,sizeof(dp[i+1&1]));
		for(k=i;k>=1;k--)
		for(j=0;j<=i;j++)
		for(s=0;s<=i;s++)
		for(t=0;t<=i;t++){
			if(dp[i&1][j][k][s][t]<0)continue;
			if(k)
			if(a[j]<=a[t])cmax(dp[i&1][s][0][0][0],dp[i&1][j][k][s][t]+k);
			cmax(ans,dp[i&1][j][k][s][t]);
		}
		for(j=0;j<=i;j++)
		for(k=0;k<=i;k++)
		for(s=0;s<=i;s++)
		for(t=0;t<=i;t++){
			if(dp[i&1][j][k][s][t]<0)continue;
			cmax(dp[i+1&1][j][k][s][t],dp[i&1][j][k][s][t]);
			if(k==0)cmax(dp[i+1&1][j][1][i+1][i+1],dp[i&1][j][k][s][t]);
			elif(a[i+1]<=a[t])cmax(dp[i+1&1][j][k+1][s][i+1],dp[i&1][j][k][s][t]);
		}
	}
	cout<<ans<<endl;
	return 0;
}


