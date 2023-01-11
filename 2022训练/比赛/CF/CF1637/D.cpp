#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
#define pii pair<int,int>
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
const int N=105;
int i,j,k,n,s,t,m;
int dp[N][N*N],a[N],b[N];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(t);
	while(t--)
	{
		memset(dp,1,sizeof(dp));
		read(n);int ans=0,sum=0;
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++)read(b[i]);
		dp[n+1][0]=0;
		for(i=n+1;i>1;i--)
		{
			ans+=a[i-1]*a[i-1]*(n-1)+b[i-1]*b[i-1]*(n-1);
			for(j=0;j<=sum;j++)
			{
				cmin(dp[i-1][j+a[i-1]],dp[i][j]+j*a[i-1]+(sum-j)*b[i-1]);
				cmin(dp[i-1][j+b[i-1]],dp[i][j]+(sum-j)*a[i-1]+j*b[i-1]);
			}
			sum+=a[i-1]+b[i-1];
		}
		int tmp=1ll*INF*INF;
		for(i=0;i<=n*100;i++)cmin(tmp,dp[1][i]);
		
		printf("%lld\n",ans+2*tmp);
	}

	return 0;
}

