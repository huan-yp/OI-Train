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
const int N=2e5+10,mod=1e9+7,M=2e5+10;
struct zy{
	int a[10];
	friend zy operator *(const zy &a,const zy &b)
	{
		zy ret;
		memset(ret.a,0,sizeof(ret.a));
		for(int j=1;j<=6;j++)
		for(int k=1;k<=6;k++)
		for(int s=1;s<=6;s++)
		{
			if(j%3==k%3||j%3==s%3)continue;
			ret.a[j]+=1ll*a.a[k]*b.a[s]%mod;
			ret.a[j]%=mod;
		}
		return ret;
	}
};
int i,j,k,n,s,t=1,m;
int col[N];
zy dp[N];
struct node{
	zy val;
	int ls,rs,len;
}a[M*4];
void push_up(int rt)
{
	zy lsv=dp[a[rt].len-1],rsv=dp[a[rt].len-1];
	if(a[rt].ls)lsv=a[a[rt].ls].val;
	if(a[rt].rs)rsv=a[a[rt].rs].val;
	a[rt].val=lsv*rsv;
	if(col[rt])
	{
		for(int i=1;i<=6;i++)
		if(col[rt]!=i)a[rt].val.a[i]=0;
	}
}
void updata(int l,int rk,int rt,int x,int c,int dep,int len)
{
	a[rk].len=len;
	if(x==rt)
	{
		col[rk]=c;
		for(int i=1;i<=6;i++)
		if(i!=c)a[rk].val.a[i]=0;
		return ;
	}
	if(x&(1ll<<dep-2))
	{
		if(a[rk].rs==0)a[rk].rs=++t,a[t].val=dp[len-1];
		updata(l,a[rk].rs,rt<<1|1,x,c,dep-1,len-1);
	}
	else
	{
		if(a[rk].ls==0)a[rk].ls=++t,a[t].val=dp[len-1];
		updata(l,a[rk].ls,rt<<1,x,c,dep-1,len-1);
	}
	push_up(rk);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	read(n),read(m);
	for(i=1;i<=6;i++)
	dp[1].a[i]=1;
	for(i=2;i<=n;i++)
	dp[i]=dp[i-1]*dp[i-1];
	a[1].val=dp[n];
	for(i=1;i<=m;i++)
	{
		int x,val,cnt=0;char ch[100];
		read(x);scanf("%s",ch+1);
		int nx=x;
		while(nx)
		{
			nx/=2;
			cnt++;
		}
		if(ch[1]=='w')val=1;
		if(ch[1]=='g')val=2;
		if(ch[1]=='r')val=3;
		if(ch[1]=='y')val=4;
		if(ch[1]=='b')val=5;
		if(ch[1]=='o')val=6;
		updata(0,1,1,x,val,cnt,n);
	}
	int ans=0;
	for(i=1;i<=6;i++)
	ans+=a[1].val.a[i],ans%=mod;
	cout<<ans<<endl;
	return 0;
}

