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
	read(t);
	while(t--)
	{
		read(n);
		int x,sum=0;
		for(i=1;i<=n;i++)	
		read(x),sum+=x;
		if(sum==n)
		{
			printf("0\n");
			continue;
		}
		if(sum<n)
		{
			printf("1\n");
			continue;
		}
		if(sum>n)
		{
			printf("%lld\n",sum-n);
			continue;
		}
	}
	return 0;
}


