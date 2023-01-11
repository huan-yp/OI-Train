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
int i,j,k,n,s,t,m;
int a[N],lo[N],st[20][N];
int gcd(int x,int y)
{
	if(y>x)swap(x,y);
	if(y==0)return x;
	return gcd(y,x%y);
}
int ask(int l,int r)
{
	int len=lo[r-l+1];
	return gcd(st[len][l],st[len][r-(1<<len)+1]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=1;i<N;i++)
	lo[i]=log2(i);
	
	read(t);
	while(t--)
	{
		read(n);
		for(i=1;i<=n;i++)
		read(a[i]);
		
		for(i=1;i<n;i++)
		st[0][i]=abs(a[i+1]-a[i]);
		
		for(i=1;i<=19;i++)
		for(j=1;j+(1<<i-1)-1<n;j++)
		st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<i-1)]);
		
		int ans=0,now;j=1;
		for(i=1;i<n;i++)
		{
			j=max(i,j);
			now=ask(i,j);
			while(now!=1&&j<n)
			{
				j++;
				if(j==n)break;
				now=ask(i,j);
			}
			j--;
			cmax(ans,j-i+1);
		}
		
		printf("%lld\n",ans+1);
	}
	

	return 0;
}

