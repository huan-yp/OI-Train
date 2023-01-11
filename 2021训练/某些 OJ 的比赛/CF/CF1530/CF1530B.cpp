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
int p[25][25];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		memset(p,0,sizeof(p));
		read(n),read(m);
		for(i=1;i<=m;i+=2)
		p[1][i]=1;
		for(i=3;i<=n;i+=2)
		p[i][m]=1;
		for(i=m-2;i>=1;i-=2)
		p[n][i]=1;
		for(i=n-2;i>=3;i-=2)
		p[i][1]=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			cout<<p[i][j];
			cout<<endl;
		}
	}

	return 0;
}

