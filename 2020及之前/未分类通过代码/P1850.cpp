#include<bits/stdc++.h>
#define y1 y749872
#define next nxt
using namespace std;
int i,j,k,n,s,t,m;
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	{
		num=num*10+ch-48;
		ch=getchar();
	}
	return num;
}
int mp[301][301],v,e,a[2001],b[2001];
double dp[2001][2011][2],p[2001]; 
double miin(double x,double y)
{
	return x<y?x:y;
}
int main()
{
	//freopen("P1850_18.in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(i=1;i<=v;i++)
	for(j=1;j<=v;j++)
	if(i!=j)
	mp[i][j]=1e9;
	for(i=1;i<=n;i++)
	a[i]=read();
	for(i=1;i<=n;i++)
	b[i]=read();
	for(i=1;i<=n;i++)
	scanf("%lf",&p[i]);
	int x,y,w;
	for(i=1;i<=e;i++)
	{
		x=read(),y=read(),w=read();
		mp[x][y]=min(mp[x][y],w);
		mp[y][x]=min(mp[y][x],w);
	}
	for(k=1;k<=v;k++)
	for(i=1;i<=v;i++)
	for(j=1;j<=v;j++)
	mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	for(i=0;i<=n;i++)
	for(j=0;j<=m;j++)
	dp[i][j][1]=dp[i][j][0]=1e9+10;
	dp[1][1][1]=0,dp[1][0][0]=0;
	for(i=2;i<=n;i++)
	for(j=0;j<=min(i,m);j++)
	{
		if(j)
		dp[i][j][1]=miin(dp[i-1][j-1][1]+mp[b[i-1]][b[i]]*p[i]*p[i-1]+mp[a[i-1]][b[i]]*(1-p[i-1])*p[i]+mp[b[i-1]][a[i]]*(1-p[i])*p[i-1]+mp[a[i-1]][a[i]]*(1-p[i])*(1-p[i-1]),dp[i-1][j-1][0]+mp[a[i-1]][b[i]]*p[i]+mp[a[i-1]][a[i]]*(1-p[i]));
		dp[i][j][0]=miin(dp[i-1][j][1]+mp[b[i-1]][a[i]]*p[i-1]+mp[a[i-1]][a[i]]*(1-p[i-1]),dp[i-1][j][0]+mp[a[i-1]][a[i]]);
	}
	double ans=1e9;
	for(i=0;i<=m;i++)
	ans=miin(ans,miin(dp[n][i][1],dp[n][i][0]));
	printf("%0.2lf",ans);
	return 0;
}
