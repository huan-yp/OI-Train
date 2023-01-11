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
/*



*/
const int N=1005;
int i,j,k,n,s,t,m,op;
char ch[N];
struct goodies{
	int p,j;
	friend bool operator <(goodies a,goodies b)
	{
		if(a.p!=b.p)
		return a.p>b.p;
		return a.j<b.j;
	}
}a[N],dp[N][N];
goodies max(goodies a,goodies b)
{
	if(a.j!=b.j)
	return a.j<b.j?b:a;
	return a.p<b.p?b:a;
}
void solve()
{
	//p:greedy
	read(n);
	scanf("%s",ch+1);
	if(ch[1]=='P')op=0;
	else op=1;
	
	for(i=1;i<=n;i++)
	read(a[i].p),read(a[i].j);
	
	sort(a+1,a+n+1);
	dp[0][0]=(goodies){0,0};
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0],dp[i][0].p+=a[i].p;
		for(j=1;j<=(i+op)/2;j++)
		{
			goodies c1=dp[i-1][j-1],c2=dp[i-1][j];
			c2.p+=a[i].p,c1.j+=a[i].j;
			dp[i][j]=max(c1,c2);
		}
	}
	printf("%d %d\n",dp[n][(n+op)/2].p,dp[n][(n+op)/2].j);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	dp[i][j]=dp[0][0];//多测多想清空的问题 
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	solve(); 
	return 0;
}

