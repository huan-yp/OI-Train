#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
using namespace std;
template<typename _type>
inline void read(_type &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
template<typename _type>
void cmin(_type &a,_type b){a=min(a,b);}
template<typename _type>
void cmax(_type &a,_type b){a=max(a,b);}
const int N=1e6+10,mod=998244353;
int i,j,k,n,s,t,m;
int dp[N][10];
signed main()
{
 	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for(i=1;i<=9;i++)dp[1][i]=1;
	for(i=1;i<n;i++)
	for(j=1;j<=9;j++)
	{
		dp[i+1][j]+=dp[i][j],dp[i+1][j]%=mod;
		if(j!=1)dp[i+1][j-1]+=dp[i][j],dp[i+1][j-1]%=mod;
		if(j!=9)dp[i+1][j+1]+=dp[i][j],dp[i+1][j+1]%=mod;
	}
	int ans=0;
	for(i=1;i<=9;i++)ans+=dp[n][i],ans%=mod;
	cout<<ans<<endl;
	return 0;
}

