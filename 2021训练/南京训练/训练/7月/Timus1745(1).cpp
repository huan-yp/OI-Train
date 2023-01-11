#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m,ans,all,mid,pos;
const int N=1e3+10;
int dp[N][N*5],lst[N][N*5],opt[N]; 
struct fu{
	int low,len,t,rk,val;
}a[N];
char ch[N*10];
bool cmp(fu aa,fu bb)
{
	return aa.val>bb.val;
}
void printz(int x,int p)
{
	if(x>1)
	printz(x-1,lst[x][p]);
	if(x>=1&&dp[x][p]!=dp[x-1][lst[x][p]])
	opt[++all]=a[x].rk;
}
void printr(int x,int p)
{
	if(x<=n&&dp[x][p]!=dp[x+1][lst[x][p]])
	opt[++all]=a[x].rk;
	if(x<n)
	printr(x+1,lst[x][p]);
}
signed main()
{
	read(n);
	for(i=0;i<=n+1;i++)
	for(j=0;j<5*N;j++)
	dp[i][j]=-1e9;
	for(i=1;i<=n;i++)
	{
		int top=0,max_need=0;
		scanf("%s",ch+1);
		m=strlen(ch+1);
		for(j=1;j<=m;j++)
		{
			if(ch[j]=='(')
			top++;
			else
			top--;
			max_need=max(max_need,-top);
		}
		if(top>=0)
		a[i].val+=1e5,a[i].low=max_need;
		else
		{
			top=0,max_need=0;
			for(j=m;j>=1;j--)
			{
				if(ch[j]==')')
				top++;
				else
				top--;
				max_need=min(max_need,top);
			}
			a[i].low=-max_need;
		}
		a[i].rk=i,a[i].len=m;
		a[i].t=top;
		a[i].val-=max_need;
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		if(a[i].val<=10000)
		break;
	}
	dp[n+1][0]=dp[0][0]=0;
	mid=i-1;
	for(i=1;i<=mid;i++)
	for(j=0;j<N*5;j++)
	{
		if(j-a[i].t>=a[i].low&&dp[i-1][j-a[i].t]+a[i].len>=dp[i-1][j])
		dp[i][j]=dp[i-1][j-a[i].t]+a[i].len,lst[i][j]=j-a[i].t;
		else
		dp[i][j]=dp[i-1][j],lst[i][j]=j;
	}
	for(i=n;i>mid;i--)
	for(j=0;j<N*5;j++)
	{
		if(j-a[i].t>=a[i].low&&dp[i+1][j-a[i].t]+a[i].len>=dp[i+1][j])
		dp[i][j]=dp[i+1][j-a[i].t]+a[i].len,lst[i][j]=j-a[i].t;
		else
		dp[i][j]=dp[i+1][j],lst[i][j]=j;
	}
	for(i=0;i<N*5;i++)
	if(dp[mid][i]+dp[mid+1][i]>ans)
	ans=dp[mid][i]+dp[mid+1][i],pos=i;
	printz(mid,  pos);
	printr(mid+1,pos);
	printf("%d %d\n",ans,all);
	for(int i=1;i<=all;++i)cout<<opt[i]<<" \n"[i==all];
	return 0;
}
