#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m,p;
const int N=1e5+10;
int vis[N],dis[N];
set<int> st[2];
set<int> ::iterator it;
queue<int> q;
void bfs()
{
	while(!q.empty())
	{
		int u=q.front();q.pop();
		while(1)
		{
			it=st[(u&1)^p].lower_bound(u+k-1-min(u-1,k-1)*2);
			if(it==st[(u&1)^p].end()||(*it)>u-k+1+min(n-u,k-1)*2)break;
			int v=(*it);
			q.push(v),dis[v]=dis[u]+1;
			st[(u&1)^p].erase(it);
		}
	}
}
//https://csacademy.com/contest/round-11/task/a-single-one
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dis,15,sizeof(dis));
	cin>>n>>k>>m>>s;
	p=(k&1)^1;
	for(i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		vis[x]=1;
	}
	for(i=1;i<=n;i++)
	if(vis[i]==0&&i!=s)
	st[i&1].insert(i);
	if(vis[s]==0)dis[s]=0,q.push(s);
	bfs();
	for(i=1;i<=n;i++)
	if(dis[i]<=1e8)
	printf("%d ",dis[i]);
	else
	printf("-1 ");
	return 0;
}


