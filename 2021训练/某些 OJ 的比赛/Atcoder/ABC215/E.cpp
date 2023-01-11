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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1<<10,mod=998244353;
int i,j,k,n,s,t,m;
char ch[N];
int dp[N][N][10],a[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	cin>>(ch+1);
	for(i=1;i<=n;i++)a[i]=ch[i]-'A';
	
	for(i=1;i<=n;i++)
	dp[i][1<<a[i]][a[i]]=1;
	for(i=1;i<n;i++)
	{
		for(int mask=1;mask<N;mask++)
		{
			
			for(k=0;k<10;k++)
			{
				if(dp[i][mask][k]==0)continue;
				dp[i+1][mask][k]+=dp[i][mask][k];
				dp[i+1][mask][k]%=mod;
				//not chose
				if(a[i+1]==k)
				{
					dp[i+1][mask][k]+=dp[i][mask][k];
					dp[i+1][mask][k]%=mod;
				}//chose the same
				if(((1<<a[i+1])&mask)==0)
				{
					dp[i+1][mask|(1<<a[i+1])][a[i+1]]+=dp[i][mask][k];
					dp[i+1][mask|(1<<a[i+1])][a[i+1]]%=mod;
				}//chose different
			}
		}
	}
	int ans=0;
	for(i=1;i<N;i++)
	for(k=0;k<10;k++)
	ans+=dp[n][i][k],ans%=mod;
	
	printf("%d\n",ans);
	return 0;
}

