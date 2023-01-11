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
template <typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template <typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e6+10;
int i,j,k,m,n,s,t,ans;
int dis[N],d[N];
vector<int> e[N];
queue<int> q;
void print(int x,int dep=1)
{
	if(x==0)return ;
	for(i=0;i<10;i++)
	{
		if(d[i])continue;
		int to=(x*10+i)%n;
		if(dep+dis[to]==ans)
		{
			printf("%d",i);
			print(to,dep+1);
			return ;
		}
	}
}
void bfs()
{
	q.push(0);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])
		{
			if(dis[v])continue;
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
}
int main()
{
//	freopen("lucky.in","r",stdin);
//	freopen("lucky.out","w",stdout);
	read(n),read(k);
	
	for(i=1;i<=k;i++)
	{
		int x;read(x);
		d[x]=1;
	}
	if(n==1)
	{
		if(d[1])
		printf("-1\n");
		else
		printf("1\n");	
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=(i==n);j<10;j++)
		{
			if(d[j])continue;
			int to=(i*10+j)%n;
			e[to].push_back(i);
		}
	}
	bfs();
	ans=dis[n];
	if(ans==0)
	{
		printf("-1\n");
		return 0;
	}
	print(n);
	return 0;
}

