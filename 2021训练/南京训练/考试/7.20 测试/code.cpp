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
struct edge{
	int first,second,val;
};
struct point{
	int x,y,val1,val2;
	friend bool operator <(const point &a,const point &b)
	{
		if(a.val1!=b.val1)
		return a.val1<b.val1;
		return a.val2<b.val2;
	}
};
const int N=2005; 
int i,j,k,n,s,t,m,ans=-1;
int dp[N][N],ed[N],son[N][2];
char ch[N];
edge re[N][N];
vector <edge> e[N][N];
vector <point> v;
void add(int u,int now)
{
	if(now==m+1)
	{
		ed[u]=1;
		return;
	}
	if(son[u][ch[now]-'0']==0)
	son[u][ch[now]-'0']=++t;
	add(son[u][ch[now]-'0'],now+1);
}
void addedge(int x1,int y1,int x2,int y2,int val)
{
	e[x1][y1].push_back((edge){x2,y2,val});
}
void printPath(int x,int y)
{
	if(x==0&&y==0)return;
	printPath(re[x][y].first,re[x][y].second);
	printf("%d",re[x][y].val);
}
void bfs()
{
	dp[0][0]=1;v.clear();
	v.push_back((point){0,0,0,0});
	while(1)
	{
		sort(v.begin(),v.end());
		vector<point> tmp;tmp.clear();
		if(v.size()==0)break;
		for(i=0;i<v.size();i++)
		{
			int x1=v[i].x,y1=v[i].y;
			if(x1!=y1&&ed[x1]&&ed[y1])
			{
				ans=1;
				printPath(x1,y1);
				break;
			}
			for(edge nxt:e[x1][y1])
			{
				int x2=nxt.first,y2=nxt.second,val=nxt.val;
				if(dp[x2][y2])continue;
				dp[x2][y2]=1;
				re[x2][y2]=(edge){x1,y1,val};
				tmp.push_back((point){x2,y2,i,val});
			}
		}
		if(ans!=-1)break;
		v=tmp;
	}
}
signed main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	//freopen(".ans","w",sdtout)
	int tot;read(tot);
	while(tot--)
	{
		t=0,ans=-1;
		read(n);
		memset(son,0,sizeof(son));memset(ed,0,sizeof(ed));
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			scanf("%s",ch+1);
			m=strlen(ch+1);
			add(0,1);
		}
		for(i=0;i<=t;i++)
		for(j=0;j<=t;j++)
		e[i][j].clear();
		
		for(i=0;i<=t;i++)
		for(j=0;j<=t;j++)
		{
			if(ed[i]&&son[0][1]&&son[j][1])
			addedge(i,j,son[0][1],son[j][1],1);
			if(ed[i]&&son[0][0]&&son[j][0])
			addedge(i,j,son[0][0],son[j][0],0);
			if(ed[j]&&son[0][1]&&son[i][1])
			addedge(i,j,son[i][1],son[0][1],1);
			if(ed[j]&&son[0][0]&&son[i][0])
			addedge(i,j,son[i][0],son[0][0],0);
			if(ed[i]&&ed[j]&&son[0][0])
			addedge(i,j,son[0][0],son[0][0],0);
			if(ed[i]&&ed[j]&&son[0][1])
			addedge(i,j,son[0][1],son[0][1],1);
			if(son[i][1]&&son[j][1])
			addedge(i,j,son[i][1],son[j][1],1);
			if(son[i][0]&&son[j][0])
			addedge(i,j,son[i][0],son[j][0],0);
		}
		bfs();
		if(ans==-1)
		printf("-1");
		
		printf("\n");
	}
	return 0;
}

