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
const int N=1e6+10;
int i,j,k,n,s,t,m;
int a[N],b[N],g[N];
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T=1;
	read(T);
	while(T--)
	{
		read(n);s=0;int gc=0;
		for(i=1;i<=n;i++)
		read(a[i]),gc=gcd(abs(a[i]),gc),b[i]=0;
		for(i=1;i<=n;i++)a[i]/=gc;
		g[n+1]=0;
		for(i=n;i>=1;i--)
		g[i]=gcd(abs(a[i]),g[i+1]);
		int sum=0;
		for(i=1;i<n;i++)
		{
			while(sum%g[i+1]||sum==0||b[i]==0)
			b[i]++,sum+=a[i];
		}		
		b[n]=(-sum)/a[n];
		for(i=1;i<=n;i++)
		printf("%d ",b[i]);
		printf("\n");
	}

	return 0;
}

