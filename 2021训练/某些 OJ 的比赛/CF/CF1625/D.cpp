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
void cmin(int &a,int b){a=min(a,b);}
void cmax(int &a,int b){a=max(a,b);}
const int N=300005<<5;
int i,j,k,n,s,t=1,m;
int a[N/32],son[N][2],dp[N/32],rk[N],from[N/32],ans[N/32],tmp[N/32];
struct point{
	int val,rk;
	friend bool operator <(point a,point b)
	{
		return a.val<b.val;
	}
}p[N];
void add(int u,int x,int dep,int val)
{
	if(dp[val]>dp[rk[u]])rk[u]=val;
	if(dep==-1)return ;
	int op=(1<<dep&x)?1:0;
	if(son[u][op]==0)son[u][op]=++t;
	add(son[u][op],x,dep-1,val);
}
int quert(int u,int x,int dep)
{
	if(u==0)return 0;
	if(dep==-1)return rk[u];
	int op=(1<<dep&(x^k))?1:0;
	if(1<<dep&k)
	return quert(son[u][op],x,dep-1);
	else
	return dp[rk[son[u][op^1]]]>(s=quert(son[u][op],x,dep-1))?rk[son[u][op^1]]:s;
}
void print(int x)
{
	if(x==0)return ;
	print(from[x]);
	printf("%d ",p[x].rk);	
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(k);
	for(i=1;i<=n;i++)read(a[i]),p[i].val=a[i],p[i].rk=i;
	sort(p+1,p+n+1);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		from[i]=quert(1,a[i],30);
		dp[i]=dp[from[i]]+1;
		add(1,a[i],30,i);
	}
	if(dp[rk[1]]==1)
	{
		puts("-1");
		return 0;
	}
	cout<<dp[rk[1]]<<endl;
	print(rk[1]);
	return 0;
}

