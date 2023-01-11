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
const int N=2e5+10;
int i,j,k,n,s,t,m,root,flag;
int p[N],b[N],dis[N],dfn[N],in[N],cnt[N];
queue<int> q;
vector<int> e[N];
void dfs(int u)
{
	dfn[u]=++t;in[u]=1;
	for(int v:e[u])
	{
		if(dfn[v])
		{
			if(in[v])flag=1;
		}
		else
		dfs(v);
	}
	in[u]=0;
}
void spfa()
{
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int v:e[u])
		{
			cmax(dis[v],dis[u]+1);
			cnt[v]--;
			if(cnt[v]==0)q.push(v);
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot;read(tot);
	while(tot--)
	{
		read(n);flag=0;
		for(i=1;i<=n;i++)
		dfn[i]=0,e[i].clear(),dis[i]=0,cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			read(b[i]);if(b[i]==i){root=i;continue;}
			e[b[i]].push_back(i);cnt[i]++;
		}
		for(i=1;i<=n;i++)read(p[i]);
		for(i=1;i<n;i++)
		e[p[i]].push_back(p[i+1]),cnt[p[i+1]]++;
		
		dfs(root);
		if(flag==1)
		{
			puts("-1");
			continue;
		}
		q.push(root);
		spfa();
		for(i=1;i<=n;i++)
		printf("%d ",dis[i]-dis[b[i]]);
		cout<<endl;
	}
	return 0;
}

