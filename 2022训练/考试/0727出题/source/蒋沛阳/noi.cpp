#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define ll long long
#define pii pair<int,int>
#define N 155
#define M 505
#define INF 0x3f3f3f3f
using namespace std;
template<typename T>inline void chmax(T &a,T b){a=max(a,b);}
template<typename T>inline void chmin(T &a,T b){a=min(a,b);}
int n,m,a[N][M],sum[N][M],dp[2][12][N][N],tmp[N];
int main(){
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		sum[i][0]=0;
		for(int j=1;j<=n;j++){
			sum[i][j]=sum[i][j-1]+a[j][i];
		}
	}
	for(int i=0;i<2;i++){
		for(int j=0;j<=10;j++){
			for(int l=0;l<=n;l++){
				for(int r=0;r<=n;r++){
					dp[i][j][l][r]=-INF;
				}
			}
		}
	}
	int ans=-INF,cur=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<=10;j++){
			for(int l=0;l<=n;l++){
				for(int r=0;r<=n;r++){
					dp[cur][j][l][r]=-INF;
				}
			}
		}
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				chmax(dp[cur][0][l][r],sum[i][r]-sum[i][l-1]);
				chmax(dp[cur][0][l][r],dp[cur^1][0][l][r]+sum[i][r]-sum[i][l-1]);
				chmax(dp[cur][1][l][r],dp[cur^1][1][l][r]+sum[i][r]-sum[i][l-1]);
				chmax(dp[cur][2][l][r],dp[cur^1][2][l][r]+sum[i][r]-sum[i][l-1]);
				chmax(dp[cur][3][1][1],dp[cur^1][2][l][r]);
				chmax(dp[cur][3][l][r],dp[cur^1][3][l][r]);
				if(r-l+1>=3){
					chmax(dp[cur][4][l][r],dp[cur^1][3][1][1]+sum[i][r]-sum[i][l-1]);
					chmax(dp[cur][5][l][r],dp[cur^1][5][l][r]+a[l][i]+a[r][i]);
					chmax(dp[cur][5][l][r],dp[cur^1][4][l][r]+a[l][i]+a[r][i]);
					chmax(dp[cur][6][l][r],dp[cur^1][5][l][r]+sum[i][r]-sum[i][l-1]);
				}
				chmax(dp[cur][7][1][1],dp[cur^1][6][l][r]);
				chmax(dp[cur][7][l][r],dp[cur^1][7][l][r]);
				if(r-l+1>=3){
					chmax(dp[cur][8][l][r],dp[cur^1][7][1][1]+a[l][i]+a[r][i]);
					chmax(dp[cur][8][l][r],dp[cur^1][8][l][r]+a[l][i]+a[r][i]);
					chmax(dp[cur][9][l][r],dp[cur^1][8][l][r]+sum[i][r]-sum[i][l-1]);
					chmax(dp[cur][9][l][r],dp[cur^1][9][l][r]+sum[i][r]-sum[i][l-1]);
					chmax(dp[cur][10][l][r],dp[cur^1][9][l][r]+a[l][i]+a[r][i]);
					chmax(dp[cur][10][l][r],dp[cur^1][10][l][r]+a[l][i]+a[r][i]);
				}
			}
			for(int l=n;l>=1;l--){
				int mx=-INF;
				for(int r=n;r>=l;r--){
					chmax(dp[cur][1][l][r],mx+sum[i][r]-sum[i][l-1]);
					chmax(mx,dp[cur^1][0][l][r]);
				}
			}
			for(int r=n;r>=1;r--){
				int mx=-INF;
				for(int l=r;l>=1;l--){
					chmax(dp[cur][2][l][r],mx+sum[i][r]-sum[i][l-1]);
					chmax(mx,dp[cur^1][1][l][r]);
				}
			}
			memset(tmp,-0x3f,sizeof(tmp));
			for(int r=1;r<=n;r++){
				int mx=-INF;
				for(int l=1;l<=r+1;l++){
					chmax(mx,dp[cur^1][1][l][r]);
					chmax(tmp[l],mx);
					if(l>r)continue;
					chmax(dp[cur][1][l][r],tmp[l]+sum[i][r]-sum[i][l-1]);
				}
			}
		}
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				chmax(ans,dp[cur][10][l][r]);
			}
		}
		cur^=1;
	}
	printf("%d\n",ans);
	return 0;
	
}
/*
Basic:
1. int or long long?
2. freopen?
3. memory limits?
Advanced:
1. use more functions
2. write carefully and check
3. think twice before writing
4. debug quickly
5. never copy others' codes
*/
