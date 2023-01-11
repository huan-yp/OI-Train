#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-')ch=getchar(),f=-1;
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=f;
}
void cmax(int &x,int y){x=max(x,y);}
void cmin(int &x,int y){x=min(x,y);}
const int BASE = 1e7,T=200;
const int p[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
struct BIGINT{
	int a[T+5],ws;
	BIGINT()
	{
		ws=1;
	}
	void clear()
	{
		memset(a,0,sizeof(a));
	}
	friend BIGINT operator <<(const BIGINT &a,int b)
	{

		BIGINT ret;ret.clear();
		int real=b/7;b%=7;ret.ws=a.ws+real+1;
		for(int i=ret.ws;i-real>=0;i--)
		ret.a[i]=a.a[i-real];
		for(int i=ret.ws;i>=1;i--)
		ret.a[i]=1ll*p[b]*ret.a[i]%BASE,ret.a[i]+=1ll*ret.a[i-1]*p[b]/BASE;
		ret.a[0]=1ll*p[b]*ret.a[0]%BASE;
		if(ret.a[ret.ws]==0)ret.ws--;
		return ret;
	}
	friend BIGINT operator +(const BIGINT &a,const BIGINT &b)
	{
		BIGINT ret;ret.clear();ret.ws=max(a.ws,b.ws)+1;
		for(int i=0;i<=ret.ws;i++)
		ret.a[i]+=a.a[i]+b.a[i],ret.a[i+1]+=(ret.a[i]>BASE),ret.a[i]-=BASE*(ret.a[i]>BASE);
		if(ret.a[ret.ws]==0)ret.ws--;
		return ret;
	}
	friend BIGINT operator +(const BIGINT &a,const int &b)
	{
		BIGINT ret;ret.clear();ret.ws=a.ws+1;
		for(int i=0;i<=ret.ws;i++)
		ret.a[i]=a.a[i];
		ret.a[0]+=b;
		for(int i=0;i<=ret.ws;i++)
		ret.a[i+1]+=ret.a[i]/BASE,ret.a[i]%=BASE;
		if(ret.a[ret.ws]==0)ret.ws--;
		return ret;
	}
	friend BIGINT operator *(const BIGINT &a,const int b)
	{
		if(b==1)return a;
		BIGINT ret;ret.clear();ret.ws=a.ws+1;
		for(int i=0;i<=ret.ws;i++)
		{
		//	int tmp=(a.a[i]*b+ret.a[i])/BASE;
			ret.a[i]+=a.a[i]*b,ret.a[i+1]+=ret.a[i]/BASE,ret.a[i]%=BASE;
		}
		if(ret.a[ret.ws]==0)ret.ws--;
		return ret;
	}
	friend void operator +=(BIGINT &a,const BIGINT &b)
	{
		a.ws=max(a.ws,b.ws)+1;
		for(int i=0;i<=a.ws;i++)
		a.a[i]+=b.a[i],a.a[i+1]+=a.a[i]>BASE,a.a[i]-=(a.a[i]>BASE)*BASE;
		if(a.a[a.ws]==0)a.ws--;
	}
	void print()
	{
		int flag=0;
		for(int i=T;i>=0;i--)
		{
			if(flag||a[i])
			{
				for(int j=6;j>=1;j--)
				if(a[i]/p[j]==0&&flag)printf("0");
				printf("%d",a[i]);	
			}
			if(a[i])flag=1;
		}
		if(flag==0)
		printf("0");
	}
};
struct constrain{
	int x,y;
};
struct edge{
	int v,cnt,sum;
};
int i,j,k,m,n,s,t;
int forbid[1<<9];
edge mp[1<<9][1<<9];
BIGINT f[2][1<<9],g[2][1<<9];
constrain a[105];
vector<edge> e[1<<9];
int main()
{

	read(n),read(m),read(k);
	for(i=1;i<=m;i++)
	read(a[i].x),read(a[i].y);
	for(int mask=0;mask<1<<k;mask++)
	{
		for(i=1;i<=k;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(a[j].y==i&&((1<<a[j].x-1)&mask))
				forbid[mask]|=1<<i-1;
			}
		}
	}
	for(int mask=0;mask<1<<k;mask++)
	{
		for(j=1;j<=k;j++)
		{
			if(forbid[mask]&(1<<j-1))continue;
			mp[mask][mask|(1<<j-1)].cnt++;
			mp[mask][mask|(1<<j-1)].sum+=j;
		}
	}
	for(i=0;i<1<<k;i++)
	for(j=0;j<1<<k;j++)
	{
		if(mp[i][j].cnt)
		{
			mp[i][j].v=j;
			e[i].push_back(mp[i][j]);
		}
	}
	f[(n+1)&1][0]=f[(n+1)&1][0]+1;
	for(i=n+1;i>1;i--)
	{
		for(int mask=0;mask<1<<k;mask++)
		{
			for(auto tmp:e[mask])
			{
				int to=tmp.v,cnt=tmp.cnt,sum=tmp.sum;
				f[(i-1)&1][to]+=f[i&1][mask]*cnt;
				g[(i-1)&1][to]+=(g[i&1][mask]*cnt)+((f[i&1][mask]*sum)<<(i-2));
			}
			f[i&1][mask].clear();
			g[i&1][mask].clear();
		}
	}
	BIGINT cnt,ans;cnt.clear(),ans.clear();
	for(i=0;i<1<<k;i++)
	cnt=cnt+f[1][i],ans=ans+g[1][i];
	cnt.print();printf("\n");
	ans.print();printf("\n");
	return 0;
}

