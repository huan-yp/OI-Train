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
int dp[N][N*5];
short lst[N][N*5],opt[N]; 
struct fu{
	int low,len,t,rk,val;
}a[N];
char ch[N*5];
bool cmp(fu aa,fu bb)
{
	return aa.val>bb.val;
}
void printz(int x,int p)
{
	if(x>1)
	printz(x-1,lst[x][p]);
	if(dp[x][p]!=dp[x-1][lst[x][p]])
	opt[++all]=a[x].rk;
}
signed main()
{
//	freopen("data.in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
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
		a[i].low=max_need;
		if(top>=0)
		a[i].val+=1e5;
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
		}
		a[i].rk=i,a[i].len=m;
		a[i].t=a[i].val<20000?-top:top;
		a[i].val-=max_need;
	}
	sort(a+1,a+n+1,cmp);
	dp[n+1][0]=dp[0][0]=0;
	for(i=1;i<=n;i++)
	for(j=0;j<N*5;j++)
	{
		//下面会超边界
		if(j-a[i].t<N*5&&j-a[i].t>=a[i].low&&dp[i-1][j-a[i].t]+a[i].len>=dp[i-1][j])
		dp[i][j]=dp[i-1][j-a[i].t]+a[i].len,lst[i][j]=j-a[i].t;
		else
		dp[i][j]=dp[i-1][j],lst[i][j]=j;
	}
	printz(n,0);
	printf("%d %d\n",dp[n][0],all);
	for(int i=1;i<=all;++i)cout<<opt[i]<<" \n"[i==all];
	return 0;
}
