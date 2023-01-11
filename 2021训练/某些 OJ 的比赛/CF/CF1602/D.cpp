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
const int N=1e6+10;
struct edge{
	int v,val;
};
int i,j,k,n,s,t,m;
int a[N],dis[N],b[N],vis[N],from[N];
vector<edge> e[N];
priority_queue<pair<int,int>> q;
void dij()
{
	memset(dis,31,sizeof(dis));dis[n]=0;
	q.push(make_pair(0,n));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();if(vis[u])continue;
		vis[u]=1;
		for(edge tmp:e[u])
		{
			int v=tmp.v,val=tmp.val;
			if(dis[v]<=dis[u]+val)continue;
			dis[v]=dis[u]+val;
			from[v]=u;
			q.push(make_pair(-dis[v],v));
		}
	}
}
void print(int x,int exp=0)
{
	if(x==n)return ;
	if(from[x]<=n)
	print(from[x],-1);
	else
	print(from[x],exp+1);
	
	if(from[x]<=n)
	printf("%d ",x-n-1+exp);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int T=1;
	while(T--)
	{
		read(n);
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			e[i].push_back((edge){i+n+1-a[i],1});
		}
		for(i=1;i<=n;i++)
		{
			read(b[i]);
			e[i+n+1].push_back((edge){i+b[i],0});
			e[i+n+1].push_back((edge){i+n+2,0});
		}
		dij();
		if(dis[n+1]>1e7)
		printf("-1\n");
		else
		{
			printf("%d\n",dis[n+1]);
			print(n+1);
			printf("\n");
		}
	}
	return 0;
}

