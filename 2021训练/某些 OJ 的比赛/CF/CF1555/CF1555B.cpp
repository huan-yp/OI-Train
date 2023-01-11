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
		int W,H,w,h,x1,x2,y1,y2;
		read(W),read(H);
		read(x1),read(y1),read(x2),read(y2);
		read(w),read(h);
		double dis=INF;
		if(w+(x2-x1)<=W)
		dis=min(dis,max(0.0,(double)w-x1));
		if(h+(y2-y1)<=H)
		dis=min(dis,max(0.0,(double)h-y1));
		if(w+(x2-x1)<=W)
		dis=min(dis,max(0.0,(double)w-(W-x2)));
		if(h+(y2-y1)<=H)
		dis=min(dis,max(0.0,(double)h-(H-y2)));
		
		if(dis==INF)
		printf("-1\n");
		else
		printf("%0.9lf\n",dis);
	}
	return 0;
}

