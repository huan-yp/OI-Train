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



*/
const int N=1000005;
int i,j,k,n,s,t=1,m,lst=1,top;
LL ans;
struct SAM{
	int ch[2],fa,len;
}a[N];
struct nod{
	int ls,rs,val;
}node[N*30];
struct query{
	int l,r,end;
	friend bool operator <(query a,query b)
	{
		return a.end<b.end;
	}
};
int st[N],r[N],sum[N],endpos[N],val[N],T[N]; 
char ch[N];
vector<int> pos[N],e[N];
vector<query> q[N];
void push_up(int rt)
{
	node[rt].val=node[node[rt].ls].val+node[node[rt].rs].val;
}
void updata(int l,int r,int rt,int x,int cc)
{
	if(l==r)
	{
		node[rt].val+=cc;
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid)
	{
		if(node[rt].ls==0)node[rt].ls=++k;
		updata(l,mid,node[rt].ls,x,cc);
	}
	else
	{
		if(node[rt].rs==0)node[rt].rs=++k;
		updata(mid+1,r,node[rt].rs,x,cc);
	}
	push_up(rt);
}
int quert(int l,int r,int rt,int x,int y)
{
	if(x>y)return 0;
	if(x<=l&&y>=r)
	return node[rt].val;
	int ret=0,mid=l+r>>1;
	if(x<=mid)
	ret+=quert(l,mid,node[rt].ls,x,y);
	if(y>mid)
	ret+=quert(mid+1,r,node[rt].rs,x,y);
	return ret;
}
void add(int c)
{
	int np=++t;a[np].len=a[lst].len+1;
	endpos[np]=i;
	while(lst&&a[lst].ch[c]==0)
	a[lst].ch[c]=np,lst=a[lst].fa;
	if(lst==0)
	a[np].fa=1;
	else
	{
		int q=a[lst].ch[c];
		if(a[q].len==a[lst].len+1)
		a[np].fa=q;
		else
		{
			int nq=++t;a[nq]=a[q],a[nq].len=a[lst].len+1;
			a[q].fa=a[np].fa=nq;
			while(lst&&a[lst].ch[c]==q)
			a[lst].ch[c]=nq,lst=a[lst].fa;
		}
	}
	lst=np;
}
void dfs(int u,int fa)
{
	for(int v:e[u])
	{
		if(v==fa)continue;
		dfs(v,u);
		if(endpos[u]==0)
		endpos[u]=endpos[v];
	}
	if(u==1)return;
	int leftLimit=endpos[u]-a[u].len+1;
	int rightLimit=endpos[u]-a[a[u].fa].len;
	q[val[endpos[u]]+N/2].push_back((query){leftLimit,rightLimit,endpos[u]});
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	scanf("%s",ch+1);
	for(i=1;i<N;i++)
	pos[i].push_back(0),T[i]=++k;
	
	pos[N/2].push_back(0);
	for(i=1;i<=n;i++)
	{
		add(ch[i]=='(');
		val[i]=val[i-1]+(ch[i]=='('?1:-1);
		pos[val[i]+N/2].push_back(i);
	}
	for(i=1;i<N;i++)
	pos[i].push_back(n+1);
	
	val[n+1]=-INF,st[++top]=n+1;
	for(i=n;i>=0;i--)
	{
		while(val[st[top]]>=val[i])top--;
		r[i]=st[top];
		st[++top]=i;
	}
	for(i=1;i<=t;i++)
	e[a[i].fa].push_back(i);
	dfs(1,0);
	
	for(i=N/2-n;i<=N/2+n;i++)
	{
		if(pos[i].size()==2)continue;
		sort(q[i].begin(),q[i].end());
		int now=q[i].size()-1;
		for(j=pos[i].size()-2;j;j--)
		{
			int posi=pos[i][j];
			while(now>-1&&q[i][now].end>=r[posi])
			{
				ans+=quert(1,n+1,T[i],1,q[i][now].r);
				ans-=quert(1,n+1,T[i],1,q[i][now].l-1);
				now--;
			}
			updata(1,n+1,T[i],pos[i][j]+1,1);
		}
		while(now>-1)
		{
			ans+=quert(1,n+1,T[i],1,q[i][now].r);
			ans-=quert(1,n+1,T[i],1,q[i][now].l-1);
			now--;
		}
	}
	cout<<ans;
	return 0;
}
