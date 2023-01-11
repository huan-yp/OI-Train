#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define size siz
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
struct edge{
	int u,v,val;
	friend bool operator <(edge a,edge b)
	{
		return a.val<b.val;
	}
};
const int N=1e5+10;
int i,j,k,n,s,t,m,ans;
int fa[N],size[N];
edge e[N];
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
	for(i=1;i<n;i++)
	read(e[i].u),read(e[i].v),read(e[i].val);
	
	sort(e+1,e+n);
	for(i=1;i<=n;i++)
	fa[i]=i,size[i]=1;
	
	for(i=1;i<n;i++)
	{
		int u=find(e[i].u),v=find(e[i].v);
		fa[u]=v,ans+=e[i].val*size[u]*size[v];
		size[v]+=size[u];
	}
	printf("%lld\n",ans);

	return 0;
}

