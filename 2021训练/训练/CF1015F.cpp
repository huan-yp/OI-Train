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
const int N=205,mod=1e9+7;
int i,j,k,n,s,t,m,ans;
int dp[N][N][N][2],nxt[N],to[N][2];
char ch[N];
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
signed main()
{
	read(n);
	scanf("%s",ch+1);
	m=strlen(ch+1);nxt[0]=j=-1;
	if(ch[1]=='(')to[0][0]=1,to[0][1]=0;
	if(ch[1]==')')to[0][0]=0,to[0][1]=1;
	for(i=1;i<=m;i++)
	{
		while(j!=-1&&ch[j+1]!=ch[i])j=nxt[j];
		nxt[i]=++j;
		if(ch[i]=='(')to[i-1][0]=i,to[i-1][1]=to[nxt[i-1]][1];
		if(ch[i]==')')to[i-1][0]=to[nxt[i-1]][0],to[i-1][1]=i;
	}
	dp[0][0][0][0]=1;
	for(i=0;i<2*n;i++)
	for(j=0;j<=i&&j<=n;j++)
	for(k=0;k<=m;k++)
	for(int p=0;p<=1;p++)
	{
		if(dp[i][j][k][p]==0)continue;
		int to0=to[k][0],to1=to[k][1];
		if(to0==m)Inc(dp[i+1][j+1][nxt[n]][1],dp[i][j][k][p]);
		else Inc(dp[i+1][j+1][to0][p],dp[i][j][k][p]);
		if(j)
		{	
			if(to1==m)Inc(dp[i+1][j-1][nxt[n]][1],dp[i][j][k][p]);
			else Inc(dp[i+1][j-1][to1][p],dp[i][j][k][p]);
		}
	}
	for(i=0;i<=m;i++)
	Inc(ans,dp[2*n][0][i][1]);
	cout<<ans<<endl;
	return 0;
}

