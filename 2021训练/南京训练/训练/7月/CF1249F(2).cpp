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
const int N=205;
int i,j,k,n,s,t,m;
int a[N],suf[N][N],maxn[N];
vector<int> e[N];
void dfs(int u,int fa)
{	
	int p=0;suf[u][0]=a[u];
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
	}
	for(int v:e[u])
	{
		if(v==fa)continue;
		for(i=0;i<=n;i++)
		maxn[i]=suf[u][i];
		
		for(i=0;i<=n;i++)
		{
			if(i)
			suf[u][i]=max(suf[u][i]+suf[v][max(i-1,k-i)],suf[u][max(i,k-i+1)]+suf[v][i-1]);
			else
			suf[u][i]=suf[u][i]+suf[v][max(i-1,k-i)];
			
		}
		for(i=n;i>=0;i--)
		suf[u][i]=max(suf[u][i+1],suf[u][i]);
	}
	
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)
	read(a[i]);
	
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	
	cout<<suf[1][0];
	return 0;
}
