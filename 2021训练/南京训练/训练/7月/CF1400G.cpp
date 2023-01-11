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
void cmin(int &a,int b)
{
	a=min(a,b);
}
void cmax(int &a,int b)
{
	a=max(a,b);
}
/*



*/
const int N=1<<20,mod=998244353;
int i,j,k,n,s,t,m,ans;
int cnt[N][2],p[N],f[N]={1},inv[N]={1},haveRelation[N];
vector <int> op[N]; 
struct relation{
	int x,y;
}b[N];
struct people{
	int r,l;
}a[N];
int C(int n,int m)
{
	if(m>n)return 0;
	return 1ll*f[n]*inv[m]%mod*inv[n-m]%mod;
}
int quick(int a,int s)
{
	int ret=1;
	while(s)
	{
		if(s&1)
		ret=1ll*ret*a%mod;
		a=1ll*a*a%mod;
		s>>=1;
	}
	return ret;
}
void recalculate()
{
	memset(cnt,0,sizeof(cnt));
	for(int mask=0;mask<1<<m;mask++)
	{
		int pd=0,tot=0;
		for(int i=1;i<=m;i++)
		{
			if((mask&(1<<i-1))==0)continue;
			if(p[b[i].x]==0||p[b[i].y]==0)
			{
				pd=1;
				break;
			}
			if(p[b[i].x]==1)tot++,p[b[i].x]=2;
			if(p[b[i].y]==1)tot++,p[b[i].y]=2;
		}
		for(int i=1;i<=m;i++)
		{
			if((mask&(1<<i-1))==0)continue;
			if(p[b[i].x]==0||p[b[i].y]==0)
			{
				pd=1;
				break;
			}
			if(p[b[i].x]==2)p[b[i].x]=1;
			if(p[b[i].y]==2)p[b[i].y]=1;
		}
		if(pd)continue;
		cnt[tot][__builtin_popcount(mask)%2]++;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=2*n;i++)
	f[i]=1ll*f[i-1]*i%mod,inv[i]=quick(f[i],mod-2);
	
	for(i=1;i<=n;i++)
	{
		read(a[i].l),read(a[i].r);
		op[a[i].l].push_back(i);
		op[a[i].r+1].push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
		haveRelation[x]=haveRelation[y]=1;
		b[i].x=x,b[i].y=y;
	}
	int sum=0;
	recalculate();
	for(i=1;i<=n;i++)
	{
		int flag=0;
		for(int v:op[i])
		{
			if(haveRelation[v])
			flag=1;
			
			if(p[v])
			sum--,p[v]=0;
			else
			sum++,p[v]=1;
		}	
		if(flag)
		recalculate();
		
		for(j=0;j<=40;j++)
		{
			ans-=1ll*C(sum-j,i-j)*cnt[j][1]%mod,ans%=mod;
			ans+=1ll*C(sum-j,i-j)*cnt[j][0]%mod,ans%=mod;
		}
	}
	cout<<(ans+mod)%mod;
	return 0;
}

