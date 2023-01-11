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
const int N=2e5+10;
int i,j,k,n,s,t,m,cnta,cntb;
int dp[N],dep[N],a[N],b[N],rk[N],clz[N];
vector<int> e[N];
void dfs(int u,int fa=0)
{
	if(dep[u]%2)m++;
	for(int v:e[u])
	{
		if(v==fa)continue;
		dep[v]=dep[u]+1,dfs(v,u);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);clz[0]=-1;
	for(i=1;i<=2e5;i++)clz[i]=clz[i>>1]+1;
	while(tot--)
	{
		for(i=1;i<=n;i++)e[i].clear();
		read(n);cntb=cnta=0;
		for(i=1;i<n;i++)
		{
			int x,y;read(x),read(y);
			e[x].push_back(y),e[y].push_back(x);
		}
		dfs(1);
		for(i=clz[i];i>=0;i--)
		{
			if(m>=min(n,(1<<i+1)-1)-(1<<i)+1)
			{
				m-=min(n,(1<<i+1)-1)-(1<<i)+1;
				for(j=1<<i;j<=(1<<i+1)-1&&j<=n;j++)
				a[++cnta]=j;
			}
			else
			{
				for(j=1<<i;j<=(1<<i+1)-1&&j<=n;j++)
				b[++cntb]=j;
			}
		}
		int nowa=0,nowb=0;
		for(i=1;i<=n;i++)
		{
			if(dep[i]%2)
			printf("%d ",a[++nowa]);
			else
			printf("%d ",b[++nowb]);
		}
		printf("\n");
	}
	return 0;
}

