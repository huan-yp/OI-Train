#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define size siz
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
/*



*/
int i,j,k,n,s,t,m,ans;
const int N=1e5+10,M=105,mod=1e9+7;
int dp[N][M][2][2],ans0[N],ans1[N],dep[N],size[N]; 
vector<int>a[N];
void dfs(int u,int op,int fa)
{
	size[u]++;
	if(op^dep[u]%2)
	dp[u][0][0][0]=1;
	else
	dp[u][1][1][0]=dp[u][0][0][0]=1;
	for(int v:a[u])
	{
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs(v,op,u);
		if(op^dep[u]%2)
		{
			for(i=min(size[u]+size[v],k);i>=0;i--)
			{
				LL v11=0,v00=0,v01=0,v10=0;
				for(j=min(size[v],i);j>=max(0,i-size[u]);j--)	
				{
					v00+=1ll*dp[u][i-j][0][0]*dp[v][j][0][0]%mod,v00%=mod;
					v01+=1ll*dp[u][i-j][0][1]*dp[v][j][1][0]%mod,v01%=mod;
					v01+=1ll*dp[u][i-j][0][0]*dp[v][j][1][0]%mod,v01%=mod;
					v01+=1ll*dp[u][i-j][0][1]*dp[v][j][0][0]%mod,v01%=mod;
				}
				dp[u][i][0][1]=v01;
				dp[u][i][0][0]=v00;
			}
		}//音野 
		else
		{
			for(i=min(size[u]+size[v],k);i>=0;i--)
			{
				LL v11=0,v00=0,v01=0,v10=0;
				for(j=min(size[v],i);j>=max(0,i-size[u]);j--)	
				{
					v00+=1ll*dp[u][i-j][0][0]*dp[v][j][0][1]%mod,v00%=mod;
					v10+=1ll*dp[u][i-j][1][0]*dp[v][j][0][0]%mod,v10%=mod;
					v10+=1ll*dp[u][i-j][1][0]*dp[v][j][0][1]%mod,v10%=mod;
				}
				dp[u][i][1][0]=v10;
				dp[u][i][0][0]=v00;
			}
		}//野 
		size[u]+=size[v];
	}
//	for(i=0;i<=k;i++)
//	dp[][][][]-=dp[][][][],dp[][][][]%=mod;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0,0);//野甜方 
	for(i=0;i<=k;i++)
	ans0[i]=dp[1][i][1][0]+dp[1][i][0][0];
	memset(dp,0,sizeof(dp));
	memset(size,0,sizeof(size));
	dfs(1,1,0);
	for(i=0;i<=k;i++)
	ans+=1ll*dp[1][i][0][1]*ans0[k-i]%mod,ans%=mod;
	cout<<(ans+mod)%mod;
	return 0;
}

