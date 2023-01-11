#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
const int N=5e3+10;
int i,j,k,n,s,t,m,ans;
int a[N],dp[N],vis[N],lst[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	read(a[i]);
	
	for(int round=1;round<=4;round++)
	{
		int maxn=0;
		memset(dp,0,sizeof(dp));
		memset(lst,0,sizeof(lst));
		for(i=1;i<=n;i++)
		{
			if(vis[i])continue;
			dp[i]=1;
			for(j=1;j<i;j++)
			if((abs(a[i]-a[j])==1||a[i]%7==a[j]%7)&&dp[j]+1>dp[i])
			dp[i]=dp[j]+1,lst[i]=j;
			maxn=max(maxn,dp[i]);
		}
		for(i=1;i<=n;i++)
		if(maxn==dp[i])
		break;
		int now=i;
		while(now)
		{
			vis[now]=1;
			now=lst[now];
		}
		ans+=maxn;
	}
	cout<<ans;
	return 0;
}
