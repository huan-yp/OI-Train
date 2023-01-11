#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
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
int i,j,k,n,s,t,m,ans;
struct op{
	int val,inc;
	friend bool operator <(op a,op b)
	{
		return a.val<b.val;
	}
}a[N];
int gcd(int x,int y)
{
	if(y==0)return x;
	return gcd(y,x%y);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	read(a[i].inc),read(a[i].val);
	
	sort(a+1,a+m+1);
	
	int now=n;
	for(i=1;i<=m;i++)
	{
		int gc=gcd(now,a[i].inc);
		ans+=(now-gc)*a[i].val;
		now=gc;
	}
	if(now!=1)
	cout<<-1;
	else
	cout<<ans;
	return 0;
}

