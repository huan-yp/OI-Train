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
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	while(tot--)
	{
		int x1,p1,x2,p2;
		read(x1),read(p1),read(x2),read(p2);
		if(p1-p2>=10)
		{
			puts(">");
			continue;
		}
		if(p2-p1>=10)
		{
			puts("<");
			continue;
		}
		int need=min(p1,p2);
		p1-=need,p2-=need;
		for(i=1;i<=p1;i++)x1*=10;
		for(i=1;i<=p2;i++)x2*=10;
		if(x1>x2)puts(">");
		if(x1==x2)puts("=");
		if(x1<x2)puts("<");
	}
	return 0;
}

