#include<bits/stdc++.h>
#define N 2010
#define ll long long
using namespace std;
int n,a[N],b[N],sa[N];
ll dp[N][N];

int main(){
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i],sa[b[i]]=i;
	int fl=0;
	for(int i=1;i<=n;i++) if(a[i]!=b[i]) fl=1;
	if(fl==0){
		cout<<n;
		return 0;
	}
	return 0;
}