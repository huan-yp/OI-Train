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
const int N=1e3+10;
const int mod=1e9+7;
int i,j,t,m;
map<int,int>dp[N];
int gcd(int x,int y)
{
	return y?gcd(y,x%y):x;
}
int inv(int aa,int ss=mod-2)
{
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=1ll*ret*aa%mod;
		ss>>=1;
		aa=1ll*aa*aa%mod;
	}
	return ret;
}
void solve(int n,int s)
{
	if(dp[n][s])
	return;
	if(n==0)
	{
		dp[0][s]=1;
		return;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		solve(n-i,gcd(i,s));
		sum+=1ll*(i%2?1:-1)*dp[n-i][gcd(i,s)]*m/s*gcd(i,s)%mod;
		sum%=mod;
	}
	dp[n][s]=1ll*sum*inv(n)%mod;
}
class TheCowDivOne{
	public:
	int find(int N, int K)
	{
		m=N;
		solve(K,N);
		return (dp[K][N]+mod)%mod;
	}	
};
//signed main()
//{
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	//freopen(".ans","w",sdtout);
//	TheCowDivOne solve;
//	cout<<solve.find(
//1000000000,
//1000);
//	return 0;
//}


