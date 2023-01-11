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
const int N=405,mod=998244353; 
int i,j,k,n,s,t,m,ans;
int dp[N][N],C[N*2][N*2],a[N][N];
vector<pair<int,int>> e[N*N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".in","w",stdout);
	read(n);
	for(i=0;i<N*2;i++){
		C[i][0]=1;
		for(j=1;j<=i;j++)
		C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++){
		read(a[i][j]);
		e[a[i][j]].push_back(make_pair(i,j));
	}
	for(i=1;i<=n*n;i++){
		if(e[i].size()<=0)continue;
		if(e[i].size()<=n){
			for(j=0;j<e[i].size();j++)
			for(k=0;k<e[i].size();k++){
				auto [x1,y1]=e[i][j];
				auto [x2,y2]=e[i][k];
				if(x2<x1||y2<y1)continue;
				ans+=C[x2+y2-x1-y1][y2-y1],ans%=mod;
			}
		}
		else{
			memset(dp,0,sizeof(dp));
			for(auto x:e[i])dp[x.first][x.second]=1;
			for(j=1;j<=n;j++)
			for(k=1;k<=n;k++){
				if(j!=1)dp[j][k]+=dp[j-1][k],dp[j][k]%=mod;
				if(k!=1)dp[j][k]+=dp[j][k-1],dp[j][k]%=mod;
				if(a[j][k]==i)ans+=dp[j][k],ans%=mod;
			}
		}
	}


	cout<<ans<<endl;
	return 0;
}


