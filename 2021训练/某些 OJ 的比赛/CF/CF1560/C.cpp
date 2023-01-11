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
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(k);
		for(i=1;;i++)
		{
			if(i*i>=k)
			break;
		}
		m=i;
		n=m*m;
		int x=m,y=1;
		for(i=1;i<m&&n!=k;i++)
		{
			n--;y++;
			if(n==k)break;
		}
		for(i=m;i>=1&&n!=k;i--)
		{
			x--,n--;
			if(n==k)break;
		}
		printf("%d %d\n",x,y);
	}

	return 0;
}

