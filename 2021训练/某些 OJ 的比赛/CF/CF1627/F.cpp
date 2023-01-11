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
const int N=3e5+10,M=505;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
struct edge{
	int v,val;
};
int i,j,k,n,s,t,m;
int dis[N],vis[N],pd[M][M][4];
vector<edge> e[N];
priority_queue<pair<int,int>> q;
int ok(int x,int y){return x>0&&y>0&&x<=k&&y<=k;}
int get(int x,int y){return (x-1)*(k+1)+y;}
void dij()
{
	q.push(make_pair(0,1));dis[1]=0;
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vis[u])continue;vis[u]=1;
		for(auto tmp:e[u])
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
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n),read(k);
		for(i=1;i<=(k+1)*(k+1);i++)e[i].clear(),dis[i]=INF,vis[i]=0;
		for(i=1;i<=k+1;i++)
		for(j=1;j<=k+1;j++)
		pd[i][j][0]=pd[i][j][1]=pd[i][j][2]=pd[i][j][3]=0;
		
		for(i=1;i<=n;i++)
		{
			int x1,x2,y1,y2;
			read(x1),read(y1),read(x2),read(y2);
			if(x1!=x2)
			{
				if(x2>x1)swap(x1,x2);
				pd[x1][y1][1]++,pd[x1][y1+1][3]++;
				x1=k-x2+1,y1=k-y1+1;
				pd[x1][y1][1]++,pd[x1][y1+1][3]++;
			}
			else if(y1!=y2)
			{
				if(y2>y1)swap(y1,y2);
				pd[x1][y1][2]++,pd[x1+1][y1][0]++;
				x1=k-x1+1,y1=k-y2+1;
				pd[x1][y1][2]++,pd[x1+1][y1][0]++;
			}
		}
		for(i=1;i<=k+1;i++)
		for(j=1;j<=k+1;j++)		
		for(s=0;s<4;s++)
		{
			if(ok(i+dx[s],j+dy[s])==0)continue;
			e[get(i,j)].push_back((edge){get(i+dx[s],j+dy[s]),pd[i][j][s]});
		}
		dij();
		printf("%d\n",n-dis[get(k/2+1,k/2+1)]);
	}

	return 0;
}

