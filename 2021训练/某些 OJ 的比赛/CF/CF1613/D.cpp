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
const int N=5e5+10,mod=998244353;
int i,j,k,n,s,t,m;
int a[N],dp[N][3],sum[N][3];
void Inc(int &x,const int y){x+=y;if(x>=mod)x-=mod;}
//dp[i][0/1/2] ÒÔ i ½áÎ²£¬mex a[i]+1/a[i]-1/a[i] + 1 ÓÐ a[i] + 2 
//i -> j
//0 -> a[i] + 1
//0 -> a[i]
//1 -> a[i]
//dp[i][0] += dp[j][0] (a[i]=a[j]||a[i]=a[j]+1)
//dp[i][1] += dp[j][0] (a[i] = a[j] + 2)
//dp[i][1] += dp[j][1] (a[i] = a[j])
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;read(tot);
	while(tot--)
	{
		read(n);int ans=0;
		
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++)
		{
			if(a[i]==0)Inc(dp[i][0],1);
			if(a[i]==1)Inc(dp[i][1],1);
			if(a[i])Inc(dp[i][0],sum[a[i]-1][0]);Inc(dp[i][0],sum[a[i]][0]);
			if(a[i]>1)Inc(dp[i][1],sum[a[i]-2][0]),Inc(dp[i][1],sum[a[i]-2][2]);Inc(dp[i][1],sum[a[i]][1]);
			
			Inc(dp[i][2],sum[a[i]+2][1]),Inc(dp[i][2],sum[a[i]][2]);
			Inc(sum[a[i]][0],dp[i][0]),Inc(sum[a[i]][1],dp[i][1]),Inc(sum[a[i]][2],dp[i][2]);
			Inc(ans,dp[i][1]),Inc(ans,dp[i][0]),Inc(ans,dp[i][2]);
		}
		cout<<ans<<endl;
		for(i=0;i<=n;i++)
		dp[i][0]=dp[i][1]=sum[i][0]=sum[i][1]=sum[i][2]=dp[i][2]=0;
	}
	return 0;
}

