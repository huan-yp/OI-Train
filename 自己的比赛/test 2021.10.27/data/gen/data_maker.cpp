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

int Rand(int l,int r)
{
	return 1ll*rand()*rand()*rand()%(r-l+1)+l;
}
int i,j,k,n,s,t,m;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(int ii=17;ii<=19;ii++)
	{
		frem(ii);
		int level=ii-10;
		level=30;
		int lima,d;
		n=100000;
		lima=20+(1<<level);
		d=pow(100,(ii-15));
//		d=3995;
		printf("%d %d\n",n,d);
		for(i=1;i<=n;i++)
		{
			int val=Rand(1,10000);
			if(val==10000)
			{
				printf("%d ",Rand(20,1<<level));
			}
			else
			{
				if(rand()%2)
				printf("%d ",1+Rand(1,5e6));
				else
				printf("%d ",lima-Rand(1,5e6));
			}
	//		printf("%d ",Rand(lima/10,lima));
		}
	}
	return 0;
}

