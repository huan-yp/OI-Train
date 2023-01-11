#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
int i,j,k,n,s,t,m,gap,main_cost;
const int N=2e5+10;
int a[N],val[N];
bool check(int x)
{
	int cost=main_cost;
	for(i=n-1;i>n-x;i--)
	{
		if(val[i]==0)continue;
		cost-=(val[i]-1)/gap;
	}
	return cost<=k;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k),read(gap);
	for(i=1;i<=n;i++)
	read(a[i]);
	
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)
	{
		val[i-1]=a[i]-a[i-1];
		if(val[i-1]==0)continue;
		main_cost+=(val[i-1]-1)/gap;
	}
	sort(val+1,val+n);
	int l=1,r=n,ans=n;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(check(mid))
		r=mid-1,ans=mid;
		else
		l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}


