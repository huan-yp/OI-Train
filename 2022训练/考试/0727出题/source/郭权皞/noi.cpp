#include<bits/stdc++.h>
using namespace std;
#define N 501
int a[N][N],n,m,fl;
int main(){
	freopen("noi.in","r",stdin);
	freopen("noi.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]!=1) fl=1;
		}
	if(fl==0){
		cout<<(n*2+2)+(n+4)+n*(m-8)-2<<endl;
		return 0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
