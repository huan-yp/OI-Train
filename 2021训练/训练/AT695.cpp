#include<bits/stdc++.h>
#define y1 y3647
#define earse erase
#define INF 1000000000
#define int long long
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
const int N=105,mod=1e9+7;
int i,j,k,n,s,t,m;
int f[N][1<<12],col[N],rk[N],lst[N],pd[N],p[1<<12][1<<6],fa[N];
void Inc(int &x,const int &y){x+=y;if(x>=mod)x-=mod;}
void check()
{
	for(int i=1;i<=n;i++)
	{
		if(rk[i]&&rk[i-1]&&rk[i]!=rk[i-1])
		printf("Boom!");
	}
}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u>v)swap(u,v);
	fa[v]=u;
}
void getrk(int lastmask,int mask)
{
	int cnt=1,now=3,flag=0;
	for(int i=1;i<=10;i++)fa[i]=i;
	for(int i=1;i<=n;i++)lst[i]=(lastmask>>((i-1)*2))&3,pd[i]=0,rk[i]=0;pd[1]=1;
	for(int i=1;i<=n;i++)if((mask&(1<<i-1))&&lst[i])rk[i]=lst[i];
	for(int i=1;i<=n;i++)if((mask&(1<<i-1))&&rk[i]==0)rk[i]=++now;
	for(int i=1;i<=n;i++)if(rk[i]==1)flag=1;
	for(int i=1;i<=n;i++)if((mask&(1<<i-1))&&(mask&(1<<i)))merge(rk[i],rk[i+1]);
	for(int i=1;i<=n;i++)if(pd[find(rk[i])]==0&&rk[i]!=0)pd[find(rk[i])]=++cnt;
	for(int i=1;i<=n;i++)rk[i]=pd[find(rk[i])];
	pd[1]=flag;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen("1.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(int mask=0;mask<1<<n;mask++)
	{
		if((mask&1)==0)continue;
		getrk(1,mask);
		int nowmask=0;
		for(i=1;i<=n;i++)
		nowmask|=(1<<(i-1)*2)*rk[i];
		f[1][nowmask]=1;t++;
	}
	for(i=1;i<=m;i++)
	{
		for(int mask=0;mask<1<<n*2;mask++)
		{
			if(f[i][mask]==0)continue;
			for(int now=0;now<1<<n;now++)
			{
				getrk(mask,now);
				if(pd[1]==0)continue;
				int nowmask=0;
				for(j=1;j<=n;j++)
				nowmask|=(1<<(j-1)*2)*rk[j];
				Inc(f[i+1][nowmask],f[i][mask]);
			}
		}
	}
	int ans=0;
	for(int mask=1;mask<1<<n*2;mask++)
	if(((mask>>(n*2-2))&3)==1)
	Inc(ans,f[m][mask]);
	
	cout<<ans<<endl;
	return 0;
}

