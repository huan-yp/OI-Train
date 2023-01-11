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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
struct edge{
	int x,y;
};
const int N=2e5+10;
int i,j,k,n,s,t,m,ans;
int deg[N],vis[N];
edge a[N];
vector<int> e[N]; 
bool cmp(const int a,const int b)
{
	if(deg[a]!=deg[b])return deg[a]<deg[b];
	return a<b;
}
//重载小于号
//从小的往大的连边 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		read(a[i].x),read(a[i].y);
		deg[a[i].x]++,deg[a[i].y]++;
	}
	for(i=1;i<=m;i++)
	{
		if(cmp(a[i].x,a[i].y))
		e[a[i].x].push_back(a[i].y);
		else
		e[a[i].y].push_back(a[i].x);
	}
	for(i=1;i<=n;i++)
	{
		int u=i;
		for(int v:e[u])
		vis[v]=1;
		for(int v:e[u])
		for(int w:e[v])
		ans+=vis[w];
		for(int v:e[u])
		vis[v]=0;
	}
	cout<<ans<<endl;
	return 0;
}

