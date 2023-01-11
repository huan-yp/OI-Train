#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define low(x) ((x)&(-x))
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
const int N=2e5+10;
struct gift{
	int a,b;
	friend bool operator <(gift a,gift b)
	{
		return a.a<b.a;
	}
}a[N];
int i,j,k,n,s,t,m,ans;
int c[N],b[N];
void updata(int x,int cc)
{
	for(;x<=m;x+=low(x))c[x]+=cc;
}
int quert(int x,int ret=0)
{
	for(;x>=1;x-=low(x))ret+=c[x];return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)read(a[i].a);
	for(i=1;i<=n;i++)read(a[i].b),b[i]=a[i].b;
	
	sort(b+1,b+n+1);m=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)a[i].b=lower_bound(b+1,b+m+1,a[i].b)-b;
	sort(a+1,a+n+1);
	int lst=0;a[n+1].a=1e9+10;
	for(i=1;i<=n;i++)
	{
		updata(a[i].b,1);
		if(a[i].a!=a[i+1].a)
		while(lst<i)
		ans+=(i-quert(a[++lst].b-1));
	}
	
	cout<<ans<<endl;
	return 0;
}

