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
const int N=1e6+10,M=505;
int i,j,k,n,s,t,m,js;
int pd[N],zs[N],a[M][M];
int ass[2][2*M];
int gcd(int x,int y)
{
	if(x==0)return y;
	return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y)
{
	if(x==0)return y;
	if(y==0)return x;
	return x/gcd(x,y)*y;
}
void init()
{
	for(i=2;i<N;i++)
	{
		if(!pd[i])zs[++js]=i;
		for(j=1;j<=js&&i*zs[j]<N;j++)
		pd[i*zs[j]]=1;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();
	read(n);
	int all=2*n+5;
	for(i=1;i<=2*n+1;i+=4)
	{
		ass[1][i-(n%2)]=zs[++t];
		ass[1][i+2-(n%2)]=zs[all-t];
		ass[0][i]=zs[++t];
		ass[0][i+2]=zs[all-t];
	}
	for(i=0;i<=n+1;i++)
	for(j=0;j<=n+1;j++)
	{
		if((i+j)%2==0)
		a[i][j]=ass[0][i+j+1]*ass[1][i-j+n+1];
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(a[i][j]==0)
		a[i][j]=lcm(lcm(a[i+1][j],a[i-1][j]),lcm(a[i][j+1],a[i][j-1]))+1;
		if(a[i][j]>1e15)
		{
			printf("boom!");
			while(1);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		printf("%lld ",a[i][j]);
		printf("\n");
	}
	return 0;
}

