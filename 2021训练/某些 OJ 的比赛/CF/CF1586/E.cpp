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
const int N =3e5+10;
int i,j,k,n,s,t,m,q,ans;
int fa[N],val[N],dep[N],dp[N];
int st[N],ed[N];
vector<int> e[N];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void kru()
{
	for(i=1;i<=n;i++)fa[i]=i;
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		int u=find(x),v=find(y);
		if(u==v)continue;
		e[x].push_back(y),e[y].push_back(x);
		fa[v]=u;
	}
}
void dfs(int u)
{
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
void redfs(int u)
{
	if(val[u])ans++;
	for(int v:e[u])
	{
		if(fa[u]==v)continue;
		redfs(v);
		val[u]^=val[v];
	}
}
int lca(int x,int y)
{
	if(dep[y]>dep[x])swap(x,y);
	while(dep[x]!=dep[y])x=fa[x];
	while(x!=y)x=fa[x],y=fa[y];
	return x;
}
void printz(int x,int y,int op)
{
	if(x==y) 
	{
		if(op)
		printf("%d ",x);
		return ;
	}
	printf("%d ",x);
	printz(fa[x],y,op);
}
void printr(int x,int y,int op)
{
	if(x==y) 
	{
		if(op)
		printf("%d ",x);
		return ;
	}
	printr(fa[x],y,op);
	printf("%d ",x);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	kru();
	read(q);
	fa[1]=0,dep[1]=1;dfs(1);
	for(i=1;i<=q;i++)
	{
		int x,y;
		read(x),read(y);
		st[i]=x,ed[i]=y;
		val[x]^=1,val[y]^=1;
	}
	redfs(1);
	if(ans==0)
	{
		puts("YES");
		for(i=1;i<=q;i++)
		{

			int Lca=lca(st[i],ed[i]);
			printf("%d\n",dep[st[i]]+dep[ed[i]]-2*dep[Lca]+1);
			printz(st[i],Lca,0);
			printr(ed[i],Lca,1);
			printf("\n");
		}
	}
	else
	{
		puts("NO");
		cout<<ans/2<<endl;
	}
	return 0;
}

