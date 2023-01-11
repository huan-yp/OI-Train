#include<bits/stdc++.h>
using namespace std;
int n,m,a[155][555],dp[88][88][6][88][88];
bool asa;
int main(){
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) asa|=(a[i][j]!=1);
	if(asa) printf("dp¹ÒÁË");
	else printf("%d",n*m-5*n+4);
	return 0;
}
