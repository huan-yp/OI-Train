#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m,ans;
const int N=1<<8;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char ch[21][21];
int dp[21][21][N],vis[21][21][N],mp[N][N],g[N],w[N],val[N][N];
struct node{
	int x,y,s;
}p;
queue<node> q;
void bfs()
{
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		if(now.x==4&&now.y==9&&now.s==0)
		t=t;
		for(int j=0;j<4;j++)
		{
			int x=now.x+dx[j],y=now.y+dy[j],s=now.s;
			if(j<=1)
			{
				int x0=x-(j==0);
				for(i=y;i<=m;i++)
				if(~val[x0][i])
				s^=(1<<val[x0][i]);
			}
			if(x>n||x<1||y>m||y<1||mp[x][y]||vis[x][y][s])continue;
			dp[x][y][s]=dp[now.x][now.y][now.s]+1;
			vis[x][y][s]=1;
			node np=(node){x,y,s};
			q.push(np);
		}
	}
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dp,1,sizeof(dp));
	int px,py;
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
		for(j=1;j<=m;j++)
		{
			if(ch[i][j]=='S')px=i,py=j;
			if(ch[i][j]!='.'&&ch[i][j]!='S')mp[i][j]=1;
			if((ch[i][j]>='0'&&ch[i][j]<='9'))
			val[i][j]=ch[i][j]-'1',t++;
			if((ch[i][j]>'9'||ch[i][j]<'0')&&ch[i][j]!='B')val[i][j]=-1;
		}
	}
	for(i=0;i<t;i++)
	read(w[i]);
	int lst=t;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	if(ch[i][j]=='B')
	val[i][j]=t++;
	
	for(i=lst;i<t;i++)
	w[i]=-1e8;//不然一会爆int 
	for(i=1;i<1<<t;i++)
	for(j=0;j<t;j++)
	if(i&(1<<j))
	g[i]+=w[j];
	
	q.push((node){px,py,0});
	vis[px][py][0]=1,dp[px][py][0]=0;
	bfs();
	for(i=0;i<1<<t;i++)
	ans=max(ans,g[i]-dp[px][py][i]);
	cout<<ans;
	return 0;
}
