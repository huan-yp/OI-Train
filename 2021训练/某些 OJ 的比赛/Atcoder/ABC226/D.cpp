#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=505;
int i,j,k,n,s,t,m;
int x[N],y[N];
int gcd(int x,int y)
{
	x=abs(x),y=abs(y);
	if(y>x)swap(x,y);
	if(y==0)return x;
	return gcd(y,x%y);
}
int get(int a,int b)
{
	return (a<0)|((b<0)<<1);
}
set<pair<int,pair<int,int> > > st;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(x[i]),read(y[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j)continue;
			int dx=x[i]-x[j],dy=y[i]-y[j];
			int gc=gcd(dx,dy);
			dx/=gc,dy/=gc;
			int op=get(dx,dy);
			st.insert(make_pair(op,make_pair(dx,dy)));
		}
	}
	
	cout<<st.size();
	return 0;
}

