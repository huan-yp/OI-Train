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
/*



*/
int i,j,k,n,s,t,m,ans;
const int N=1e5+10;
struct line{
	int l,r,op;
}a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		int op;
		read(a[i].op),read(a[i].l),read(a[i].r);
		a[i].op--;
	}
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	if(!((a[i].r<a[j].l||(a[i].r==a[j].l&&(a[j].op&2||a[i].op&1)))
	||(a[j].r<a[i].l||(a[j].r==a[i].l&&(a[i].op&2||a[j].op&1)))))
	ans++;
	cout<<ans<<endl;

	return 0;
}

