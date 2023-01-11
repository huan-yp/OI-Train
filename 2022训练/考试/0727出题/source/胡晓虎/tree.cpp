#include<bits/stdc++.h>
using namespace std;
int n;
double ans;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++) ans+=i;
	printf("%.10Lf",ans);
	return 0;
} 
