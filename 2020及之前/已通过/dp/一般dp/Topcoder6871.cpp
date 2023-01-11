#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
#define LL long long
using namespace std;
inline int read(int &x)
{
	x=0;int f=1;
	char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
class NiceOrUgly{
	public :
	string describe(string s)
	{
		string ans;
		int len=s.length();	
		int p1=0,p2=1;
		int dp[100][10];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<len;i++)
		{
			if(s[i]=='?')
			{
				for(int j=2;j<=5&&i;j++)
				dp[i][j]|=dp[i-1][j-1];
				dp[i][5]|=dp[i-1][5];
				for(int j=7;j<=8&&i;j++)
				dp[i][j]|=dp[i-1][j-1];
				dp[i][8]|=dp[i-1][8];
				if(dp[i-1][1]||dp[i-1][2]||dp[i-1][3]||dp[i-1][4]||dp[i-1][5]||i==0)
				dp[i][6]=1;
				if(dp[i-1][6]||dp[i-1][7]||dp[i-1][8]||i==0)
				dp[i][1]=1;
			}
			else
			if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
			{
				for(int j=7;j<=8&&i;j++)
				dp[i][j]|=dp[i-1][j-1];
				dp[i][8]|=dp[i-1][8];
				if(dp[i-1][1]||dp[i-1][2]||dp[i-1][3]||dp[i-1][4]||dp[i-1][5]||i==0)
				dp[i][6]=1;
			}
			else
			{
				for(int j=2;j<=5&&i;j++)
				dp[i][j]|=dp[i-1][j-1];
				dp[i][5]|=dp[i-1][5];
				if(dp[i-1][6]||dp[i-1][7]||dp[i-1][8]||i==0)
				dp[i][1]=1;
			}
			if(dp[i][5]||dp[i][8])p1=1;
			if(!(dp[i][1]||dp[i][2]||dp[i][3]||dp[i][4]||dp[i][6]||dp[i][7]))p2=0;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<len;i++)
		{
			if(s[i]=='?')
			{
				for(int j=2;j<=5&&i;j++)
				dp[i][j]|=dp[i-1][j-1];
				dp[i][5]|=dp[i-1][5];
				for(int j=7;j<=8&&i;j++)
				dp[i][j]|=dp[i-1][j-1];
				dp[i][8]|=dp[i-1][8];
				if(dp[i-1][1]||dp[i-1][2]||dp[i-1][3]||dp[i-1][4]||i==0)
				dp[i][6]=1;
				if(dp[i-1][6]||dp[i-1][7]||i==0)
				dp[i][1]=1;
			}
			else
			if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
			{
				for(int j=7;j<=8&&i;j++)
				dp[i][j]|=dp[i-1][j-1];
				dp[i][8]|=dp[i-1][8];
				if(dp[i-1][1]||dp[i-1][2]||dp[i-1][3]||dp[i-1][4]||i==0)
				dp[i][6]=1;
			}
			else
			{
				for(int j=2;j<=5&&i;j++)
				dp[i][j]|=dp[i-1][j-1];
				dp[i][5]|=dp[i-1][5];
				if(dp[i-1][6]||dp[i-1][7]||i==0)
				dp[i][1]=1;
			}
			if(!(dp[i][1]||dp[i][2]||dp[i][3]||dp[i][4]||dp[i][6]||dp[i][7]))p2=0;
		}	
		if(p1&&p2)
		ans="42";
		else
		if(p1)
		ans="UGLY";
		else
		ans="NICE";
		return ans;
	}
};


