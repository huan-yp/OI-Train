#include<bits/stdc++.h>
#define int long long
#define low(x) ((x)&(-x))
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch==45)f=-1,ch=getchar();
	while((ch<='9'&&ch>='0'))x=x*10+ch-48,ch=getchar();
	x*=f;
}

void cmin(int &x,int y){x=min(x,y);}
void cmax(int &x,int y){x=max(x,y);}
const int N=3e5+10,mod=998244353;
int i,j,k,m,n,s,t,ans,x;
int a[N],son[N*64][2],sum[N*64],dp[N];
void Inc(int &x,int y)
{
	x+=y;if(x>=mod)x-=mod;
}
void push_up(int rt)
{
	if(rt==0)return ;
	sum[rt]=sum[son[rt][0]]+sum[son[rt][1]];
	if(sum[rt]>=mod)sum[rt]-=mod;
}
int quert(int u,int x,int c,int dep)
{
	if((u==0&&dep!=60))return sum[u]; 
	if(dep == -1) return sum[u];
	int x1=(1ll<<dep&x)?1:0,c1=(1ll<<dep&c)?1:0,ret=0;
	if(c1==0)
	ret=sum[son[u][x1^1]];
	Inc(ret,quert(son[u][x1^c1],x,c,dep-1));
	return ret;
}
void add(int u,int x,int c,int dep)
{
	if(dep == -1)
	{
		Inc(sum[u],c);
		return ;
	}
	if(1ll<<dep&x)
	{
		if(son[u][1]==0)son[u][1]=++t;
		add(son[u][1],x,c,dep-1);
	}
	else
	{
		if(son[u][0]==0)son[u][0]=++t;
		add(son[u][0],x,c,dep-1);
	}
	push_up(u);
}
signed main()
{
	read(n),read(x);int ans=0;
	for(i=1;i<=n;i++)
	read(a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		dp[i]=quert(0,a[i],x,60)+1;
		if(dp[i]>=mod)dp[i]-=mod;
		add(0,a[i],dp[i],60);
		Inc(ans,dp[i]);
	}
	cout<<ans<<endl; 
	return 0;
}


