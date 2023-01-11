#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch!=45&&(ch>'9'||ch<'0'))ch=getchar();
	if(ch==45){f=-1,ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}x*=f;
}
void cmin(LL &a,LL b){a=min(a,b);}
void cmax(LL &a,LL b){a=max(a,b);}
const int N=2e7+10;
int i,j,k,n,s,t,m,maxn;
int cnt[N<<1],pd[N],zs[N];
long long dp[N],ans;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n);
	for(i=1;i<=n;i++)
	{
		int x;read(x);cnt[x]++;
		maxn=max(maxn,x);
	}
	
	
	for(i=2;i<=maxn;i++)
	{
		if(!pd[i])zs[++s]=i;
		for(j=1;zs[j]*i<=maxn;j++)
		{
			pd[i*zs[j]]=1;
			if(i%zs[j]==0)break;
		}
	}
	for(i=1;i<=s;i++)
	for(j=maxn/zs[i];j>=1;j--)
	cnt[j]+=cnt[j*zs[i]];
	
	cmax(ans,n);
	for(i=2;i<=maxn;i++)
	cmax(dp[i],dp[1]+(n-cnt[i]));
	
	for(i=2;i<=maxn;i++)
	{
		cmax(ans,dp[i]+1ll*i*cnt[i]);
		for(j=1;zs[j]*i<=maxn;j++)
		{
			cmax(dp[i*zs[j]],dp[i]+1ll*i*(cnt[i]-cnt[i*zs[j]]));
			pd[i*zs[j]]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

