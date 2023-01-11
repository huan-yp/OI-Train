#include<bits/stdc++.h>
#define LL long long
#define y1 y3647
#define pii pair<int,int>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;int f=1;
	while((ch<'0'||ch>'9')&&ch!=45)ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename _type>
void cmax(_type &x,const _type &y){x=max(x,y);}
template<typename _type>
void cmin(_type &x,const _type &y){x=min(x,y);}
const int N=105;
int i,j,k,m,n,s,t,mod;
long long dp[2][N][N*N*2];
void Inc(int &x,const int y){
	x+=y;if(x>=mod)x-=mod;
}
int main(){
//	freopen("permutation.in","r",stdin);
//	freopen("permutation.out","w",stdout);
	read(t);
	while(t--){
		read(n),read(mod);
		memset(dp,0,sizeof(dp));
		dp[0][0][N*N]=1;
		for(i=0;i<n;i++){
			int tar=i&1,limit=(i)*(i+1);
			for(j=0;j<=i&&j<=n-i;j++)
			memset(dp[tar^1][j],0,sizeof(dp[tar^1][j]));
			for(j=0;j<=i&&j<=n-i;j++){
				for(k=N*N-limit;k<=N*N+limit;k++){
					if(dp[tar][j][k]==0)continue;
					int val=dp[tar][j][k]%mod;
					if(j)dp[tar^1][j-1][k+2*i+2]+=1ll*val*j*j;
					dp[tar^1][j][k]+=1ll*val*((j<<1)+1);
					dp[tar^1][j+1][k-2*i-2]+=val;
				}		
			}
		}
		for(i=0;i<n*n;i++)printf("%d ",dp[n&1][0][N*N+i]%mod);
		printf("\n");
	}
	return 0;
}

