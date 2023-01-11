#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<bitset>
#define y1 y3647
#define next nxt
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
const int mod=20100501,N=2e6+10,M=2e5+10;
int i,j,k,n,s,t,m,js;
int zs[M*2];
bitset<N> pd;
struct query{
	int op,x,rk;
}q[601];
int ans[201],p[N],cnt[201];
bool cmp(query aa,query bb)
{
	return aa.x<bb.x;
}
void init(int now=1)
{
	for(i=2;i<N;i++)
	{
		if(!pd[i])zs[++js]=i;
		for(j=1;j<=js&&zs[j]*i<N;j++)
		{
			pd[i*zs[j]]=1;
			if(i%zs[j]==0)break;
		}
	}	
}
void add_query(int x,int y,int f)
{
	++s,q[s].x=x  ,q[s].rk=i+f*t,q[s].op= 1;
	++s,q[s].x=y  ,q[s].rk=i+f*t,q[s].op=-1;
	++s,q[s].x=x-y,q[s].rk=i+f*t,q[s].op=-1;
}
void solve()
{
	sort(q+1,q+s+1,cmp);
	p[0]=1;
	for(i=1;i<=js;i++)
	{
		memset(cnt,0,sizeof(cnt));
		int sum=0,now=1;
		for(j=1;j*zs[i]<N;j++)
		{
			int x=zs[i]*j;
			while(q[now].x<zs[i]*j&&now<=s)
			cnt[q[now].rk]+=sum*q[now].op,now++;
			while(x%zs[i]==0)
			sum++,x/=zs[i];
		}
		for(j=1;j<=sum;j++)
		p[j]=1ll*p[j-1]*zs[i]%mod;
		while(q[now].x<zs[i]*j&&now<=s)
		cnt[q[now].rk]+=sum*q[now].op,now++;
		for(j=1;j<=2*t;j++)
		ans[j]=1ll*ans[j]*p[cnt[j]]%mod;
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	init();
	read(t);
	for(i=1;i<=t;i++)
	{
		read(n),read(m);
		ans[i+t]=ans[i]=1;
		if(m>n)	continue;
		add_query(n+m,n  ,0);
		add_query(n+m,n+1,1);
	}
	solve();
	for(i=1;i<=t;i++)
	printf("%d\n",(ans[i]-ans[i+t]+mod)%mod);
	return 0;
}
