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
//2212
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
const int N=3005,mod=INF;
int i,j,k,n,s,t,m;
int dp[2][N<<1][2],a[N];
string operator /(const string &a,int b)
{
	
	int n=a.length(),ret=0;
	string ans="";
	if(a[0]>='4')ans+=char((a[0]-'0')/4+'0');
	ret=(a[0]-'0')%4;
	for(i=1;i<n;i++)
	{
		ret=ret*10+a[i]-'0';
		ans+=char((ret/4)+'0');
		ret%=4;
	}
	if(ans=="")ans="0";
	return ans;
}
int operator %(const string &a,int b)
{
	int ret=0,n=a.length();
	for(i=0;i<n;i++)
	ret=(ret*10+a[i]-'0')%b;
	return ret;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	string str;
	cin>>str;
	while(str!="0")
	{
		a[++n]=str%4;
		str=str/4;
	}
	for(i=1;i<=n/2;i++)
	swap(a[i],a[n-i+1]);
	dp[0][0][0]=1;
	int lst=0;
	for(i=0;i<=n;i++)
	{
	
		for(j=lst;j<=lst+4;j++)
		{
			if(a[i+1]==0)
			{
				dp[i+1&1][j][0]+=dp[i&1][j][0],dp[i+1&1][j][0]%=mod;
				dp[i+1&1][j+1][0]+=dp[i&1][j][1],dp[i+1&1][j+1][0]%=mod;
			}
			if(a[i+1]==1)
			{
				dp[i+1&1][j+1][0]+=dp[i&1][j][0],dp[i+1&1][j+1][0]%=mod;
				dp[i+1&1][j+2][0]+=dp[i&1][j][1],dp[i+1&1][j+2][0]%=mod;
				dp[i+1&1][j+2][1]+=dp[i&1][j][1],dp[i+1&1][j+2][1]%=mod;
			}
			if(a[i+1]==2)
			{
				dp[i+1&1][j+2][0]+=dp[i&1][j][0],dp[i+1&1][j+2][0]%=mod;
				dp[i+1&1][j+2][1]+=dp[i&1][j][0],dp[i+1&1][j+2][1]%=mod;
				dp[i+1&1][j+1][1]+=dp[i&1][j][1],dp[i+1&1][j+1][1]%=mod;
			}
			if(a[i+1]==3)
			{
				dp[i+1&1][j+1][1]+=dp[i&1][j][0],dp[i+1&1][j+1][1]%=mod;
				dp[i+1&1][j][1]+=dp[i&1][j][1],dp[i+1&1][j][1]%=mod;
			}
			dp[i&1][j][0]=dp[i&1][j][1]=0;
		}
		for(j=lst;j<=lst+7;j++)
		if(dp[(i+1)&1][j][0]||dp[(i+1)&1][j][1])
		{
			lst=j;
			break;
		}
	}
	for(i=0;i<=n*2;i++)
	if(dp[(n+1)&1][i][0])
	{
		printf("%d",dp[(n+1)&1][i][0]);
		return 0;
	}
}

