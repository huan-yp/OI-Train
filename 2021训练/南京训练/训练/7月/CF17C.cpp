#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define next nxt
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
/*
conserdier string B that expand by A 
We can simplify B by turn the continuous character into one
then B' is a substring of A with no same continuous character
*/
const int mod=51123987;
const int N=155,M=55;
int dp[N][M][M][M],next[N][3];
int i,j,k,n,s,t,m,ans;
//dp[i][a][b]=;
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	for(i=n;i>=0;i--)
	{
		next[i][0]=next[i+1][0];
		next[i][1]=next[i+1][1];
		next[i][2]=next[i+1][2];
		if(i)
		next[i][ch[i]-'a']=i;
	}
	dp[0][0][0][0]=1;
	for(i=0;i<=n;i++)
	for(int ca=0;ca<=n/3+1;ca++)
	for(int cb=0;cb<=n/3+1;cb++)
	for(int cc=0;cc<=n/3+1;cc++)
	{
		if(dp[i][ca][cb][cc]==0)continue;
		if(ca+cb+cc==n&&abs(ca-cb)<=1&&abs(cb-cc)<=1&&abs(ca-cc)<=1)
		ans+=dp[i][ca][cb][cc],ans%=mod;
		if(next[i][0])
		dp[next[i][0]][ca+1][cb][cc]+=dp[i][ca][cb][cc],dp[next[i][0]][ca+1][cb][cc]%=mod;
		if(next[i][1])
		dp[next[i][1]][ca][cb+1][cc]+=dp[i][ca][cb][cc],dp[next[i][1]][ca][cb+1][cc]%=mod;
		if(next[i][2])
		dp[next[i][2]][ca][cb][cc+1]+=dp[i][ca][cb][cc],dp[next[i][2]][ca][cb][cc+1]%=mod;
	} 
	cout<<ans<<endl;
	return 0;
}

