#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
int i,j,k,n,s,t,m;
const int N=105;
int dp[28][30][30][11],g[N];
void solve(int x)
{
	memset(dp,0,sizeof(dp));
	int cnt=0,ans=25;
	while(x)
	{
		g[++cnt]=x%10;
		x/=10;
	}
	for(i=0;i<=10;i++)
	dp[0][i][i][0]=1;
	
	for(i=0;i<cnt;i++)
	{
		for(j=1;j<=10;j++)
		{
			for(int lst=0;lst<=j;lst++)
			{
				for(int from=0;from<=3;from++)
				{
					if(dp[i][j][lst][from]==0)continue;
					for(int s1=0;s1<=lst;s1++)
					for(int s2=0;s2+s1<=lst;s2++)
					for(int s0=0;s0+s1+s2<=lst;s0++)
					{
						int s3=lst-s1-s2-s0;
						int val=s1*1+s2*2+s3*3+from;
						if(val%10==g[i+1])
						dp[i+1][j][lst-s0][val/10]=1;
					}
				}	
			}	
		}		
	}
	for(i=1;i<=10;i++)
	{
		int pd=0;
		for(j=0;j<=i;j++)
		{
			if(dp[cnt][i][j][0])pd=1;
		}
		if(pd)break;
	}
	cout<<i<<endl;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(t);
	while(t--)
	{
		read(n);
		solve(n);
	}
	return 0;
}

