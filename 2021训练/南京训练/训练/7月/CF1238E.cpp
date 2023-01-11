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
int i,j,k,n,s,t,m;
const int N=1e5+10,M=25;
int cnt[M][M];
char ch[N];
int dp[1<<20];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	//This problem is similar to message sending¡£ 
	read(n),read(m);
	scanf("%s",ch+1);
	for(i=1;i<n;i++)
	cnt[ch[i]-'a'][ch[i+1]-'a']++;
	for(i=0+0;i<m;i++)
	for(j=i+1;j<m;j++)
	cnt[i][j]=cnt[j][i]=cnt[i][j]+cnt[j][i];
	
	memset(dp,1,sizeof(dp));
	dp[0]=0;
	for(int mask=0;mask<1<<m;mask++)
	{
		for(i=0;i<m;i++)
		{
			if(mask&(1<<i))continue;
			int sum=0,pos=__builtin_popcount(mask)+1;
			for(j=0;j<m;j++)
			{
				if(i==j)continue;
				if(mask&(1<<j))
				sum+=pos*cnt[i][j];
				else
				sum-=pos*cnt[i][j];
			}	
			dp[mask^(1<<i)]=min(dp[mask^(1<<i)],dp[mask]+sum);
		}
	}
	cout<<dp[(1<<m)-1];
	return 0;
}


