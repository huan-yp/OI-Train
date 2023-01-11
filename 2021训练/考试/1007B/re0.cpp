#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmin(int &x,int y){x=min(x,y);}
void cmax(int &x,int y){x=max(x,y);}
const int N=3e6+10,M=55;
int i,j,k,m,n,s,t;
string str[N],ans[N];
int dp[M][M][M*M],dir[M];
int ok(int x,int y)
{
	return x>0&&y>=0&&x<=n&&y<m;
}
int check(int x,int y,int time)
{
	y-=1;
	return str[x][((y-dir[x]*time)%m+m)%m]=='.'&&ok(x,y);
}
int dfs(int x,int y,int time)
{
	if(time<0)return 0;
	if(dp[x][y][time]!=-1)return dp[x][y][time];
	if(check(x,y,time)==0) return dp[x][y][time]=0;
	return dp[x][y][time]=(dfs(x,y%m+1,time-1)||dfs(x,((y-2)%m+m)%m+1,time-1)||dfs(x+1,y,time-1)||dfs(x-1,y,time-1)||dfs(x,y,time-1));
}
void solve1()
{
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(str[i][j]=='L')dir[i]=-1;
			if(str[i][j]=='R')dir[i]=1;
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[1][1][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			int flag=1;
			for(k=0;k<M*M;k++)	
			if(dfs(i,j,k))
			{
				printf("%d",k%10),flag=0;
				break;
			}
			if(flag)
			printf("-");
		}
		printf("\n");
	}
}
void solve2()
{
	
}
int main()
{
	freopen("re0.in","r",stdin);
	freopen("re0.out","w",stdout); 
	read(n),read(m);
	for(i=1;i<=n;i++)
	cin>>str[i];
	if(n*m<=10000)
	solve1();
	else
	solve2();

	return 0;
}

