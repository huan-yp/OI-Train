#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int N=2005;
int i,j,k,m,n,s,t;
int len[N][N],st[N][N][12],pd[N][N],vis[N][N];
queue<int> q;
vector<int> e[N];
void bfs(int x)
{
	q.push(x);pd[x][x]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])
		{
			if(pd[x][v])continue;
			pd[x][v]=1;
			q.push(v);
		}
	}
}
int calc(int x,int y)
{
	if(x==y)return len[x][y]=1;
	if(vis[x][y])return -1;
	if(len[x][y])return len[x][y];
	int minu=1e9;
	for(int v:e[x])
	{
		if(pd[v][y])
		cmin(minu,v);
	}
	if(minu==1e9)return len[x][y]=-1;
	vis[x][y]=1;
	int nxt=calc(minu,y);
	vis[x][y]=0;
	if(nxt==-1)return len[x][y]=-1;
	else st[x][y][0]=minu;
	return len[x][y]=nxt+1;
}
void init()
{
	for(k=1;k<=10;k++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(i==j)continue;
		if(len[i][j]==-1)continue;
		st[i][j][k]=st[st[i][j][k-1]][j][k-1];
	}
}
int ask(int x,int y,int step)
{
	for(int i=10;i>=0;i--)
	{
		if(1<<i&step)
		x=st[x][y][i];
	}
	return x;
}
int main()
{
	read(n),read(m),read(s);
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(y);
	}
	for(i=1;i<=n;i++)
	bfs(i);
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	{
		calc(i,j);
		calc(j,i);
	}
	for(i=1;i<=n;i++)
	len[i][i]=1;
	init();
	for(i=1;i<=s;i++)
	{
		int x,y;
		read(x),read(y),read(k);
		if(len[x][y]<k)
		printf("-1\n");
		else
		printf("%d\n",ask(x,y,k-1));
	}
	return 0;
}

