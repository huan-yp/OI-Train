#include<bits/stdc++.h>
#define int long long
#define N 155
using namespace std;
const int INF=1e18;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<48){if(c=='-')f=0;c=getchar();}
	while(c>=48) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
int n,m,a[505][N];
int dp1[N][N],dp2[N][N],dp3[N][N],dp4,dp5[N][N],dp6[N][N],dp7[N][N],dp8,dp9[N][N],dp10[N][N],dp11[N][N],dp12; 
int f[N],f1[N][N],f2[N][N];
signed main(){
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) a[j][i]=read();
	memset(dp1,128,sizeof(dp1));memset(dp2,128,sizeof(dp2));memset(dp3,128,sizeof(dp3));memset(dp5,128,sizeof(dp5));memset(dp6,128,sizeof(dp6));memset(dp7,128,sizeof(dp7));memset(dp9,128,sizeof(dp9));memset(dp10,128,sizeof(dp10));memset(dp11,128,sizeof(dp11));
	memset(f1,128,sizeof(f1));memset(f2,128,sizeof(f2));
	dp4=dp8=dp12=-INF;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++) f[i]=f[i-1]+a[j][i];
		for(int l=1;l<=n;l++)
			for(int r=l+2;r<=n;r++){
				dp11[l][r]=max(dp11[l][r],dp10[l][r])+a[j][r]+a[j][l];
				dp12=max(dp12,dp11[l][r]);
			}
		for(int l=1;l<=n;l++)
			for(int r=l+2;r<=n;r++) dp10[l][r]=max(dp10[l][r],dp9[l][r])+f[r]-f[l-1];
		for(int l=1;l<=n;l++)
			for(int r=l+2;r<=n;r++) dp9[l][r]=max(dp9[l][r],dp8)+a[j][r]+a[j][l];
		for(int l=1;l<=n;l++)
			for(int r=l;r<=n;r++) dp8=max(dp8,dp7[l][r]);
		for(int l=1;l<=n;l++)
			for(int r=l+2;r<=n;r++) dp7[l][r]=dp6[l][r]+f[r]-f[l-1];
		for(int l=1;l<=n;l++)
			for(int r=l+2;r<=n;r++) dp6[l][r]=max(dp6[l][r],dp5[l][r])+a[j][r]+a[j][l];
		for(int l=1;l<=n;l++)
			for(int r=l+2;r<=n;r++) dp5[l][r]=dp4+f[r]-f[l-1];
		for(int l=1;l<=n;l++)
			for(int r=l;r<=n;r++) dp4=max(dp4,dp3[l][r]);
		for(int r=1;r<=n;r++){
			int mx=-INF;
			for(int l=r-1;l;l--){
				mx=max(mx,dp2[l+1][r]),dp3[l][r]=max(dp3[l][r],mx)+f[r]-f[l-1];
			}
		}
        for(int l=1;l<=n;l++){
        	int mx=f2[l-1][l-1];
			for(int r=l;r<=n;r++) mx=max(mx,f2[l][r]),dp2[l][r]=max(f1[l][r+1],mx)+f[r]-f[l-1];
		}
        for(int l=1;l<=n;l++)
        	for(int r=l;r<=n;r++) dp1[l][r]=max(dp1[l][r],0ll)+f[r]-f[l-1];
        for(int r=1;r<=n;r++)
            for(int l=1;l<=n;l++)
                f2[l][r]=max(dp2[l][r],f2[l-1][r]);
        for(int l=1;l<=n;l++)
            for(int r=n;r;r--)
                f1[l][r]=max(dp1[l][r],f1[l][r+1]);
	}
	cout<<dp12<<endl;
	return 0;
}
