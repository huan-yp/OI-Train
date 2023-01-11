#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline void read(int &x)
{
	scanf("%d",&x);
}
int i,j,k,n,s,t,m;
const int N=4e5+10;
int a[N];
void solve()
{
	LL sum=0;
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]);
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[i+1]&&a[i]>a[i-1])
		{
			int to=max(a[i-1],a[i+1]);
			sum+=a[i]-to;
			a[i]=to;
		}
	}
	for(i=1;i<=n+1;i++)
	sum+=abs(a[i]-a[i-1]);
	for(i=1;i<=n;i++)
	a[i]=0;
	printf("%lld\n",sum);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	solve();
	return 0;
}


