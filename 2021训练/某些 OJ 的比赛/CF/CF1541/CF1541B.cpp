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
const int N=4e5+10;
int i,j,k,n,s,t,m,ans;
int a[N],p[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		ans=0;
		read(n);
		for(i=1;i<=2*n;i++)
		p[i]=0;
		for(i=1;i<=n;i++)
		read(a[i]);
		for(i=1;i<=n;i++)
		{
			for(j=a[i];j<=2*n;j+=a[i])
			if(i+p[j/a[i]]==j&&p[j/a[i]])
			ans++;
			p[a[i]]=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}

