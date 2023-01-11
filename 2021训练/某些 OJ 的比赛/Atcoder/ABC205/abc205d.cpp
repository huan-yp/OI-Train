#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m;
const int N=1e5+10;
int a[N];
int check(int x)
{
	return x-(lower_bound(a+1,a+n+1,x)-a);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)
	read(a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++)
	{
		read(k);
		int l=0,r=2e18,ans;
		while(r>=l)
		{
			int mid=(l+r)/2;
			if(check(mid)<k)
			ans=mid,l=mid+1;
			else
			r=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


