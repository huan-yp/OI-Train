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
int i,j,k,n,s,t,m;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(k);
	while(k--)
	{
		int n,x,t;
		read(n),read(x),read(t);
		int tmp=t/x;
		if(tmp>=n)
		printf("%lld\n",n*(n-1)/2);
		else
		printf("%lld\n",tmp*n-tmp*(tmp+1)/2);
	}
	return 0;
}


