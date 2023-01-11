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
/*



*/
const int N=105;
const double eps=1e-9;
int i,j,k,n,s,t,m,flag;
struct equation{
	double a[N],b;
	friend equation operator *(const equation &a,const double &b)
	{
		equation ret;
		for(int i=1;i<=n;i++)
		ret.a[i]=a.a[i]*b;
		ret.b=a.b*b;
		return ret;
	}
	friend equation operator -(const equation &a,const equation &b)
	{
		equation ret;
		for(int i=1;i<=n;i++)
		ret.a[i]=a.a[i]-b.a[i];
		ret.b=a.b-b.b;
		return ret;
	}
}e[N];
double x[N];
double eq(double a,double b)
{
	return abs(a-b)<eps;
}
void gauss()
{
	for(i=1;i<=n;i++)
	{
		int p=0;
		for(j=i;j<=n;j++)
		{
			if(eq(e[i].a[j],0.0))continue;
			p=j;break;
		}
		if(p==0)
		{
			flag=1;
			return;
		}
		swap(e[i],e[p]);
		for(j=i+1;j<=n;j++)
		e[j]=e[j]-(e[i]*(e[j].a[i]/e[i].a[i]));
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)	
		scanf("%lf",&e[i].a[j]);
		scanf("%lf",&e[i].b);
	}
	gauss();
	if(flag)
	{
		printf("No Solution");
		return 0;
	}
	for(i=n;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		e[i].b-=x[j]*e[i].a[j];
		x[i]=e[i].b/e[i].a[i];
	}
	for(i=1;i<=n;i++)
	printf("%0.2lf\n",x[i]);
	return 0;
}
