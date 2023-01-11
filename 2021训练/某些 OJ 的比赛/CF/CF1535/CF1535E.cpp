#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
const int N=3e5+10;
int i,j,k,n,s,t,m;
int fa[N][20],sum[N][20],price[N],amount[N],all[N];
int jump(int x)
{
	for(i=19;i>=0;i--)
	{
		if(all[fa[x][i]])
		x=fa[x][i];
	}
	return x;
}
void add(int i,int x,int a,int c)
{
	fa[i][0]=x;
	price[i]=c;
	all[i]=a;
	for(j=1;j<=19;j++)
	fa[i][j]=fa[fa[i][j-1]][j-1];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(all[0]),read(price[0]);
	for(i=0;i<=19;i++)
	fa[0][i]=N-1,fa[N-1][i]=N-1;
	for(int i1=1;i1<=n;i1++)
	{
		int op,x,a,c;
		read(op);
		if(op==1)
		{
			read(x),read(a),read(c);
			add(i1,x,a,c);
		}
		if(op==2)
		{
			read(x),read(a);
			int sum=0,js=0;
			while(all[x]&&a)
			{
				int pos=jump(x);
				int tmp=min(all[pos],a);
				sum+=price[pos]*tmp;
				js+=tmp;
				all[pos]-=tmp;
				a-=tmp;
			}
			printf("%lld %lld\n",js,sum);
			fflush(stdout);
		}
	}
	return 0;
}


