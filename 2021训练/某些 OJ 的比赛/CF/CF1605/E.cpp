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
const int N=1e6+10;
int i,j,k,n,s,t,m,base;
struct query{
	int x,rk;
	friend bool operator <(query a,query b){return a.x<b.x;}
};
int a[N],b[N],c[N],ans[N],mu[N];
query q[N];
void init()
{
	mu[1]=-1;
	for(i=1;i<N;i++)
	{
		mu[i]=-mu[i];
		for(j=2*i;j<N;j+=i)
		mu[j]+=mu[i];
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//freopen(".ans","w",sdtout);
	int tot=1;init();
	while(tot--)
	{
		read(n);
		for(i=1;i<=n;i++)read(a[i]);
		for(i=1;i<=n;i++)read(b[i]);
		read(m);for(i=1;i<=m;i++)read(q[i].x),q[i].rk=i;
		sort(q+1,q+m+1);b[1]=q[1].x;
		int cnt1=0,cnt0=0,sum0=0,sum1=0,now=1;
		for(i=1;i<=n;i++)
		{
			int need=b[i]-a[i];
			if(mu[i])c[++s]=-need*mu[i],sum0+=c[s],cnt0++;
			else base+=abs(need);
			for(j=i;j<=n;j+=i)
			a[j]+=need;
		}
		sort(c+1,c+s+1);
		for(i=1;i<=m;i++)
		{
			while(c[now]<=q[i].x-b[1]&&now<=s)
			{
				sum0-=c[now],cnt0--;
				cnt1++,sum1+=c[now++];
			}
			int x=q[i].x-b[1];
			ans[q[i].rk]=x*cnt1-sum1+sum0-cnt0*x;
		}
		for(i=1;i<=m;i++)
		printf("%lld\n",ans[i]+base);
	}
	return 0;
}

