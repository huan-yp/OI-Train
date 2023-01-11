#include<bits/stdc++.h>
#define int long long
#define LL long long
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
const int N=2e5+10;
int i,j,k,m,n,s,t,d,a,tag;
int pos[N],val[N],gap[N],dp[N];
struct tree{
	LL a[N*32],lazy[N*32];
	signed ls[N*32],rs[N*32];
	tree()
	{
		a[0]=-1e18;
	}
	void push_up(int rt)
	{
		a[rt]=max(a[ls[rt]],a[rs[rt]]);
	}
	void push_down(int rt)
	{
		if(lazy[rt]==0)return ;
		a[ls[rt]]+=lazy[rt],a[rs[rt]]+=lazy[rt];
		lazy[ls[rt]]+=lazy[rt],lazy[rs[rt]]+=lazy[rt];
		lazy[rt]=0;
	}
	void updata(int l,int r,int rt,int x,int y,LL c,int op=1)
	{
		if(x<=l&&y>=r)
		{
			if(op==2)
			a[rt]=max(c,a[rt]);
			else
			a[rt]+=c;lazy[rt]+=c;
			return ;
		}
		int mid=(l+r)/2;push_down(rt);
		if(x<=mid)
		{
			if(ls[rt]==0)ls[rt]=++t,a[t]=-1e18;
			updata(l,mid,ls[rt],x,y,c,op);
		}
		if(y>mid)
		{
			if(rs[rt]==0)rs[rt]=++t,a[t]=-1e18;
			updata(mid+1,r,rs[rt],x,y,c,op);
		}
		push_up(rt);
	}
	LL quert(int l,int r,int rt,int x,int y)
	{
		if(rt==0)return -1e18;
		if(x<=l&&y>=r)return a[rt];
		push_down(rt);int mid=(l+r)/2;LL ret=-1e18;
		if(x<=mid)cmax(ret,quert(l,mid,ls[rt],x,y));
		if(y>mid)cmax(ret,quert(mid+1,r,rs[rt],x,y));
		return ret;
	}
}T;
signed main()
{
	read(k),read(m),read(d),read(a),read(n);
	for(i=1;i<=n;i++)
	read(pos[i]),read(val[i]);
	T.updata(0,d-1,t=1,0,0,0,2);
	gap[1]=pos[1]-k,gap[n+1]=m-pos[n];
	for(i=2;i<=n;i++)gap[i]=pos[i]-pos[i-1];

	for(i=1;i<=n+1;i++)
	{
		T.updata(0,d-1,1,0,d-1,1ll*-gap[i]/d*a);
		int inc=gap[i]%d;
		if(inc)
		{
			int x=((d-inc+1-tag)%d+d)%d;
			int y=((d-tag)%d+d)%d;
			if(x>y)
			{
				T.updata(0,d-1,1,x,d-1,-a);
				T.updata(0,d-1,1,0,y,-a);
			}
			else 
			T.updata(0,d-1,1,x,y,-a);
		}
		//d-inc+1-tag,d-tag
		tag+=gap[i]%d;if(tag>=d)tag-=d;
		dp[i]=T.quert(0,d-1,1,0,d-1)+val[i];
		T.updata(0,d-1,1,(d-tag)%d,(d-tag)%d,dp[i],2);
	}
	cout<<dp[n+1]<<endl;
	return 0;
}

