#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
const int N=1e5+10;
int i,j,k,n,s,t,m;
int f[N][50],g[N][50],d[11][11][11][11][11];
vector<point> a[N][50],b[N][50]; 
int change(int x,int y)
{
	int c[2]={0,0},g[2][6],cnt=0;
	memset(g,0,sizeof(g));
	while(x)
	{
		g[0][++c[0]]=x%10;
		x/=10;
	}
	while(y)
	{
		g[1][++c[1]]=y%10;
		y/=10;
	}
	for(int i=1;i<=2;i++)
	swap(g[0][i],g[0][6-i]),swap(g[1][i],g[1][6-i]);
	for(int i=1;i<=5;i++)
	cnt+=g[0][i]!=g[1][i];
	return cnt;
}
int calc(int x,int mask)
{
	int base=11,cnt=0,ret=0;
	while(x)
	{
		if((1<<cnt)&mask)
		ret=ret*base*10;
		
		cnt++;
	}
}
void init()
{
	memset(g,1,sizeof(g));
	for(i=0;i<1e5;i++)
	g[i][0]=f[i][0]=i;
	for(i=1;i<=44;i++)
	{
		for(s=0;s<32;s++)
		{
			for(j=0;j<=99999;j++)
			{
				
			}
			for(j=0;j<=99999;j++)
			{
				
			}
		}
		
	}
}
void solve()
{
	int l,r;
	int ans=1e9;
	read(l),read(r);
	if(l==r)
	{
		puts("0");
		return;
	}
	for(i=l;i<=r;i++)
	{
		int turn=change(i,0);
		for(j=turn;j<=44;j++)
		if(f[i+1][j-turn]>=r&&g[i-1][j-turn]<=l)
		{
			ans=min(ans,j);
			break;
		}
	}
	printf("%d\n",ans+1);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();
	read(t);
	while(t--)
	solve();
	return 0;
}


