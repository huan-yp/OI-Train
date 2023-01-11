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
/*



*/
int i,j,k,n,s,t,m;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int a,b,c,d;
	read(a),read(b),read(c),read(d);
	int l=0,r=2e18/d/c,ans=-1;
	while(r>=l)
	{
		int mid=(l+r)/2;
		if(d*c*mid>=(a+mid*b))
		r=mid-1,ans=mid;
		else
		l=mid+1;
	}
	cout<<ans;
	return 0;
}

