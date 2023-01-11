#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<48))ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while(ch<='9'&&ch>47)x=x*10+ch-48,ch=getchar();
	x*=f;
}
const int N=2005;
int i,j,k,n,s,t,m,flag;
char ch[N][N];
int dp[N][N],cnt[N],col[N];
vector<int> e[N];
void dfs(int u)
{
	cnt[col[u]]++;
	for(int v:e[u])
	{
		if(~col[v])
		{
			if(col[v]==col[u])
			flag=1;
		}
		else
		{
			col[v]=col[u]^1;
			dfs(v);
		}
	}
}
int main()
{
	memset(col,-1,sizeof(col));
	read(n),read(m);
	for(i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
		for(j=i+1;j<=n;j++)
		{
			if(ch[i][j]=='0')
			e[i].push_back(j),e[j].push_back(i);
		}
	}
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		if(~col[i])continue;
		++s;col[i]=cnt[0]=cnt[1]=0;dfs(i);
		for(j=0;j<=n;j++)
		{
			if(j>=cnt[0])dp[s][j]|=dp[s-1][j-cnt[0]];
			if(j>=cnt[1])dp[s][j]|=dp[s-1][j-cnt[1]];
		}
	}
	if(flag)
	{
		puts("-1");
		return 0;
	}
	int ideal=0;
	for(i=1;i<=n/2;i++)
	if(dp[s][i])ideal=i;
	
	int ans=(n-ideal)*(n-ideal-1)/2+ideal*(ideal-1)/2;
	cout<<ans<<endl;
	return 0;
}
