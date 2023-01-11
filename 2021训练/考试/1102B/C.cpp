#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while((ch<='9'&&ch>='0'))x=x*10+ch-48,ch=getchar();
	x*=f;
}

void cmin(int &x,int y){x=min(x,y);}
void cmax(int &x,int y){x=max(x,y);}
const int N=1e6+10;
int i,j,k,m,n,s,t,ans;
int fa[N],col[N],dis[N],rk[N];
vector<pair<int,int>> e[N];
vector<int> from[N];
queue<int> q;
void bfs()
{
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto tmp:e[u])
		{
			int v=tmp.first,rk=tmp.second;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q.push(v);
			}
			if(dis[v]==dis[u]+1)
			from[v].push_back(rk);
		}
	}
}
int main()
{
	memset(dis,1,sizeof(dis));
	read(n),read(m);
	read(s),read(t);
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		e[x].push_back(make_pair(y,i));
		e[y].push_back(make_pair(x,i));
	}
	dis[s]=0;
	bfs();
	
	for(i=1;i<=n;i++)
	{
		if(dis[i]>=dis[t]&&t!=i)continue;
		for(int v:from[i])
		col[v]=dis[i];
	}
	for(auto tmp:e[t])
	{
		int v=tmp.first,rk=tmp.second;
		col[rk]=dis[t];
	}
	ans=dis[t];

	cout<<ans<<endl;
	for(i=1;i<=m;i++)
	printf("%d\n",col[i]);
	return 0;
}
