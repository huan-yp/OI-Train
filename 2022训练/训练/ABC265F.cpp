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
const int N=105,M=1005,mod=998244353;
int i,j,k,n,s,t,m,d;
int dp[2][M][M],p[N],q[N],tmp[M][M];
void Inc(int &x,const int &y){
	x+=y;if(x>=mod)x-=mod;
}
void Dec(int &x,const int &y){
	x-=y;if(x<0)x+=mod;
}
signed main()
{
	read(n),read(d);
	dp[0][0][0]=1;
	for(i=1;i<=n;i++)read(p[i]);
	for(i=1;i<=n;i++)read(q[i]);
	for(i=0;i<n;i++){
		memset(dp[i+1&1],0,sizeof(dp[i+1&1]));
		
		int dis=abs(p[i+1]-q[i+1]);
		for(j=dis;j<=2*d;j++){
			int base=max(0,j-d);
			for(k=0;k<=dis&&k<=base;k++){
				if(j-base-(dis-k)>=0)
				Inc(dp[i+1&1][base][j-base],dp[i&1][base-k][j-base-(dis-k)]);
			}
			for(k=base+1;k<=d&&j-k<=d&&k<=j;k++){
				dp[i+1&1][k][j-k]=dp[i+1&1][k-1][j-k+1];
				if(j-k-dis>=0)Inc(dp[i+1&1][k][j-k],dp[i&1][k][j-k-dis]);
				if(k-1-dis>=0)Dec(dp[i+1&1][k][j-k],dp[i&1][k-1-dis][j-k+1]);
			}
		}
		memset(tmp,0,sizeof(tmp));
		for(j=-d;j<=d;j++){
			int base=max(0,-j);
			for(k=base;k<=d&&k+j<=d;k++){
				if(k&&k+j-1>=0)tmp[k][k+j]=tmp[k-1][k+j-1];
				if(k+j>=dis)Inc(tmp[k][k+j],dp[i&1][k][k+j-dis]);
				if(k>=dis)Inc(tmp[k][k+j],dp[i&1][k-dis][k+j]);	
			}
		}
		for(j=0;j<=d;j++)
		for(k=0;k<=d;k++)
		{
			Inc(dp[i+1&1][j][k],tmp[j][k]);
			if(j>=dis)Dec(dp[i+1&1][j][k],dp[i&1][j-dis][k]);
			if(k>=dis)Dec(dp[i+1&1][j][k],dp[i&1][j][k-dis]);	
		}
	}
	int ans=0;
	for(i=0;i<=d;i++)
	for(k=0;k<=d;k++)
	Inc(ans,dp[n&1][i][k]);
	
	cout<<ans<<endl;
	return 0;
}


