#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n,s,t;
const int N=1e5+10;
int a[N],b[N],c[N],vis[N];
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int js=0;
	for(i=1;i<=n;i++)
	if(a[i]>=b[js+1])
	js++;
	cout<<js;
	return 0;
}
