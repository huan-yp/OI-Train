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
ans=2^x;
决定了 1 与所有人的关系，就可以唯一确定一种合法方案
不考虑与 1 的连边 
考虑已有边构成的连通块
不同连通块之间不影响决策
连一条 1 边，代表相同
连一条 0 边，代表相反
 

*/
struct edge{
	int v,val;
};
int i,j,k,n,s,t,m,ans,opt=1,flag=1;
const int N=1e5+10,mod=1e9+7;
int to[N],fa[N],col[N],det[N];
vector<edge> e[N];
void dfs(int u)
{
	for(edge tmp:e[u])
	{
		int v=tmp.v,val=tmp.val;
		if(col[v]==-1)
		{
			col[v]=col[u]^1^val;
			dfs(v);
		}
		else
		{
			if(col[v]!=val^col[u]^1)
			flag=0;
		}
	}
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int u=find(x),v=find(y);
	if(u==v)return ;
	fa[u]=v;
}
signed main()
{
	freopen("album.in","r",stdin);
	freopen("album.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	memset(col,-1,sizeof(col)),memset(to,-1,sizeof(to)),memset(det,-1,sizeof(det));
	for(i=1;i<=n;i++)fa[i]=i;
	
	for(i=1;i<=m;i++)
	{
		int x,y,val;
		read(x),read(y),read(val);
		if(x>y)swap(x,y);
		if(x==1)
		to[y]=val;
		else
		{
			merge(x,y);
			e[x].push_back((edge){y,val});
			e[y].push_back((edge){x,val});
		}
	}
	for(i=2;i<=n;i++)
	{
		if(col[i]!=-1)continue;
		col[i]=1;
		dfs(i);
	}
	for(i=2;i<=n;i++)
	{
		int u=find(i);
		if(to[i]==-1)continue;
		int res=(col[i]!=col[u]);
		if(det[u]==-1)det[u]=res^to[i];
		if(res^to[i]!=det[u])flag=0;
	}
	for(i=2;i<=n;i++)
	{
		if(find(i)!=i)continue;
		ans+=(det[i]==-1);
	}
	if(flag==0)	
	printf("0");
	else
	{
		for(i=1;i<=ans;i++)
		opt=opt*2%mod;
		
		cout<<opt;
	}
	return 0;
}

