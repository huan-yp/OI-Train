#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();int x=0,r=1;
	while(ch<'0'||ch>'9'){if(ch=='-')r=0;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return r?x:-x;
}
struct node
{
	int v,next;
}e[1001000];
int head[1001000],cnt,tot;
bool b[1001000];
char s[5];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int n,x,sum[1001000],fail[1001000],suc[1001000];
struct cmp
{
	bool operator()(int a,int b)
	{
		return fail[a]*sum[b]>fail[b]*sum[a];
	}
};
void dfs(int u)
{
	priority_queue<int,vector<int>,cmp> q;
	sum[u]=0;fail[u]=2;
	if(head[u]==0)tot++,sum[u]++;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		dfs(v);
		sum[u]+=sum[v];fail[u]+=fail[v];
		q.push(v);
	}
	int summ=sum[u];
	while(!q.empty())
	{
		x=q.top();q.pop();
		summ-=sum[x];
		suc[u]+=sum[x]+suc[x]+fail[x]*summ;
	}
	if(b[u])fail[u]=2;
}
signed main()
{
	freopen("street.in","r",stdin);
	freopen("street.out","w",stdout);
	n=read();
	for(int i=2;i<=n;++i)
	{
		x=read();add(x,i);
		scanf("%s",s+1);b[i]=(s[1]=='Y');
	}
	dfs(1);
	printf("%.8lf\n",1.0*suc[1]/tot);
	return 0;
}
