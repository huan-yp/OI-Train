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
const int N = 55,mod = 998244353; 
struct point{
	int x,y;
}p[N];
int i,j,k,n,s,t,m,lenx,leny;
int bx[N],by[N],inv[N],a[N][N];
int quick(int a,int s,int ret=1)
{
	while(s)
	{
		if(s&1)ret=1ll*a*ret%mod;
		a=1ll*a*a%mod;s>>=1;
	}
	return ret;
}
int calc(int x1,int y1,int x2,int y2)
//вСио,сроб 
{
	return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y2-1];
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(t);
	for(i=1;i<N;i++)
	inv[i]=quick(i,mod-2);
	for(i=1;i<=n;i++)
	{
		read(p[i].x),read(p[i].y);
		bx[i]=p[i].x,by[i]=p[i].y;
	}
	sort(bx+1,bx+n+1),lenx=unique(bx+1,bx+n+1)-bx-1;
	sort(by+1,by+n+1),leny=unique(by+1,by+n+1)-by-1;
	
	
	
	

	return 0;
}

