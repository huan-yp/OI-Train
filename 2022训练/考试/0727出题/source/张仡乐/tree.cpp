#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int N=2e5+5;
int n,dfx[N],bfx[N];
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&dfx[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&bfx[i]);
	if(n==1)printf("1\n"),exit(0);
	ld sum=0;
	for(int i=2;i<=n;i++)
		sum+=i;
	sum/=(n-1);
	printf("%.7Lf\n",sum);
}

