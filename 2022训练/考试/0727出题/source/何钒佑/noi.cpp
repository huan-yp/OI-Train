#include<bits/stdc++.h>
using namespace std;
int n,m,a[160][510],dp[3][160][160],s[160],f[3][160][160];
int mx[160],qz[510],qz2[510],ans;
void ad(int &a,int b){a=max(a,b);}
const int I=1e9;
int main(){
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	memset(dp,-0x3f,sizeof(dp));
	memset(f,-0x3f,sizeof(f));
	memset(qz,-0x3f,sizeof(qz));
	memset(qz2,-0x3f,sizeof(qz2));
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i][k];
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
			f[0][i][j]=0;
			for(int p=0;p<3;p++)ad(f[p][i][j],dp[p][i][j]);
		}
		for(int i=1;i<=n;i++)mx[i]=-I;
		for(int j=n;j;j--){
			int M=-I;
			for(int i=j;i;i--)ad(mx[i],dp[1][i][j]),ad(M,mx[i]),ad(f[1][i][j],M);
		}
		for(int j=2;j<=n;j++){
			int M=-I;
			for(int i=1;i<j;i++)ad(M,dp[1][i][j-1]);
			for(int i=j;i<=n;i++)ad(f[1][j][i],M);
		}
		for(int i=1;i<n;i++){
			int M=-I;
			for(int j=n;j>i;j--)
				M=max(M,dp[0][i][j]),
				ad(f[1][i][j-1],M);
		}
		for(int j=2;j<=n;j++){
			int M=-I;
			for(int i=j;i>=2;i--){
				M=max(M,dp[1][i][j]);
				ad(f[2][i-1][j],M);
			}
		}
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
			for(int p=0;p<3;p++)dp[p][i][j]=f[p][i][j]+s[j]-s[i-1],f[p][i][j]=-I;
			qz[k]=max(qz[k],dp[2][i][j]);
		}
		qz[k]=max(qz[k],qz[k-1]);
	}
	memset(dp,-0x3f,sizeof(dp));
	for(int k=2;k<=m;k++){
		qz2[k]=qz2[k-1];
		for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i][k];
		for(int i=1;i<=n;i++)for(int j=i+2;j<=n;j++){
			int f0,f1,f2;
			f0=s[j]-s[i-1]+qz[k-2];
			f1=max(dp[1][i][j],dp[0][i][j])+a[i][k]+a[j][k];
			f2=dp[1][i][j]+s[j]-s[i-1];
			dp[0][i][j]=f0,dp[1][i][j]=f1,dp[2][i][j]=f2;
			qz2[k]=max(qz2[k],f2);
		}
	}
	ans=-I;
	memset(dp,-0x3f,sizeof(dp));
	for(int k=2;k<=m;k++){
		for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i][k];
		for(int i=1;i<=n;i++)for(int j=i+2;j<=n;j++){
			int f0,f1,f2;
			f0=a[i][k]+a[j][k]+max(qz2[k-2],dp[0][i][j]);
			f1=s[j]-s[i-1]+max(dp[0][i][j],dp[1][i][j]);
			f2=a[i][k]+a[j][k]+max(dp[1][i][j],dp[2][i][j]);
			dp[0][i][j]=f0,dp[1][i][j]=f1,dp[2][i][j]=f2;
			ans=max(ans,f2);
		}
	}
	return printf("%d",ans),0;
}
