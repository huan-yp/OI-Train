#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LNF 1000000000000000000ll
#define LINF 1000000000ll
#define int long long
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
struct point{
	int x,y,rk;// 1:U 2:D 3:L 4:R
	char dir;
	friend bool operator <(const point &a,const point &b)
	{
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	}
};
struct edge{
	int v,val;
};
const int N=100005;
int i,j,k,n,s,t,m,m0,m1;
int dis[N],b[2][N],vis[N];//0 ->x 1->y
point a[N];
vector<edge> e[N];
vector<point> ax[N],ay[N];
priority_queue<pair<int,int> >q;
void dij()
{
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(edge tmp:e[u])
		{
			int v=tmp.v,val=tmp.val;
			if(dis[v]<=dis[u]+val)continue;
			dis[v]=dis[u]+val;
			q.push(make_pair(-dis[v],v));
		}
	}
}
signed main()
{
	//freopen("particles.in","r",stdin);
	//freopen("particles.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(t);
	for(i=1;i<=n;i++)
	{
		read(a[i].x),read(a[i].y);cin>>a[i].dir;
		a[i].rk=i;b[0][i]=a[i].x,b[1][i]=a[i].y;
		dis[i]=LNF;
	}
	sort(b[0]+1,b[0]+n+1),sort(b[1]+1,b[1]+n+1);
	m0=unique(b[0]+1,b[0]+n+1)-b[0]-1,m1=unique(b[1]+1,b[1]+n+1)-b[1]-1;
	
	for(i=1;i<=n;i++)
	{
		int x=lower_bound(b[0]+1,b[0]+m0+1,a[i].x)-b[0];
		int y=lower_bound(b[1]+1,b[1]+m1+1,a[i].y)-b[1];
		ax[x].push_back(a[i]);
		ay[y].push_back(a[i]);
	}
	for(i=1;i<=m0;i++)//handle elements with the same x
	{
		sort(ax[i].begin(),ax[i].end());
		for(j=0;j<ax[i].size();j++)
		{
			if(j>0&&ax[i][j].dir=='D')
			{
				int now=j;
				do{
					now--;
					e[ax[i][j].rk].push_back((edge){ax[i][now].rk,ax[i][j].y-ax[i][now].y});
				}while(now>0&&ax[i][now].dir!='D');
			}
			if(j<ax[i].size()-1&&ax[i][j].dir=='U')
			{
				int now=j;
				do{
					now++;
					e[ax[i][j].rk].push_back((edge){ax[i][now].rk,ax[i][now].y-ax[i][j].y});
				}while(now<ax[i].size()-1&&ax[i][now].dir!='U');
			}
		}
	}
	for(i=1;i<=m1;i++)
	{
		sort(ay[i].begin(),ay[i].end());
		for(j=0;j<ay[i].size();j++)
		{
			if(j>0&&ay[i][j].dir=='L')
			{
				int now=j;
				do{
					now--;
					e[ay[i][j].rk].push_back(edge{ay[i][now].rk,ay[i][j].x-ay[i][now].x});
				}while(now>0&&ay[i][now].dir!='L');
			}
			if(j<ay[i].size()-1&&ay[i][j].dir=='R')
			{
				int now=j;
				do{
					now++;
					e[ay[i][j].rk].push_back(edge{ay[i][now].rk,ay[i][now].x-ay[i][j].x});
				}while(now<ay[i].size()-1&&ay[i][now].dir!='R');
			}
		}
	}
	dis[1]=0;
	dij();
	for(i=1;i<=n;i++)
	{
		if(t<=dis[i])
		printf("%d %d\n",a[i].x,a[i].y);	
		else
		{
			if(a[i].dir=='U')printf("%d %d\n",a[i].x,a[i].y+t-dis[i]);
			if(a[i].dir=='D')printf("%d %d\n",a[i].x,a[i].y-t+dis[i]);
			if(a[i].dir=='L')printf("%d %d\n",a[i].x-t+dis[i],a[i].y);
			if(a[i].dir=='R')printf("%d %d\n",a[i].x+t-dis[i],a[i].y);
		}
	}
	return 0;
}//checked

