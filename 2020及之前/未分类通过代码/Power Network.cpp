#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define y1 y749872
#define next nxt
using namespace std;
int j,k,n,s,t,m,__be,__ed;
const int N=1e5+10;
int head[N],now[N],dep[N];
struct fu{
	int next,v,val;
}a[N];
queue <int> q;
int bfs()
{
	int i;
	while(!q.empty())
	q.pop();
	q.push(__be);
	for(i=__be;i<=__ed;i++)
	now[i]=head[i],dep[i]=0;
	dep[__be]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(i=head[u];i;i=a[i].next)
		{
			int v=a[i].v;
			if(dep[v]||a[i].val==0)
			continue;
			dep[v]=dep[u]+1;
			q.push(v);
			if(v==__ed)
			return 1;
		}
	}
	return 0;
}
int dfs(int u,int Min)
{
	if(u==__ed)
	return Min;
	int i;
	int ret=0;
	for(i=now[u];i;i=a[i].next)
	{
		int v=a[i].v;
		if(dep[v]!=dep[u]+1)
		continue;
		if(Min==0)
		return ret;
		int xx=min(Min,a[i].val);
		if(xx==0)
		continue;
		now[u]=i;
		int tmp=dfs(v,xx);
		if(tmp==0)
		dep[v]=1e9;
		a[i].val-=tmp;
		a[i+(i%2?1:-1)].val+=tmp;
		Min-=tmp;
		ret+=tmp;
	}
	return ret;
}
void work(int aa,int bb,int cc)
{
	a[++k].next=head[aa];
	head[aa]=k;
	a[k].v=bb;
	a[k].val=cc;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int n1,n2,i,x,y,f,d;
	while(~scanf("%d%d%d",&n,&f,&d))
	{
		k=0;
		memset(head,0,sizeof(head));
		int z;
		__be=0,__ed=n*2+d+f+1;
		for(i=1;i<=f;i++)
		{
			scanf("%d",&z);
			work(__be,i,z);
			work(i,__be,0);
		}
		for(i=1;i<=d;i++)
		{
			scanf("%d",&z);
			work(i+n*2+f,__ed,z);
			work(__ed,i+n*2+f,0);
		}
		char ch[2004];
		for(i=1;i<=n;i++)
		{
			work(f+i,f+n+i,1);
			work(f+n+i,f+i,0);
			scanf("%s",ch+1);
			for(j=1;j<=f;j++)
			if(ch[j]=='Y')
			{
				work(j,f+i,1);
				work(f+i,j,0);	
			} 
		}
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch+1);
			for(j=1;j<=d;j++)
			if(ch[j]=='Y')
			{
				work(j+n+n+f,f+i+n,0);
				work(f+i+n,j+n+n+f,1);	
			} 
		}
		int ans=0;
		while(bfs())
		ans+=dfs(__be,1e9);
		printf("%d\n",ans);
	}
	return 0;
}

