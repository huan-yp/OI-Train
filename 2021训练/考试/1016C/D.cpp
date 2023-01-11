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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=55,M=1<<18,mod=1e9+7;
int i,j,k,n,s,t,m,a,b,c,target,lim,ans;
int p[N]={1},dp[N][M];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(a),read(b),read(c);
	int all=a+b+c;dp[0][0]=1;lim=(1<<all)-1;
	target=(1<<c-1)|(1<<c+b-1)|(1<<a+b+c-1);
	for(i=1;i<=n;i++)p[i]=p[i-1]*10ll%mod;
	
	for(i=0;i<=n;i++)
	{
		for(int mask=0;mask<1<<all;mask++)
		{
			if((mask&target)==target)
			{
				ans+=1ll*p[n-i]*dp[i][mask]%mod,ans%=mod;
				continue;
			}
			for(k=1;k<=10;k++)
			{
				int to=((mask<<1|1)<<k-1)&lim;
				dp[i+1][to]+=dp[i][mask];
				dp[i+1][to]%=mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

