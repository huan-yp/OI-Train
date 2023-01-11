#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define next nxt
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
const int N=2e5+10,mod=1e9+7;
int i,j,k,n,s,t,m;
int next[N][26],dp[N];
char ch[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	scanf("%s",ch+1);
	n=strlen(ch+1);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	
	for(i=0;i<26;i++)
	next[n][i]=next[n-1][i]=n+1;
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<26;j++)
		next[i][j]=next[i+1][j];
		
		next[i][ch[i+2]-'a']=i+2;
	}
	next[0][ch[1]-'a']=1;
	dp[0]=1;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<26;j++)
		dp[next[i][j]]+=dp[i],dp[next[i][j]]%=mod;
	}
	int ans=0;
	for(i=1;i<=n;i++)
	ans+=dp[i],ans%=mod;
	cout<<ans<<endl;
	return 0;
}

