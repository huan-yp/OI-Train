#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e3+10;
struct point{
	int a,b;
	friend bool operator <(point a,point b)
	{
		return a.a<b.a;
	}
}p[N];
int i,j,k,n,s,t,m;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(k);
		for(i=1;i<=n;i++)read(p[i].a);	
		for(i=1;i<=n;i++)read(p[i].b);
		sort(p+1,p+n+1);
		for(i=1;i<=n;i++)
		if(k>=p[i].a)k+=p[i].b;
		
		cout<<k<<endl;
	}
	
	return 0;
}

