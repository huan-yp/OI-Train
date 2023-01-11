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
int randshort()
{
	return (1ll*rand()*rand())&32767;
}
int randint()
{
	return randshort()<<16|randshort();
}
int Rand()
{
	return randint()<<32|randint();
}
/*



*/
const int N=2e6+10;
int i,j,k,n,s,t,m,ans;
int head[N],val[N],w[N],nval[N],b[N];
map<int,int> mp;
struct edge{
	int v,next,val;
}a[N];
void work(int aa,int bb,int cc)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].val=cc;
	a[k].v=bb;
}
void dfs(int u,int fa=0)
{
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(v==fa)continue;
		val[v]=a[i].val;
		dfs(v,u);
	}
}
void dfs2(int u,int fa,int now)
{
	nval[u]=now^w[val[u]];
	for(int i=head[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(v==fa)continue;
		dfs2(v,u,nval[u]);
	}
}
//from:https://vjudge.net/problem/HackerRank-number-game-on-a-tree
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	srand(time(NULL));
	read(t);
	while(t--)
	{
		mp.clear();
		ans=k=0;
		for(i=1;i<=n;i++)
		head[i]=0;
		
		read(n);
		for(i=2;i<=n;i++)
		{
			int x,y,z;
			read(x),read(y),read(z);
			work(x,y,z);
			work(y,x,z);
		}
		dfs(1);
		
		for(i=2;i<=n;i++)
		b[i-1]=val[i];
		sort(b+1,b+n),m=unique(b+1,b+n)-b-1;
		for(i=2;i<=n;i++)
		val[i]=lower_bound(b+1,b+m+1,val[i])-b;
		for(i=1;i<=m;i++)
		w[i]=Rand();
		
		dfs2(1,0,0);
		for(i=1;i<=n;i++)
		mp[nval[i]]++;
		
		for(pair<int,int> v:mp)	
		ans+=v.second*(v.second-1)/2;
		
		printf("%lld\n",n*(n-1)/2-ans);
	}
	return 0;
}

