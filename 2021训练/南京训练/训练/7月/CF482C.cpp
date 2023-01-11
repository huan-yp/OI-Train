#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define earse erase
#define INF 1000000000
#define LL long long
#define low(x) (x)&(-x)
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
const int N=20,M=55;
int i,j,k,n,s,t,m;
int cnt[1<<N];
LL p[1<<N];
char ch[M][N+10];
double dp[1<<N];
double ans;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(m);
	for(i=1;i<=m;i++)
	scanf("%s",ch[i]+1);
	
	n=strlen(ch[1]+1);
	
	for(i=1;i<=m;i++)
	for(j=i+1;j<=m;j++)
	{
		int mask=0;
		for(k=1;k<=n;k++)
		if(ch[i][k]==ch[j][k])
		mask|=1<<k-1;
		
		p[mask]|=1ll<<j-1,p[mask]|=1ll<<i-1;
	}
	for(i=1;i<1<<n;i++)
	cnt[i]=__builtin_popcount(i);
	
	p[(1<<n)-2]|=p[(1<<n)-1];
	for(int mask=(1<<n)-2;mask>=0;mask--)
	{
		for(i=1;i<=n;i++)
		if(((1<<i-1)&mask)==0)
		{
			p[mask]|=p[mask^(1<<i-1)];
			dp[mask]+=1.0/(n-cnt[mask])*dp[mask^(1<<i-1)];
		}
		dp[mask]+=1.0*__builtin_popcountll(p[mask])/m;
	}
	printf("%0.9lf",dp[0]);
	return 0;
}


