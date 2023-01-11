#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=150005,M=305;
int i,j,k,n,s,t,m,d,ans,tail,head;
int dp[2][N],q[N];
struct point{
	int t,pos;
	friend bool operator <(point aa,point bb)
	{
		return aa.t<bb.t;	
	} 
	int calc(int x)
	{
		return -abs(x-pos);
	}
}a[M]; 
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	memset(dp,191,sizeof(dp));
	read(n),read(m),read(d);
	for(i=1;i<=m;i++)
	{
		int x;
		read(a[i].pos),read(x),read(a[i].t);
		ans+=x;
	}
	sort(a+1,a+m+1);
	for(i=1;i<=n;i++)
	dp[1][i]=-abs(i-a[1].pos);
	
	for(i=2;i<=m;i++)
	{
		head=tail=1;
		for(j=1;j<=n;j++)
		{
			while(tail!=head&&dp[(i-1)&1][j]>dp[(i-1)&1][q[tail-1]])
			tail--;
			q[tail++]=j;
			while(tail!=head&&q[head]+d*(a[i].t-a[i-1].t)<j)
			head++;
			dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][q[head]]+a[i].calc(j));
		}
		head=tail=1;
		for(j=n;j>=1;j--)
		{
			while(tail!=head&&dp[(i-1)&1][j]>dp[(i-1)&1][q[tail-1]])
			tail--;
			q[tail++]=j;
			while(tail!=head&&q[head]-d*(a[i].t-a[i-1].t)>j)
			head++;
			dp[i&1][j]=max(dp[i&1][j],dp[(i-1)&1][q[head]]+a[i].calc(j));
		}
		memset(dp[(i-1)&1],191,sizeof(dp[(i-1)&1]));
	}
	int maxn=-1e18;
	for(i=1;i<=n;i++)
	maxn=max(maxn,dp[m&1][i]);
	
	cout<<ans+maxn;
	return 0;
}
