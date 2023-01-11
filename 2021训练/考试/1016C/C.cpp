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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=1e5+10;
int i,j,k,n,s,t,m,e;
int dp[N],pos[N];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	//dp[i]=+dp[j]+max(pos[i]-pos[i+1],T)
	read(n),read(e),read(t);
	for(i=1;i<=n;i++)read(pos[i]);
	
	int minu=1e18,now=0;
	for(i=1;i<=n;i++)
	{
		while(2*(pos[i]-pos[now+1])>=t)
		cmin(minu,dp[now]-2*pos[now+1]),now++;
		dp[i]=dp[now]+t;
		cmin(dp[i],minu+2*pos[i]);
	}
	cout<<dp[n]+e;
	return 0;
}

