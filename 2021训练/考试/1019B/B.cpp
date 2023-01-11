#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
template <typename _type>
void cmin(_type &x,_type y){x=min(x,y);}
template <typename _type>
void cmax(_type &x,_type y){x=max(x,y);}
struct point{
	int x,y;
};
const int N=514;
const int dx[]={0,0,1,-1},dy[]={-1,1,0,0};
int i,j,k,m,n,s,t,r1,c1,r2,c2;
int dis[N][N],from[N][N][4];
queue<point> q; 
vector<int> e[N][2];
int checkDir(int x,int tox)
{
	if(x-tox==1)return 0;
	if(x-tox==n)return 1;
	if(tox-x==1)return 2;
	return 3;
}
int ok(int x,int y)
{
	return x>0&&y>0&&x<=n&&y<=n;
}
void bfs()
{
	while(!q.empty())
	{
		int x=q.front().x,y=q.front().y;q.pop();
		for(int vx:e[x][0])
		{
			for(int vy:e[y][1])
			{
				int *pd=from[vx][vy];
				pd[checkDir(x,vx)]=0;
				if(!pd[0]&&!pd[1]&&!pd[2]&&!pd[3]&&dis[vx][vy]==-1)
				{
					dis[vx][vy]=dis[x][y]+2;
					q.push((point){vx,vy});
				}
			}
		}
	}
}
int main()
{
	memset(dis,-1,sizeof(dis));
	read(n),read(r1),read(c1),read(r2),read(c2);
	if(abs(r1-r2)+abs(c1-c2)==1)
	{
		printf("YUYUKO 1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		for(k=0;k<4;k++)
		for(int op=1;op<=2;op++)
		{
			int toi=i+op*dx[k],toj=j+op*dy[k];
			if(ok(toi,toj))
			{
				e[(i-1)*n+j][op-1].push_back((toi-1)*n+toj);
				if(op==1)e[(i-1)*n+j][op].push_back((toi-1)*n+toj);
			}
		}
	}
	for(i=1;i<=n*n;i++)
	{
		dis[i][i]=0;
		q.push((point){i,i});
		for(j=1;j<=n*n;j++)
		{
			for(int v:e[i][0])
			from[v][j][checkDir(i,v)]=1;
		}
	}
	bfs();
	printf("YUKARI %d\n",dis[(r1-1)*n+c1][(r2-1)*n+c2]);
	return 0;
}

