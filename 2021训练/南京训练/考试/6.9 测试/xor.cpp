#include<bits/stdc++.h>
#define y1 y3647
#define next nxt
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
int i,j,k,n,s,t,m;
const int N=1e5+10,mod=998244353;
int val[N],inv[32]={1},po[32]={1};
int quick(int aa,int ss=mod-2,int ret=1)
{
	while(ss)
	{
		if(ss&1)
		ret=1ll*ret*aa%mod;
		aa=1ll*aa*aa%mod;
		ss>>=1;
	}
	return ret;
}
struct node{
	int dp[32][2],val,x[32],p[32],cnt[32];
	friend node operator +(node aa,node bb)
	{
		node ret;
		ret.val=aa.val^bb.val;
		for(int i=29;i>=0;i--)
		{
			ret.p[i]=aa.p[i]+bb.p[i];
			ret.x[i]=aa.x[i]^bb.x[i];
			ret.cnt[i]=1ll*aa.cnt[i]*bb.cnt[i]%mod;
			ret.dp[i][0]=(1ll*aa.dp[i][0]*bb.dp[i][0]+1ll*aa.dp[i][1]*bb.dp[i][1])%mod;
			ret.dp[i][1]=(1ll*aa.dp[i][0]*bb.dp[i][1]+1ll*aa.dp[i][1]*bb.dp[i][0])%mod;
		}
		return ret;
	}
	int count(int lim)
	{
		if(lim<0)return 0;
		int ret=0;
		for(int i=29;i>=0;i--)
		{
			if(p[i]>=1)
			{
				if(((x[i]^1)< lim/po[i])&&p[i])
				ret+=1ll*dp[i][(x[i]&1)^1]%mod,ret%=mod;
				if(((x[i]^1)==lim/po[i])&&p[i])
				ret+=1ll*dp[i][(x[i]&1)^1]*inv[i]%mod*(lim%po[i]+1)%mod,ret%=mod;
			}
			if(p[i]>=2)
			{
				if(((x[i])< lim/po[i])&&p[i])
				ret+=1ll*(dp[i][(x[i]&1)]-cnt[i])%mod,ret%=mod;
				if(((x[i])==lim/po[i])&&p[i])
				ret+=1ll*(dp[i][(x[i]&1)]-cnt[i])*inv[i]%mod*(lim%po[i]+1)%mod,ret%=mod;
			}
		}
		return ret+(val<=lim);
	}
	void reset()
	{
		for(int i=29;i>=0;i--)
		{	
			cnt[i]=dp[i][(val>>i)&1]=(val&((1<<i)-1))+1;
			x[i]=(x[i+1]<<1)|((val>>i)&1);
			p[i]=((val>>i)&1);
			if((val>>i)&1)
			dp[i][0]=1<<i;
			else
			dp[i][1]=0;
		}
	}
};
struct segemet_tree{
	node a[N<<2];
	void build(int l,int r,int rt)
	{
		if(l==r)
		{
			read(a[rt].val),val[l]=a[rt].val;
			a[rt].reset();
			return;
		}
		int mid=(l+r)/2;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		a[rt]=a[rt<<1]+a[rt<<1|1];
	}
	void updata(int l,int r,int rt,int x)
	{
		if(l==r)
		{
			a[rt].val=val[x];
			a[rt].reset();
			return;
		}
		int mid=(l+r)/2;
		if(x<=mid)
		updata(l,mid,rt<<1,x);
		else
		updata(mid+1,r,rt<<1|1,x);
		a[rt]=a[rt<<1]+a[rt<<1|1];
	}
	node quert(int l,int r,int rt,int x,int y)
	{
		if(x<=l&&y>=r)
		return a[rt];
		int mid=(l+r)/2;
		node ret;
		if(x<=mid)
		ret=quert(l,mid,rt<<1,x,y);
		if(y>mid)
		{
			if(x<=mid)
			ret=ret+quert(mid+1,r,rt<<1|1,x,y);
			else
			ret=quert(mid+1,r,rt<<1|1,x,y);
		}
		return ret;
	}
	
}T;
signed main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	T.build(1,n,1);
	for(i=1;i<=30;i++)
	po[i]=po[i-1]*2%mod,inv[i]=quick(po[i]);
	
	for(i=1;i<=m;i++)
	{
		int op,L,R,x,y;
		read(op);
		if(op==1)
		{
			read(x),read(val[x]);
			T.updata(1,n,1,x);
		}
		else
		{
			read(x),read(y),read(L),read(R);
			node ans=T.quert(1,n,1,x,y);
			int sum=0;
			printf("%lld\n",(ans.count(R)-ans.count(L-1)+mod*2)%mod);
		}
	}
	return 0;
}
