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
const int N=2e5+10;
int i,j,k,n,s,t,m,q,now;
int deg[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	now=n;
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		if(x>y)swap(x,y);
		deg[x]++;if(deg[x]==1)now--;
	}
	read(q);
	for(i=1;i<=q;i++)
	{
		int op,x,y;
		read(op);
		if(op==1)
		{
			read(x),read(y);
			if(x>y)swap(x,y);
			deg[x]++;if(deg[x]==1)now--;
		}
		if(op==2)
		{
			read(x),read(y);
			if(x>y)swap(x,y);
			deg[x]--;if(deg[x]==0)now++;
		}
		if(op==3)
		{
			printf("%d\n",now);
		}
	}

	return 0;
}

