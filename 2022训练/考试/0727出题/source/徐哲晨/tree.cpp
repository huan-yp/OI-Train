#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=2e5+5;
int n,x,a[N],f[N];
ld ans;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x),f[x]=i;
	for(int i=1;i<=n;i++) scanf("%d",&x),a[i]=f[x];
	if(n==1) return puts("1"),0;
	ans=(ld)n/2+1;
	printf("%.8Lf",ans); 
	return 0;
}
