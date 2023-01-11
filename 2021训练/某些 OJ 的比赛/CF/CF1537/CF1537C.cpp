#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
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
const int N=3e5+10;
int a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]);
		sort(a+1,a+n+1);
		int minu=1e9;
		for(i=2;i<=n;i++)
		minu=min(minu,abs(a[i]-a[i-1]));
		int chose1,chose2;
		if(minu==a[2]-a[1])
		{
			for(i=1;i<=n;i++)
			{
				if(i!=2)
				printf("%d ",a[i]);
			}
			printf("%d ",a[2]);
			printf("\n");
			continue;
		}
		if(minu==a[n]-a[n-1])
		{
			printf("%d ",a[n-1]);
			for(i=1;i<=n;i++)
			{
				if(i!=n-1)
				printf("%d ",a[i]);
			}
			printf("\n");
			continue;
		}
		for(i=2;i<=n;i++)
		{
			if(minu==a[i]-a[i-1])
			break;
		}
		int chose=i;
		for(i=chose;i<=n;i++)
		printf("%d ",a[i]);
		for(i=1;i<=chose-1;i++)
		printf("%d ",a[i]);
		printf("\n");
		
	}
	return 0;
}


