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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
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
		if(n==1)
		{
			printf("a\n");
			continue;
		}
		if(n%2)
		{
			for(i=1;i<=n/2;i++)
			printf("a");
			printf("bc");
			for(i=1;i<n/2;i++)
			printf("a");
			printf("\n");
		}
		else
		{
			for(i=1;i<=n/2;i++)
			printf("a");
			printf("b");
			for(i=1;i<n/2;i++)
			printf("a");
			printf("\n");
		}
	}

	return 0;
}

