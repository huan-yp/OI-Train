#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline void read(int &x)
{
	scanf("%d",&x);
}
const int N=565;
int i,j,k,n,s,t,m,p;
char ch[N][N];
int vis[N][N];
void dfs(int x,int y)
{
	if(x<=0||x>n||y<=0||y>m)return;
	if(vis[x][y])return;
	vis[x][y]=1;
	if(ch[x][y]==ch[x+1][y])p=0;
	if(ch[x][y]==ch[x-1][y])p=0;
	if(ch[x][y]==ch[x][y+1])p=0;
	if(ch[x][y]==ch[x][y-1])p=0;
	if(ch[x][y]=='R')
	ch[x][y+1]=ch[x][y-1]=ch[x-1][y]=ch[x+1][y]='W';
	else
	ch[x][y+1]=ch[x][y-1]=ch[x-1][y]=ch[x+1][y]='R';
	dfs(x+1,y);dfs(x-1,y);
	dfs(x,y+1);dfs(x,y-1);
}
int main()
{
	read(t);
	while(t--)
	{
		p=1;
		int flag=0,posx,posy;
		memset(ch,0,sizeof(ch));
		memset(vis,0,sizeof(vis));
		read(n),read(m);
		for(i=1;i<=n;i++)
		cin>>(ch[i]+1);
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		if(ch[i][j]=='W'||ch[i][j]=='R')
		{
			posx=i,posy=j;
			flag=1;
		}
		if(flag==0)
		ch[1][1]='W',posx=posy=1;
		dfs(posx,posy);
		if(p==0)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%c",ch[i][j]);
			}
			printf("\n");
		}
	} 
	return 0;
}


