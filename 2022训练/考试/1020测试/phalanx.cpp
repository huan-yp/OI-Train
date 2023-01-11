#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define INF 1000000000
/*
complie options: -Wl,--stack=204800000 -std=c++14
*/
using namespace std;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch==45)ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename T1,typename T2>void cmax(T1 &x,const T2 &y){if(y>x)x=y;}
template<typename T1,typename T2>void cmin(T1 &x,const T2 &y){if(y<x)x=y;}
const int N=5e3+10;
int i,j,k,m,n,s,t;
int a[N];
int dp[2][N*2][3][4];
int ins(int x,int y){
	return x!=2&&y!=2&&x!=y;
}
int main(){
//	freopen("phalanx.in","r",stdin);
//	freopen("phalanx.out","w",stdout);
	read(t);
	while(t--){
		read(n);int cnt=0,cnt0=0;
		for(i=1;i<=n;i++)read(a[i]),cnt+=a[i]==2,cnt0+=a[i]==0;
		if(!cnt&&(cnt0!=0&&cnt0!=n)){
			puts("-1");
			continue;
		}
		if(cnt0==0||cnt0+cnt==n){
			puts("0");
			continue;
		}
		memset(dp,1,sizeof(dp));
		dp[0][N][2][0]=0;
		for(i=1;i<=n;i++){
			memset(dp[i&1],1,sizeof(dp[i&1]));
			for(j=N-i;j<=N+i;j++){
				for(int mask=0;mask<4;mask++){	
			//		cout<<(mask|((a[i]==2)?0:(1<<(a[i]))))<<' ';
					int tar=mask|((a[i]==2)?0:(1<<a[i]));
					for(int op:{0,1,2}){
						cmin(dp[i&1][j+(a[i]==2)][op][mask],dp[(i+1)&1][j][op][mask]+1);
						cmin(dp[i&1][j-ins(a[i],op)][a[i]][(op==2&&a[i]==2)?3:tar],dp[(i+1)&1][j][op][mask]);
					}
				}
			}
		}	
		int ans=1e9;
		for(int mask:{0,1,2,3})
		cmin(ans,dp[n&1][N][2][mask]);
		for(int op:{0,1,2})
		cmin(ans,dp[n&1][N][op][3]);
		for(i=N+1;i<=N+n;i++)for(int op=0;op<=2;op++)for(int mask=0;mask<4;mask++)
		cmin(ans,dp[n&1][i][op][mask]);
		cout<<ans<<endl;
	}
	return 0;
}

