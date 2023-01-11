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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N = 1e5+10;
int i,j,k,n,s,t,m;
int a[N],sum[N];
int isprime(int x)
{
	for(int i=2;i<=sqrt(x+1);i++)
	{
		if(x%i==0)
		return 0;
	}
	return 1;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T;read(T);
	while(T--)
	{
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]),sum[i]=sum[i-1]+a[i];
		if(isprime(sum[n]))
		{
			printf("%d\n",n-1);
			int flag=1;
			for(i=1;i<=n;i++)
			{
				if((a[i]&1)&&flag)
				{
					flag=0;
					continue;
				}
				printf("%d ",i);
			}
			printf("\n");
		}
		else
		{
			printf("%d\n",n);
			for(i=1;i<=n;i++)
			printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}

