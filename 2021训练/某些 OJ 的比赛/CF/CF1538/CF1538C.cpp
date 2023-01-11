#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define int long long
#define low(x) (x)&(-x)
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
int i,j,k,n,s,t,m,len;
const int N=2e5+10;
int a[N],c[N],b[N];
int quert(int x,int ret=0)
{
	for(int i=x;i>=1;i-=low(i))
	{
		ret+=c[i];
	}
	return ret;
}
void updata(int x)
{
	for(int i=x;i<len;i+=low(i))
	c[i]++;
}
int ask(int x)
{
	int lim=x-b[a[i]];
	lim=lower_bound(b+1,b+len,lim+1)-b-1;
	return quert(lim);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		int ans=0,l,r;
		read(n),read(l),read(r);
		for(i=1;i<=n;i++)	
		read(a[i]),b[i]=a[i];
		sort(b+1,b+n+1);
		len=unique(b+1,b+n+1)-b;
		for(i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+len,a[i])-b;
		for(i=1;i<=n;i++)
		{
			ans+=ask(r)-ask(l-1);
			updata(a[i]);
		}
		for(i=1;i<len;i++)
		c[i]=0;
		cout<<ans<<endl;
	}
	return 0;
}


