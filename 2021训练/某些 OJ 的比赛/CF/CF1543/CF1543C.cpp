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
double eps=1e-12;
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
double solve(double c,double m,double p,double v)
{
	double ret=1;
	if(c>=eps)
	{
		double change=min(c,v);
		double cm=change/2*(m>=eps);double cp=change/(1+(m>=eps));
		ret+=c*solve(c-change,m+cm,p+cp,v);
	}
	if(m>=eps)
	{
		double change=min(m,v);
		double cc=change/2*(c>=eps);double cp=change/(1+(c>=eps));
		ret+=m*solve(c+cc,m-change,p+cp,v);
	}
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		double c,m,p,v;
		cin>>c>>m>>p>>v;
		printf("%0.9lf\n",solve(c,m,p,v));	
	}
	return 0;
}

