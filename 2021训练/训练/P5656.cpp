#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
int i,j,k,n,s,t,m;
int gcd(int x,int y){if(y==0)return x;return gcd(y,x%y);}
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return ;
	}
	exgcd(b,a%b,x,y);
	int tmp=y;y=x-a/b*y,x=tmp;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int a,b,c;
		read(a),read(b),read(c);
		int x,y,gc=gcd(a,b);
		if(c%gc)
		{
			printf("-1\n");
			continue;
		}
		a/=gc,b/=gc,c/=gc;
		exgcd(a,b,x,y);
		x*=c,y*=c;
		int x0,y0,x1,y1;
		x0=x-(int)(floor(1.0*x/b))*b,y1=y-(floor(1.0*y/a))*a;
		if(x0==0)x0+=b;if(y1==0)y1+=a;	
		y0=(c-x0*a)/b,x1=(c-y1*b)/a;
		if(y0<=0)	
		printf("%lld %lld\n",x0,y1);
		else
		printf("%lld %lld %lld %lld %lld\n",(y0-y1)/a+1,x0,y1,x1,y0);
	
	}
	return 0;
}
