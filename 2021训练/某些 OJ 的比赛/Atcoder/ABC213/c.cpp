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
struct point {
	int x,y;
};
const int N=1e5+10;
int i,j,k,n,s,t,m,m1,m2;
int bx[N],by[N];
point a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t),read(t);
	read(n);
	for(i=1;i<=n;i++)
	{
		read(a[i].x),read(a[i].y);
		bx[i]=a[i].x,by[i]=a[i].y;
	}
	sort(bx+1,bx+n+1),sort(by+1,by+n+1);
	m1=unique(bx+1,bx+n+1)-bx-1,m2=unique(by+1,by+n+1)-by-1;
	for(i=1;i<=n;i++)
	{
		int x=lower_bound(bx+1,bx+m1+1,a[i].x)-bx;
		int y=lower_bound(by+1,by+m2+1,a[i].y)-by;
		printf("%d %d\n",x,y);
		
	}

	return 0;
}

