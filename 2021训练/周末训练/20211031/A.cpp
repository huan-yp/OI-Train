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
const int N=1505;
const int dx[2][8] = { { 0, 1, -1, 0 }, { -1, -1, -1, 0, 0, 1, 1, 1 } };
const int dy[2][8] = { { 1, 0, 0, -1 }, { -1, 0, 1, -1, 1, -1, 0, 1 } };
int i,j,k,n,s,t,m,p,r;
int dis[N][N],from[N][N][2],vis[N][N];
char ch[N][N];
deque<pair<int,int> > q;
int ok(int x,int y)
{
	if(x<1||y<1||x>n||y>m)return 0;
	return 1;
}
void bfs()
{
	while(!q.empty())
	{
		int x=q.front().first,y=q.front().second;q.pop_front();
		if(vis[x][y])continue;
		vis[x][y]=1;
		if(dis[x][y]%(p+r) == 0)
		{
			for(k=0;k<4;k++)
			{
				int tox=x+dx[0][k],toy=y+dy[0][k];
				if(ok(tox,toy)==0)continue;
				if(ch[tox][toy]=='@')
				{
					for(int k=0;k<4+(p!=0)*4;k++)
					{
						int tox=x+dx[(p!=0)][k],toy=y+dy[(p!=0)][k];
						if(ok(tox,toy)==0)continue;
						if(dis[tox][toy]<=dis[x][y]+1)continue;
						from[tox][toy][0]=x,from[tox][toy][1]=y;
						dis[tox][toy]=dis[x][y]+1;
						q.push_back(make_pair(tox,toy));
					}
				}
				else
				{
					if(dis[x][y]>=dis[tox][toy])continue;
					dis[tox][toy]=dis[x][y];
					from[tox][toy][0]=x,from[tox][toy][1]=y;
					q.push_front(make_pair(tox,toy));
				}
			}
			continue;
		}
		if(dis[x][y]%(p+r)<p)
		{
			for(k=0;k<8;k++)
			{
				int tox=x+dx[1][k],toy=y+dy[1][k];
				if(ok(tox,toy)==0)continue;
				if(dis[tox][toy]<=dis[x][y]+1)continue;
				dis[tox][toy]=dis[x][y]+1;
				from[tox][toy][0]=x,from[tox][toy][1]=y;
				q.push_back(make_pair(tox,toy));
			}
		}
		else
		{
			for(k=0;k<4;k++)
			{
				int tox=x+dx[0][k],toy=y+dy[0][k];
				if(ok(tox,toy)==0)continue;
				if(dis[tox][toy]<=dis[x][y]+1)continue;
				dis[tox][toy]=dis[x][y]+1;
				from[tox][toy][0]=x,from[tox][toy][1]=y;
				q.push_back(make_pair(tox,toy));
			}
		}
	}
}
void print(int x,int y)
{
	if(dis[x][y]==0)return ;
	print(from[x][y][0],from[x][y][1]);
	if(dis[x][y]%(p+r)==1||((p+r)==1&&dis[x][y]==dis[from[x][y][0]][from[x][y][1]]+1))
	printf("%d %d\n",from[x][y][0],from[x][y][1]);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m),read(p),read(r);p/=2;
	memset(dis,1,sizeof(dis));
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
		for(j=1;j<=m;j++)
		if(ch[i][j]=='S')
		{
			q.push_back(make_pair(i,j));
			dis[i][j]=0;
		}
	}
	bfs();
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	if(ch[i][j]=='E')
	{
		if(dis[i][j]==0)
		printf("0\n");
		else
		{
			printf("%d\n",(dis[i][j]-1)/(p+r)+1);
			print(i,j);
		}
	}
	return 0;
}

