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
const int N=1024,mod=998244353;
int i,j,k,n,s,t,m;
int ans[N][N],dp[N][N],g[N];
void inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
}
signed main()
{
	//dp[k][i]=dp[k-1][i]+dp[k-1][i+1]+dp[k-1][]
 	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	//freopen(".in","w",stdout);
	read(n),read(k);
	ans[1][1]=1;g[1]=1;
	for(i=2;i<=n;i++){
		ans[i][0]=ans[i-1][1];
		ans[i][1]=ans[i-1][1]+ans[i-1][2];ans[i][1]%=mod;
		for(j=2;j<=i;j++){
			ans[i][j]=ans[i-1][j];
			inc(ans[i][j],ans[i-1][j-1]);
			inc(ans[i][j],ans[i-1][j+1]);
		}
		g[i]=ans[i][0];
	}
	dp[1][0]=1;
	for(i=2;i<=k;i++){
		int x,lim=min(n-(k-i)+2,n);
		for(j=i-1;j<=lim;j++)
		for(x=j-i+2;x>=1;x--){
			inc(dp[i][j],1ll*dp[i-1][j-x]*g[x]%mod);
		}
	}
	cout<<dp[k][n]<<endl;

	return 0;
}


