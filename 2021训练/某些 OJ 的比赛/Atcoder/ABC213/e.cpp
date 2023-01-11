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
struct state{
	int val,x,y;
	friend bool operator <(state a,state b)
	{
		return a.val>b.val;
	}
	friend bool operator >(state a,state b)
	{
		return a.val<b.val;
	}
};
const int N=505;
int i,j,k,n,s,t,m;
int dp[N][N],vis[N][N];
char ch[N][N];
vector<state> e[N][N]; 
priority_queue<state> q;
void bfs()
{
	q.push((state){0,1,1});
	dp[1][1]=0;
	while(!q.empty())
	{
		int x=q.top().x;
		int y=q.top().y;q.pop();
		if(vis[x][y])continue;
		vis[x][y]=1;
		for(state v:e[x][y])
		{
			int x0=v.x,y0=v.y,val=v.val;
			if(dp[x0][y0]<=dp[x][y]+val)continue;
			dp[x0][y0]=dp[x][y]+val;
			q.push((state){dp[x0][y0],x0,y0});
		}
	}
}
int ok(int lim,int tar)
{
	if(tar>=1&&tar<=lim)
	return 1;
	return 0;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dp,1,sizeof(dp));
	read(n),read(m);
	for(i=1;i<=n;i++)
	scanf("%s",ch[i]+1);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(ch[i][j+1]=='.')e[i][j].push_back((state){0,i,j+1});
		if(ch[i][j-1]=='.')e[i][j].push_back((state){0,i,j-1});
		if(ch[i+1][j]=='.')e[i][j].push_back((state){0,i+1,j});
		if(ch[i-1][j]=='.')e[i][j].push_back((state){0,i-1,j});
		for(int di=-2;di<=2;di++)
		for(int dj=-2;dj<=2;dj++)
		if(abs(di)+abs(dj)!=4&&ok(n,di+i)&&ok(m,dj+j))
		e[i][j].push_back((state){1,i+di,j+dj});
	}
	
	bfs();
	printf("%d\n",dp[n][m]);
	return 0;
}

