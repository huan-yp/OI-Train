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
const int N=1e5+10;
struct edge{
	int v,next,col;
};
int i,j,k,n,s,t,m,e,ans;
int head[N],col[N],vis[N],no[N];
edge a[N];
void addedge(int u,int v)
{
	a[k].next=head[u];a[k].v=v;head[u]=k++;
	a[k].next=head[v];a[k].v=u,head[v]=k++;
}
int find(int u,int tp)
{
	if(vis[u]||no[u])return 0;
	if(tp==1&&col[u]==0)
	return col[u]=1;	
	
	vis[u]=1;
	for(int i=head[u];i!=-1;i=a[i].next)
	{
		if(a[i].col!=tp)continue;
		if(find(a[i].v,tp^1))
		{
			a[i].col^=1;a[i^1].col^=1;vis[u]=0;
			return col[u]=1;
		}
	}
	no[u]=1;
	return vis[u]=0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(head,-1,sizeof(head));
	read(n),read(m),read(e);
	for(i=1;i<=e;i++)
	{
		int x,y;read(x),read(y);
		addedge(x,y+n);
	}
	while(1)
	{
		int flag=0;
		for(i=1;i<=n;i++)no[i]=0;
		for(i=1;i<=n;i++)
		{ 
			if(col[i])continue;
			flag=find(i,0);
			if(flag)break;
		}
		if(flag==0)break;
		ans+=flag;
	}
	cout<<ans<<endl;
	return 0;
}

