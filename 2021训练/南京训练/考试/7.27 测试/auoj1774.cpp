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
const int N=5e5+10;
int i,j,k,n,s,t,m;
int fa[N];
LL ans=0;
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	//10+1+3+1+2
	for(i=1;i<=n;i++)
	fa[i]=i;
	
	for(i=n;i>=1;i--)
	for(j=2;j*i<=n;j++)
	{
		if(find(i)==find(i*j))continue;
		fa[find(i)]=find(i*j);
		ans+=i;	
	}
	printf("%lld %d\n",ans,n-1);
	return 0;
}

