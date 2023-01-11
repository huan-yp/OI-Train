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
const int N=1e5+10;
int i,j,k,n,s,t,m;
int dp[2][N];
char ch[N],str[N];
int son[N][26],fail[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s%s",str+1,ch+1);
	n=strlen(ch+1),m=strlen(str+1);
	for(i=0;i<n;i++)
	{
		if(i>1)
		fail[i]=son[fail[i-1]][ch[i]-'a'];
		for(j=0;j<26;j++)
		if(ch[i+1]=='a'+j)
		son[i][j]=i+1;	
		else
		son[i][j]=son[fail[i]][j];
	}
	if(n>1)
	fail[n]=son[fail[n-1]][ch[n]-'a'];
	memset(dp,191,sizeof(dp));
	dp[0][0]=0;
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
		if(dp[i&1][j]<0)continue;
		if(str[i+1]=='?')
		{
			for(k=0;k<26;k++)
			{
				int v=son[j][k];
				if(v==n)
				v=fail[v],dp[(i+1)&1][v]=max(dp[i&1][j]+1,dp[(i+1)&1][v]);
				else
				dp[(i+1)&1][v]=max(dp[i&1][j],dp[(i+1)&1][v]);
			}	
		}
		else
		{
			int v=son[j][str[i+1]-'a'];
			if(v==n)
			v=fail[v],dp[(i+1)&1][v]=max(dp[i&1][j]+1,dp[(i+1)&1][v]);
			else
			dp[(i+1)&1][v]=max(dp[i&1][j],dp[(i+1)&1][v]);
		}	
		dp[i&1][j]=-INF;
	}
	int ans=0;
	for(j=0;j<n;j++)
	ans=max(ans,dp[m&1][j]);
	
	cout<<ans;
	return 0;
}


