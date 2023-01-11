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
int myPow(int a,int s)
{
	int ret=1;
	for(int i=1;i<=s;i++)
	ret=ret*a;
	
	return ret;
} 
void construct(int x,int now)
{
	//let it increase at least by 1
	if(x==0)return ;
	if(x!=n)printf(" ");
	
	int p2=1;
	while(x%3==0)
	now++,x/=3;
	while(p2*2<=x)p2*=2;
	
	if((x-p2)%3==0)
	{
		printf("%lld",p2*myPow(3,now));
		construct(x-p2,now);
	}
	else
	{
		p2/=2;
		printf("%lld",p2*myPow(3,now));
		construct(x-p2,now);
	}
} 
signed main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		construct(n,0);
		printf("\n");
	}
	return 0;
}

