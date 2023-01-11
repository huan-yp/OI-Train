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
const int N=105;
int i,j,k,n,s,t,m;
int a[N],b[N];
struct num{
	int val,rk;
	friend bool operator <(num a,num b)
	{
		return a.val<b.val;
	}
}c[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	t=1;
	read(t);
	while(t--)
	{
		int suma=0,sumb=0,ans=0;
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]),suma+=a[i];
		for(i=1;i<=n;i++)
		read(b[i]),sumb+=b[i];
		for(i=1;i<=n;i++)
		c[i].val=b[i]-a[i],c[i].rk=i,ans+=abs(c[i].val);
		if(suma!=sumb)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans/2);
		sort(c+1,c+n+1);
		for(i=n;i>=1;i--)
		{
			while(c[i].val>0)
			{
				c[i].val--;
				for(j=1;j<=n;j++)
				{
					if(c[j].val<0)
					{
						printf("%d %d\n",c[j].rk,c[i].rk);
						c[j].val++;
						break;
					}
				}
			}
		}
		
	}
	return 0;
}

