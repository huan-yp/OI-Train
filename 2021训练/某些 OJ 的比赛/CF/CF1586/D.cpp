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
const int N = 1e6+10;
int i,j,k,n,s,t,m,pos;
int p[N],a[N];
void ask()
{
	printf("?");
	for(int i=1;i<=n;i++)
	printf(" %d",a[i]);
	printf("\n");
	fflush(stdout);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	a[i]=n;
	for(i=1;i<n;i++)
	{
		a[n]=i;
		ask();
		read(pos);
		if(pos)
		{
			p[n]=n-i+1;
			break;
		}
	}
	if(i==n)p[n]=1;
	for(i=1;i<=n;i++)
	{
		if(i==p[n])continue;
		a[n]=n-p[n]+1;
		for(j=1;j<n;j++)
		a[j]=n-i+1;
		ask();
		read(pos);
		p[pos]=i;
	}
	printf("!");
	for(i=1;i<=n;i++)
	printf(" %d",p[i]);
	printf("\n");
	return 0;
}

