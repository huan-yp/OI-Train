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
const int N=5005;
int i,j,k,n,s,t,m;
int dp[N],pd[N];
int solve(int x)
{
	if(dp[x]!=-1)return dp[x];
	for(int i=1;i<x;i++)
	dp[x]=max(dp[x],min(solve(i)+solve(x-i-1),solve(i-1)+solve(x-i)));
	return dp[x];
}
void init()
{
	memset(dp,-1,sizeof(dp));
	dp[1]=1;dp[0]=0;
	for(i=2;i<N;i++)
	dp[i]=solve(i);
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();
	read(t);
	while(t--)
	{
		int ans=0,lst=0;
		memset(pd,0,sizeof(pd));
		read(n),read(m);
		for(i=1;i<=m;i++)
		{
			int x,y;
			read(x),read(y);if(x>y)swap(x,y);
			if(x+1!=y)continue;
			pd[x]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(pd[i]==0)
			{
				if(pd[i-1])
				lst++,ans+=dp[lst];
				else
				ans++;
				lst=0;
			}
			else
			lst++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}//ÒÑ¼ì²é,Î´¶ÔÅÄ 

