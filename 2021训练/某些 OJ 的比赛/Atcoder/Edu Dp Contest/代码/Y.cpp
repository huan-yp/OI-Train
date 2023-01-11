#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define LL long long
#define pii pair<int,int>
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
struct edge{
	int v,val;
};
struct point{
	int x,y;
};
const int N=200005,M=3005,mod=1e9+7;
int i,j,k,n,s,t,m,ans;
int inv[N]={1},f[N]={1},dp[M][2],cnt[M];
point a[N];
vector<edge> e[N];
queue<int> q;
int C(int n,int m)
{
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int calc(point a,point b)
{
	return C(b.x+b.y-a.x-a.y,b.x-a.x);
}
int quick(int aa,int ss)
{
	int ret=1;
	while(ss)
	{
		if(ss&1)
		ret=1ll*ret*aa%mod;
		aa=1ll*aa*aa%mod;
		ss>>=1;
	}
	return ret;
}
void Topsort()
{
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(j=0;j<=1;j++)
		{	
			if(dp[u][j]==0)continue;
			for(edge tmp:e[u])
			{
				int v=tmp.v,val=tmp.val;
				dp[v][j^1]+=1ll*val*dp[u][j]%mod;
				dp[v][j^1]%=mod;
			}
		}
		for(edge tmp:e[u])
		{
			int v=tmp.v,val=tmp.val;
			cnt[v]--;
			if(cnt[v]==0)
			q.push(v);
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	for(i=1;i<N;i++)
	f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	
	read(n),read(m),read(s);
	a[0]=(point){1,1};
	for(i=1;i<=s;i++)
	read(a[i].x),read(a[i].y);
	
	a[++s]=(point){n,m};
	for(i=0;i<=s;i++)
	for(j=0;j<=s;j++)
	{
		if(i==j)continue;
		if(a[j].x<a[i].x||a[j].y<a[i].y)continue;
		e[i].push_back((edge){j,calc(a[i],a[j])});
		cnt[j]++;
	}
	dp[0][0]=1;
	q.push(0);
	Topsort();
	for(i=0;i<=1;i++)
	ans+=dp[s][i]*(i%2?1:-1),ans%=mod;
	cout<<(ans+mod)%mod;
	return 0;
}
