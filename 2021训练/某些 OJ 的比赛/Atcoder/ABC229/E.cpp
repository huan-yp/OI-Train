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
const int N=3e5+10;
int i,j,k,n,s,t,m;
int fa[N],ans[N];
vector<int> e[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v)return ;
	fa[u]=v,ans[i-1]--;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y),e[y].push_back(x);
	}
	ans[n+1]=0;
	for(i=n;i>=1;i--)
	{
		ans[i-1]=ans[i]+1;
		for(int v:e[i])
		{
			if(v<i)continue;
			merge(i,v);
		}
	}
	for(i=1;i<=n;i++)
	printf("%d\n",ans[i]);
	return 0;
}

