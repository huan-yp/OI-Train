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
const int N=2e6+10;
struct edge{
	int v,next,pd;
}a[N];
int i,j,k,n,s,t,m;
int now[N],head[N],deg1[N],deg2[N],col[N];
void addedge(int u,int v)
{
	a[k].next=head[u],head[u]=k,a[k].v=v,k++;
	a[k].next=head[v],head[v]=k,a[k].v=u,k++;
}
void dfs(int u)
{
	for(int i=now[u];i!=-1;i=now[u])
	{
		now[u]=a[i].next;
		if(a[i].pd)continue;
		int v=a[i].v;
		col[i/2+1]=i%2+1;
		a[i].pd=a[i^1].pd=1;
		dfs(v);
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(head,-1,sizeof(head));
	read(n),read(m);
	for(i=1;i<=m;i++)
	{
		int x,y,val;
		read(x),read(y),read(val);
		if(val==1)
		addedge(x,y),deg1[x]++,deg1[y]++;
		else
		addedge(x+n,y+n),deg2[x]++,deg2[y]++;
	}
	for(i=1;i<=n;i++)
	{
		if(deg1[i]%2&&deg2[i]%2==0)s++,addedge(0,i);
		if(deg1[i]%2&&deg2[i]%2)s++,addedge(i,i+n);
		if(deg1[i]%2==0&&deg2[i]%2)addedge(0,i+n);
	}
	
	for(i=0;i<=2*n;i++)
	now[i]=head[i];
	
	
	for(i=0;i<=2*n;i++)
	dfs(i);
	
	printf("%d\n",s);
	for(i=1;i<=m;i++)
	printf("%d",col[i]);
	return 0;
}

